#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#ifndef PROFESSION_HPP
#define PROFESSION_HPP
class Profession
{
  public:
    float php = 0;
    float pstr = 0;
    std::string id;
    Profession(std::string identifier);
    std::string toString();
};  

class Warrior : public Profession
{

  public:
    Warrior();
};

class Wizard : public Profession
{
  public:
    Wizard ();
};

#endif