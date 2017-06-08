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

    Warrior::Warrior() : Profession("Warrior") {
      php = 3;
      pstr = 3;
    }

    Wizard::Wizard() : Profession("Wizard") { 
      php = 3;
      pstr = 3;
    }