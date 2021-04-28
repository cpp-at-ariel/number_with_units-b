#pragma once
#include <iostream>
#include <fstream>
#include <map>

using std::string;
using std::map;
using std::pair;
using std::ifstream;
using std::ostream;
using std::istream;




namespace ariel {
    static map <string, map <string, double>> unitsType;
    const static double epsilon = 0.00001;

    class NumberWithUnits {
        private:
            pair <double, string> _unit;


        public:
            NumberWithUnits(double val, const string &type);
            static void read_units(ifstream &units_file) ;
             // + - 
            NumberWithUnits operator+ () const; 
            NumberWithUnits operator- () const;
            //prefix and postfix 
            NumberWithUnits & operator++ ();
            NumberWithUnits operator++ (int);
            NumberWithUnits & operator-- ();
            NumberWithUnits operator-- (int);
            //
            NumberWithUnits& operator+= (const NumberWithUnits &num);
            NumberWithUnits& operator-= (const NumberWithUnits &num);
            //unary
            NumberWithUnits operator+ (const NumberWithUnits &other_num)const;
            NumberWithUnits operator- (const NumberWithUnits &other_num)const ;
            // *
            NumberWithUnits operator* (double factor) const;
            friend NumberWithUnits operator* (double factor, const NumberWithUnits &num);
            // < > = 
            bool operator> (const NumberWithUnits &other_num) const;
            bool operator< (const NumberWithUnits &other_num) const;
            bool operator== (const NumberWithUnits &other_num) const;
            bool operator<= (const NumberWithUnits &other_num) const;
            bool operator>= (const NumberWithUnits &other_num) const;
            bool operator!= (const  NumberWithUnits &other_num) const;
            // << >> 
            friend ostream& operator<< (ostream& stream, const NumberWithUnits& num);
            friend istream& operator>> (istream& stream, NumberWithUnits& num);
	};
}