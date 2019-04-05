#include <iostream>
#include "PhysicalNumber.h"
using namespace std;


ariel::PhysicalNumber:: PhysicalNumber(double data, Unit unit)
{
this->data=data;
this->unit=unit;
}

 

ariel::PhysicalNumber ariel::PhysicalNumber::operator+(const PhysicalNumber& p_n1) 
{
   
if (type(this->unit, p_n1.unit)==-1)
{
    throw "Units not frim the same type";
}
double data=convert(p_n1, this->unit);
return PhysicalNumber(this->data+data, this->unit);
}

ariel::PhysicalNumber ariel::PhysicalNumber::operator+=(const PhysicalNumber& p_n)
{

    this->data=this->data+p_n.data;
    return *this;
}


ariel::PhysicalNumber ariel::PhysicalNumber::operator-(const PhysicalNumber& p_n1) 
{
       
if (type(this->unit, p_n1.unit)==-1)
{
    throw "Units not frim the same type";
}
double data=convert(p_n1, this->unit);
return PhysicalNumber(this->data+data, this->unit);
}


ariel::PhysicalNumber ariel::PhysicalNumber::operator-=(const PhysicalNumber& p_n) 
{
    this->data=this->data-p_n.data;
    return *this;
}

 const ariel::PhysicalNumber ariel::PhysicalNumber::operator+() 
 {
return *this;
 }
 const ariel::PhysicalNumber ariel::PhysicalNumber::operator-() 
{
    this->data=-this->data;
    return *this;
}

ariel::PhysicalNumber ariel::PhysicalNumber::operator++()
{
this->data=this->data+1;
return *this;
}
ariel:: PhysicalNumber ariel::PhysicalNumber::operator--()
{
this->data=this->data-1;
return *this;
}

bool ariel::operator==(const PhysicalNumber& p_n1, const PhysicalNumber p_n2)
{
return true;
}

bool ariel::operator!=(const PhysicalNumber& p_n1, const PhysicalNumber p_n2)
{
    return true;
}
bool ariel::operator<(const PhysicalNumber& p_n1, const PhysicalNumber p_n2){
    return true;
}
bool ariel::operator>(const PhysicalNumber& p_n1, const PhysicalNumber p_n2)
{
    return true;
}
bool ariel::operator<=(const PhysicalNumber& p_n1, const PhysicalNumber p_n2)
{
    return true;
}
 bool ariel::operator>=(const PhysicalNumber& p_n1, const PhysicalNumber p_n2)
 {
     return true;
 }

 ostream& ariel::operator<<(ostream& os, const PhysicalNumber& p_n)
 {
  //os << p_n.data << p_n.unit << '\n';
    return os;
 }
 istream& ariel::operator>>(istream& st,  PhysicalNumber& p_n)
 {
//p_n.read(st); 
return st;
 }

int ariel::PhysicalNumber::type(Unit unit1, Unit unit2)
 {
if ((Unit::CM<= unit1 && unit1<=Unit::KM) && (Unit::CM<= unit2 && unit2<=Unit::KM))
    return 1;
if ((Unit::SEC<= unit1 && unit1<=Unit::HOUR) && (Unit::SEC<= unit2 && unit2<=Unit::HOUR))
    return 2;
if ((Unit::G<= unit1 && unit1<=Unit::TON) && (Unit::G<= unit2 && unit2<=Unit::TON))
    return 3;
return -1;
 }

 double ariel::PhysicalNumber:: convert(const PhysicalNumber& p_n, Unit unit)
 {
    if (p_n.unit==unit)
    return p_n.data;
    int typeofunit=type(p_n.unit, unit);
    if (typeofunit==1)
    {
      if (unit==Unit::KM)
      {
        if (p_n.unit==Unit::CM)
          return p_n.data/100000;
        else if (p_n.unit==Unit::M)
          return p_n.data/1000;
       }
       else if (this->unit==Unit::CM)
       {
        if (p_n.unit==Unit::KM)
          return p_n.data*100000;
        else if (p_n.unit==Unit::M)
          return p_n.data*100;
       }
       else if (this->unit==Unit::M)
       {
        if (p_n.unit==Unit::CM)
          return p_n.data/100;
        else if (p_n.unit==Unit::KM)
          return p_n.data*1000;
       }
    }
    else if (typeofunit==2)
    {
        if (unit==Unit::HOUR)
      {
        if (p_n.unit==Unit::SEC)
          return p_n.data/3600;
        else if (p_n.unit==Unit::MIN)
          return p_n.data/60;
       }
       else if (this->unit==Unit::SEC)
       {
        if (p_n.unit==Unit::HOUR)
          return p_n.data*3600;
        else if (p_n.unit==Unit::MIN)
          return p_n.data*60;
       }
       else if (this->unit==Unit::MIN)
       {
        if (p_n.unit==Unit::HOUR)
          return p_n.data*60;
        else if (p_n.unit==Unit::SEC)
          return p_n.data/60;
       }
    }
     else if (typeofunit==3)
    {
        if (unit==Unit::TON)
      {
        if (p_n.unit==Unit::KG)
          return p_n.data/1000;
        else if (p_n.unit==Unit::G)
          return p_n.data/1000000;
       }
       else if (this->unit==Unit::KG)
       {
        if (p_n.unit==Unit::TON)
          return p_n.data*1000;
        else if (p_n.unit==Unit::G)
          return p_n.data/1000;
       }
       else if (this->unit==Unit::G)
       {
        if (p_n.unit==Unit::TON)
          return p_n.data*1000000;
        else if (p_n.unit==Unit::KG)
          return p_n.data*1000;
       }
    }

return p_n.data;
    
 }
