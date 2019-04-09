#include <iostream>
#include "Unit.h"
using namespace std;
namespace ariel{
class PhysicalNumber
{
    private:
    double data;
    Unit unit;

   static int type(const Unit u1, const Unit u2);
   static double convert(const PhysicalNumber p_n, const Unit unit);
 //  static istream& getAndCheckNextCharIs(istream& input, char expectedChar);

  

    public:
        

    PhysicalNumber(double data, Unit unit);
    PhysicalNumber operator+(const PhysicalNumber p_n)  ;
    PhysicalNumber& operator+=(const PhysicalNumber p_n);

    PhysicalNumber operator-(const PhysicalNumber p_n) ;
    PhysicalNumber& operator-=(const PhysicalNumber p_n) ;

    const PhysicalNumber operator+() ;
    const PhysicalNumber operator-() ;


    PhysicalNumber& operator++();
    PhysicalNumber& operator--();

     PhysicalNumber operator++(int demo);
    PhysicalNumber operator--(int demo);

    friend bool operator==(const PhysicalNumber p_n1, const PhysicalNumber p_n2);
    friend bool operator!=(const PhysicalNumber p_n1, const PhysicalNumber p_n2);
    friend bool operator<(const PhysicalNumber p_n1, const PhysicalNumber p_n2);
    friend bool operator>(const PhysicalNumber p_n1, const PhysicalNumber p_n2);
    friend bool operator<=(const PhysicalNumber p_n1, const PhysicalNumber p_n2);
    friend bool operator>=(const PhysicalNumber p_n1, const PhysicalNumber p_n2);

    friend ostream& operator<<(ostream& st, const PhysicalNumber& p_n);
    friend istream& operator>>(istream& st,  PhysicalNumber& p_n);

};
 
}