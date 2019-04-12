#include <iostream>
#include "PhysicalNumber.h"
#include "string"
using namespace std;


ariel::PhysicalNumber:: PhysicalNumber(double data, Unit unit)
{
this->data=data;
this->unit=unit;
}


ariel::PhysicalNumber ariel::PhysicalNumber::operator+(const PhysicalNumber p_n1) 
{
   
if (type(this->unit, p_n1.unit)==-1)
{
    throw "Units not from the same type";
}
double data=convert(p_n1, this->unit);
return PhysicalNumber(this->data+data, this->unit);
}

ariel::PhysicalNumber& ariel::PhysicalNumber::operator+=(const PhysicalNumber p_n)
{
    if (type(this->unit, p_n.unit)==-1)
    {
        throw "Units not from the same type";
    }
    double data=convert(p_n, this->unit);
    this->data=this->data+data;
    return *this;
}


ariel::PhysicalNumber ariel::PhysicalNumber::operator-(const PhysicalNumber p_n1) 
{
       
if (type(this->unit, p_n1.unit)==-1)
{
    throw "Units not from the same type";
}
double data=convert(p_n1, this->unit);
return PhysicalNumber(this->data-data, this->unit);
}


ariel::PhysicalNumber& ariel::PhysicalNumber::operator-=(const PhysicalNumber p_n) 
{
     if (type(this->unit, p_n.unit)==-1)
    {
        throw "Units not from the same type";
    }
    double data=convert(p_n, this->unit);
    this->data=this->data-data;
    return *this;
}

 const ariel::PhysicalNumber ariel::PhysicalNumber::operator+() 
 {
    return PhysicalNumber(this->data, this->unit);
 }
 const ariel::PhysicalNumber ariel::PhysicalNumber::operator-() 
{
  return  PhysicalNumber(-(this->data), this->unit);
}

ariel::PhysicalNumber& ariel::PhysicalNumber::operator++()
{
this->data=this->data+1;
return *this;
}
ariel::PhysicalNumber& ariel::PhysicalNumber::operator--()
{
this->data=this->data-1;
return *this;
}

ariel::PhysicalNumber ariel::PhysicalNumber::operator++(int demo)
{
  PhysicalNumber temp(*this);
  this->data=this->data+1;
  return temp;

}
ariel::PhysicalNumber ariel::PhysicalNumber::operator--(int demo)
{
    PhysicalNumber temp(*this);
  this->data=this->data-1;
  return temp;


}

bool ariel::operator==(const PhysicalNumber p_n1, const PhysicalNumber p_n2)
{

 if (ariel::PhysicalNumber::type(p_n1.unit, p_n2.unit)==-1)
    {
        throw "Units not from the same type";
    }
    double data=ariel::PhysicalNumber::convert(p_n2, p_n1.unit);
    if (p_n1.data==data)
       return true;
    return false;
    
}

bool ariel::operator!=(const PhysicalNumber p_n1, const PhysicalNumber p_n2)
{
 
 if (ariel::PhysicalNumber::type(p_n1.unit, p_n2.unit)==-1)
    {
        throw "Units not from the same type";
    }
    double data=ariel::PhysicalNumber::convert(p_n2, p_n1.unit);
    if (p_n1.data!=data)
       return true;
    return false;
}
bool ariel::operator<(const PhysicalNumber p_n1, const PhysicalNumber p_n2){
    
 if (ariel::PhysicalNumber::type(p_n1.unit, p_n2.unit)==-1)
    {
        throw "Units not from the same type";
    }
    double data=ariel::PhysicalNumber::convert(p_n2, p_n1.unit);
    if (p_n1.data<data)
       return true;
    return false;
}
bool ariel::operator>(const PhysicalNumber p_n1, const PhysicalNumber p_n2)
{
  
 if (ariel::PhysicalNumber::type(p_n1.unit, p_n2.unit)==-1)
    {
        throw "Units not from the same type";
    }
    double data=ariel::PhysicalNumber::convert(p_n2, p_n1.unit);
    if (p_n1.data>data)
       return true;
    return false;
}
bool ariel::operator<=(const PhysicalNumber p_n1, const PhysicalNumber p_n2)
{
 if (ariel::PhysicalNumber::type(p_n1.unit, p_n2.unit)==-1)
    {
        throw "Units not from the same type";
    }
    double data=ariel::PhysicalNumber::convert(p_n2, p_n1.unit);
    if (p_n1.data<=.data)
       return true;
    return false;
}
 bool ariel::operator>=(const PhysicalNumber p_n1, const PhysicalNumber p_n2)
 {
     
 if (ariel::PhysicalNumber::type(p_n1.unit, p_n2.unit)==-1)
    {
        throw "Units not from the same type";
    }
    double data=ariel::PhysicalNumber::convert(p_n2, p_n1.unit);
    if (p_n1.data>=data)
       return true;
    return false;
 }

 ostream& ariel::operator<<(ostream& os, const PhysicalNumber& p_n)
 {
    if (p_n.unit==Unit::CM)
  os << p_n.data << "[cm]";
    if (p_n.unit==Unit::M)
  os << p_n.data << "[m]";
    if (p_n.unit==Unit::KM)
  os << p_n.data << "[km]";
    if (p_n.unit==Unit::SEC)
  os << p_n.data << "[sec]";
    if (p_n.unit==Unit::MIN)
  os << p_n.data << "[min]";
    if (p_n.unit==Unit::HOUR)
  os << p_n.data << "[hour]";
    if (p_n.unit==Unit::G)
  os << p_n.data << "[g]";
    if (p_n.unit==Unit::KG)
  os << p_n.data << "[kg]";
    if (p_n.unit==Unit::TON)
  os << p_n.data << "[ton]";
    return os;
 }
 istream& ariel::operator>>(istream& st,  PhysicalNumber& p_n)
 {
  double newdata; Unit newunit; 
  string input;
  st >> input;
  string unit, data;
  int startunit=0; int endunit=0;
  bool vaildinput=true;
  startunit=input.find("[");
  endunit=input.find("]");
  if (startunit==-1 || endunit ==-1)
  {
    vaildinput=false;
  }
if (vaildinput)
{
  unit=input.substr(startunit, endunit);
  if (unit == "[cm]" ) 
     newunit= Unit::CM;
  else if (unit == "[m]" ) 
     newunit= Unit::M;
  else if (unit == "[km]" ) 
     newunit= Unit::KM;
  else if (unit == "[sec]" ) 
     newunit= Unit::SEC;
  else if (unit == "[min]" ) 
     newunit= Unit::MIN;
  else if (unit == "[hour]" ) 
     newunit= Unit::HOUR;
  else if (unit == "[g]" ) 
     newunit= Unit::G;
  else if (unit == "[kg]" ) 
     newunit= Unit::KG;
  else if (unit == "[ton]" ) 
     newunit= Unit::TON;
  else
    vaildinput=false;
  if (vaildinput)
  {
    data=input.substr(0, startunit-1);
    try
    {
      size_t offset = 0; //offset will be set to the length of characters of the "value" - 1.
      newdata= stod(&data[0], &offset); //So we want to get the value "5.9568
    }
    catch (exception &e)
    {
      vaildinput=false;
    }
            
  }
}
if (vaildinput)
{
  p_n.unit=newunit;
  p_n.data=newdata;
}
else
{
  auto errorState = st.rdstate(); // remember error state
  st.clear(); // clear error so seekg will work
 // st.seekg(startPosition); // rewind
  st.clear(errorState); // set back the error flag
}

  

 /* ios::pos_type startPosition = st.tellg();

    if ( (!(st >> newdata))                 ||
         (!getAndCheckNextCharIs(st,'[')) ||
         //(!(st >> newunit))                 ||
         (!(getAndCheckNextCharIs(st,']'))) ) {

        // rewind on error
        auto errorState = st.rdstate(); // remember error state
        st.clear(); // clear error so seekg will work
        st.seekg(startPosition); // rewind
        st.clear(errorState); // set back the error flag
    } else {
      */
      //  p_n.data = newdata;
      //  p_n.unit = newunit;
 //   }

    return st;
 }

