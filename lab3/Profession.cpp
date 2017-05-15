#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>


class Profession
{
  public:
    float php = 0;
    float pstr = 0;
    string id;
    Profession(string identifier) {
      this->id = identifier;
    }
    string toString() {
      return this->id;
    }   
};  

class Warrior : public Profession
{

  public:
    Warrior() : Profession("Warrior") {
      php = 3;
      pstr = 3;
    }
};

class Wizard : public Profession
{
  public:
    Wizard () : Profession("Wizard") { 
      php = 3;
      pstr = 3;
    }
};