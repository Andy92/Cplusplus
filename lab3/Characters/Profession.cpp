#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Profession.hpp"

    Profession::Profession(std::string identifier) {
      this->id = identifier;
    }
    std::string Profession::toString() {
      return this->id;
    }  


    Warrior::Warrior(std::string identifier) : Profession(identifier) {
      php = 3;
      pstr = 3;
    }

    Wizard::Wizard(std::string identifier) : Profession(identifier) { 
      php = 3;
      pstr = 3;
    }