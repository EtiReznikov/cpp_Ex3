#include <iostream>
#include "PhysicalNumber.h"
using namespace std;


ariel::PhysicalNumber:: PhysicalNumber(double data, Unit unit)
{
this->data=data;
this->unit=unit;
}

 bool ariel::PhysicalNumber::sametype(Unit unit1, Unit unit2)
 {
return false;
 }


ariel::PhysicalNumber::PhysicalNumber ariel::PhysicalNumber::operator+(const PhysicalNumber& p_n) const
{
return PhysicalNumber(this->data+p_n.data, this->unit);
}

ariel::PhysicalNumber::PhysicalNumber& ariel::PhysicalNumber::operator+=(const PhysicalNumber& p_n)
{

    this->data=this->data+p_n.data;
    return *this;
}


ariel::PhysicalNumber::PhysicalNumber ariel::PhysicalNumber::operator-(const PhysicalNumber& p_n) const
{
return PhysicalNumber(this->data-p_n.data, this->unit);
}
ariel::PhysicalNumber::PhysicalNumber& ariel::PhysicalNumber::operator-=(const PhysicalNumber& p_n) 
{
    this->data=this->data-p_n.data;
    return *this;
}

 const ariel::PhysicalNumber::PhysicalNumber ariel::PhysicalNumber::operator+() 
 {
return *this;
 }
 const ariel::PhysicalNumber::PhysicalNumber ariel::PhysicalNumber::operator-() 
{
    this->data=-this->data;
    return *this;
}

ariel::PhysicalNumber::PhysicalNumber& ariel::PhysicalNumber::operator++()
{
this->data=this->data+1;
return *this;
}
ariel::PhysicalNumber:: PhysicalNumber& ariel::PhysicalNumber::operator--()
{
this->data=this->data-1;
return *this;

bool ariel::PhysicalNumber::operator==(const PhysicalNumber& p_n1, const PhysicalNumber p_n2) 
{
    return true;
}
bool ariel::PhysicalNumber::operator!=(const PhysicalNumber& p_n1, const PhysicalNumber p_n2)
{
    return true;
}
bool ariel::PhysicalNumber::operator<(const PhysicalNumber& p_n1, const PhysicalNumber p_n2){
    return true;
}
bool ariel::PhysicalNumber::operator>(const PhysicalNumber& p_n1, const PhysicalNumber p_n2)
{
    return true;
}
bool ariel::PhysicalNumber::operator<=(const PhysicalNumber& p_n1, const PhysicalNumber p_n2)
{
    return true;
}
 bool ariel::PhysicalNumber::operator>=(const PhysicalNumber& p_n1, const PhysicalNumber p_n2)
 {
     return true;
 }


 ostream& ariel::PhysicalNumber::operator<<(ostream& st, const PhysicalNumber& p_n)
 {
p_n.print(os);
return os;
 }
 istream& ariel::PhysicalNumber::operator>>(istream& st,  PhysicalNumber& p_n)
 {
p_n.read(is); 
return is;
 }
}