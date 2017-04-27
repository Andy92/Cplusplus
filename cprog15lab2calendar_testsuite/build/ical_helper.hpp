#ifndef CPROG_ICAL_HELPER_HPP
#define CPROG_ICAL_HELPER_HPP

#include <ostream>
#include <istream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>

namespace ical {
  class Entity {
    public:
      typedef std::map<std::string, std::string> properties_type;
      typedef std::vector<Entity>                children_type;

    public:
      Entity () = default;
      Entity (Entity const&) = default;
      Entity (std::string const& type);

      Entity& operator= (Entity const&) = default;
      Entity& operator= (Entity&&)      = default;

      Entity& create_child (std::string const& type);
      void set_property (std::string const& key, std::string const& value);

      std::string        base_type () const;
      std::string const&      type () const;

      children_type   const&   children () const;
      properties_type const& properties () const;

      std::string   property (std::string const&) const;
      children_type children (std::string const&) const;

      std::vector<Entity> events () const;

    protected:
      std::string      _type;
      children_type    _children;
      properties_type  _properties;
  };


  Entity parse (std::istream&);

  bool operator< (Entity const&, Entity const&);
  void print (std::ostream&, Entity const& data, unsigned level = 0);
}

#endif /* include-guard */
