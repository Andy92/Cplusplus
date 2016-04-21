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
            bool isLeap(int y) const;
            void validDate(int y, int m, int d) const;
       public:
        virtual Gregorian& operator++();
        virtual Gregorian& operator--();
        Gregorian operator++(int);
        Gregorian operator--(int);
        std::string week_day_name() const;
        unsigned int week_day() const;
        //Gregorian& operator=(const Gregorian &src);
        explicit Gregorian();
        virtual ~Gregorian();
        Gregorian& operator=(const Gregorian &src);
        Gregorian(Date const& src);
        Gregorian(int Y, int M, int D);
        int year() const;
        unsigned int month() const;
        unsigned int day() const;
        
    };
}
#endif
