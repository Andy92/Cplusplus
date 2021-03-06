#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>
#include "date.hpp"     
#ifndef JULIAN_HPP
#define JULIAN_HPP

namespace lab2 {
        class Julian : public Date {
        private:
                bool isLeap(int y) const;
                void validDate(int Y, int M, int D) const;
        public:
                virtual Julian& operator++();
                virtual Julian& operator--();
                explicit Julian();
                virtual ~Julian();
                std::string week_day_name() const;
                unsigned int week_day() const;
                unsigned int day() const;
                int year() const;
                unsigned int month() const;
                Julian& operator=(const Julian &src);
                int convertToJDN(int J, int check) const;
                int mod(int a, int b) const;
                int div(int a, int b) const;
                Julian(int Y, int M, int D);
                Julian(Date const& src);
                Julian operator--(int);
                Julian operator++(int);
                };
}
#endif
