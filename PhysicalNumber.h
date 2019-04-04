namespace ariel{
#include <iostream>
#include "Unit.h"
using namespace std;
class PhysicalNumber
{
    private:
    double data;
    Unit unit;
    bool sametype(Unit u1, Unit u2);

    public:
PhysicalNumber(double data, Unit unit);
//~PhysicalNumber();

    PhysicalNumber operator+(const PhysicalNumber& p_n) const;
    PhysicalNumber& operator+=(const PhysicalNumber& p_n);

    PhysicalNumber operator-(const PhysicalNumber& p_n) const;
    PhysicalNumber& operator-=(const PhysicalNumber& p_n) ;

    const PhysicalNumber operator+() ;
    const PhysicalNumber operator-() ;


    PhysicalNumber& operator++();
    PhysicalNumber& operator--();

    bool operator==(const PhysicalNumber& p_n1) const;
    bool operator!=(const PhysicalNumber& p_n) const;
    friend bool operator<(const PhysicalNumber& p_n1, const PhysicalNumber p_n2);
    friend bool operator>(const PhysicalNumber& p_n1, const PhysicalNumber p_n2);
    friend bool operator<=(const PhysicalNumber& p_n1, const PhysicalNumber p_n2);
    friend bool operator>=(const PhysicalNumber& p_n1, const PhysicalNumber p_n2);

    friend ostream& operator<<(ostream& st, const PhysicalNumber& p_n);
    friend istream& operator>>(istream& st,  PhysicalNumber& p_n);

};
}