int ariel::PhysicalNumber::type(const Unit unit1, const Unit unit2)
 {
if ((Unit::CM<= unit1 && unit1<=Unit::KM) && (Unit::CM<= unit2 && unit2<=Unit::KM))
    return 1;
if ((Unit::SEC<= unit1 && unit1<=Unit::HOUR) && (Unit::SEC<= unit2 && unit2<=Unit::HOUR))
    return 2;
if ((Unit::G<= unit1 && unit1<=Unit::TON) && (Unit::G<= unit2 && unit2<=Unit::TON))
    return 3;
return -1;
 }

 double ariel::PhysicalNumber:: convert(const PhysicalNumber p_n,const Unit unit)
 {
    if (p_n.unit==unit)
      return p_n.data;
    int typeofunit=type(p_n.unit, unit);
    if (typeofunit==1)
    {
      if (unit==Unit::KM)
      {
        if (p_n.unit==Unit::CM)
          return (p_n.data/100000);
        else if (p_n.unit==Unit::M)
          return (p_n.data/1000);
       }
       else if (unit==Unit::CM)
       {
        if (p_n.unit==Unit::KM)
          return (p_n.data*100000);
        else if (p_n.unit==Unit::M)
          return (p_n.data*100);
       }
       else if (unit==Unit::M)
       {
        if (p_n.unit==Unit::CM)
          return (p_n.data/100);
        else if (p_n.unit==Unit::KM)
          return (p_n.data*1000);
       }
    }
    else if (typeofunit==2)
    {
        if (unit==Unit::HOUR)
      {
        if (p_n.unit==Unit::SEC)
          return (p_n.data/3600);
        else if (p_n.unit==Unit::MIN)
          return (p_n.data/60);
       }
       else if (unit==Unit::SEC)
       {
        if (p_n.unit==Unit::HOUR)
          return (p_n.data*3600);
        else if (p_n.unit==Unit::MIN)
          return (p_n.data*60);
       }
       else if (unit==Unit::MIN)
       {
        if (p_n.unit==Unit::HOUR)
          return (p_n.data*60);
        else if (p_n.unit==Unit::SEC)
          return (p_n.data/60);
       }
    }
     else if (typeofunit==3)
    {
        if (unit==Unit::TON)
      {
        if (p_n.unit==Unit::KG)
          return (p_n.data/1000);
        else if (p_n.unit==Unit::G)
          return (p_n.data/1000000);
       }
       else if (unit==Unit::KG)
       {
        if (p_n.unit==Unit::TON)
          return (p_n.data*1000);
        else if (p_n.unit==Unit::G)
          return (p_n.data/1000);
       }
       else if (unit==Unit::G)
       {
        if (p_n.unit==Unit::TON)
          return (p_n.data*1000000);
        else if (p_n.unit==Unit::KG)
          return (p_n.data*1000);
       }
    }

return p_n.data;
 }
  /*  
  }
  static istream& getAndCheckNextCharIs(istream& input, char expectedChar) {
      char actualChar;
      input >> actualChar;
      if (!input) return input;

      if (actualChar!=expectedChar) 
          // failbit is for format error
          input.setstate(ios::failbit);
      return input;
  }
*/
