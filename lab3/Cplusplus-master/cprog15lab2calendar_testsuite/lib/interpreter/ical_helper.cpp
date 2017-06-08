#include "ical_helper.hpp"

#include <string>
#include <stack>
#include <stdexcept>
#include <sstream>
#include <functional>
#include <algorithm>

ical::Entity::Entity (std::string const& type)
  : _type (type)
{ }

ical::Entity&
ical::Entity::create_child (std::string const& type)
{
  Entity e (type);

  return *_children.insert (
    std::lower_bound (_children.begin (), _children.end (), e), e
  );
}

void
ical::Entity::set_property (std::string const& key, std::string const& value)
{
  std::string base_key = key.substr (0, key.find (';'));

  if (_properties.find (base_key) != _properties.end ())
    throw std::domain_error ("duplicate property found");

  _properties[base_key] = value;
}

std::string const&
ical::Entity::type () const 
{
  return _type;
}

std::string
ical::Entity::base_type () const 
{
  return _type.substr (0, _type.find (';'));
}

ical::Entity::children_type const&
ical::Entity::children () const
{
  return _children;
}

ical::Entity::children_type
ical::Entity::children (std::string const& key) const
{
  return {
    std::lower_bound (_children.begin (), _children.end (), key),
    std::upper_bound (_children.begin (), _children.end (), key)
  };
}


ical::Entity::properties_type const&
ical::Entity::properties () const
{
  return _properties;
}

std::string
ical::Entity::property (std::string const& key) const
{
  auto it = _properties.find (key);

  if (it != _properties.end ())
    return it->second;

  return {};
}

bool
ical::operator< (Entity const& lhs, Entity const& rhs)
{
  return lhs.base_type () < rhs.base_type ();
}

ical::Entity
ical::parse (std::istream& input_stream) 
{
  Entity global;
  std::stack<Entity*> entity_stack ({ &global });

  std::string line;
  std::string key, value;

  while (std::getline (input_stream, line)) {

    if (line.size () && line.back () == '\r')
      line.pop_back ();

    if (line.size () == 0)
      continue;

    {
      std::istringstream iss (line);

      if (!std::getline (iss, key, ':') || !std::getline (iss, value))
        throw std::domain_error ("invalid ical-data");

      while (input_stream && input_stream.peek () == ' ') {

        if (std::getline (input_stream, line)) {
          if (line.size () && line.back () == '\r')
            line.pop_back ();

          if (line.size ())
            value += line.substr (1); // ignore space
        }
      }
    }

    if (key == "BEGIN") {
      entity_stack.push (
        std::addressof (entity_stack.top ()->create_child (value))
      );

    } else if (key == "END") {
      if (value != entity_stack.top ()->type ()) 
        throw std::domain_error ("invalid ical-data");

      entity_stack.pop ();

    } else {
      entity_stack.top ()->set_property (key, value);
    }
  }

  return global;
}

void
ical::print (std::ostream& output_stream, ical::Entity const& data, unsigned level)
{
  auto out = [&] () -> std::ostream& {
    return output_stream << std::string (level * 2, ' ');
  };

  out () << "TYPE: " << data.type () << "\n";

  for (auto const& property : data.properties ()) {
    out () << "  prop." << property.first << " = " << property.second << "\n";
  }

  for (auto const& node : data.children ()) {
    ical::print (output_stream, node, level + 1);
  }
}
