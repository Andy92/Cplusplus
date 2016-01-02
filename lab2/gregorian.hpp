#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>
#include "date.hpp"
#ifndef GREGORIAN_HPP
#define GREGORIAN_HPP

namespace lab2 {
    class Gregorian : public Date {
        private:
            int convertToJDN(int J, int check) const;
            int mod(int a, int b) const;
            int div(int a, int b) const;
            bool isLeap(int y);
       public:
        std::string week_day_name() const;
        unsigned int week_day() const;
        Gregorian operator++(int a);
        Gregorian operator--(int a);
        //Gregorian& operator=(const Gregorian &src);
        explicit Gregorian();
        Gregorian& operator=(const Gregorian &src);
        Gregorian(Gregorian const& src);
        Gregorian(int Y, int M, int D);
        
        virtual Gregorian& operator++();
        virtual Gregorian& operator--();
        int year() const;
        unsigned int month() const;
        unsigned int day() const;
        friend std::ostream& operator<<(std::ostream&, Date const&);
    };
}
#endif