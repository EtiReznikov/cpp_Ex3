/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

   //My PhysicalNUmbers
    PhysicalNumber km(5, Unit::KM);
    PhysicalNumber m(400, Unit::M);
    PhysicalNumber cm(7000, Unit::CM);

    PhysicalNumber min(45, Unit::MIN);
    PhysicalNumber hour(3, Unit::HOUR);
    PhysicalNumber sec(4, Unit::SEC);

    PhysicalNumber ton(7, Unit::TON);
    PhysicalNumber kg(50, Unit::KG);
    PhysicalNumber g(200, Unit::G);

    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT

    .setname("My Basic Output")


    .CHECK_OUTPUT(km, "5[km]")
    .CHECK_OUTPUT(m, "400[m]")
    .CHECK_OUTPUT(cm, "7000[cm]")
    .CHECK_OUTPUT(min, "45[min]")
    .CHECK_OUTPUT(hour, "3[hour]")
    .CHECK_OUTPUT(sec, "30[sec]")
    .CHECK_OUTPUT(ton, "7[ton]")
    .CHECK_OUTPUT(kg, "50[kg]")
    .CHECK_OUTPUT(g, "200[g]")

     .setname("My Compatible dimensions")
    .CHECK_OUTPUT(km+m, "5.4[km]")
    .CHECK_OUTPUT(m+cm, "470[m]")
    .CHECK_OUTPUT(cm+km, "507000[cm]")
    .CHECK_OUTPUT(km+cm, "5.07[km]")
    .CHECK_OUTPUT(m+km, "5400[m]")
    .CHECK_OUTPUT(cm+m, "47000[cm]")

    .CHECK_OUTPUT(min+hour, "225[min]")
    .CHECK_OUTPUT(hour+min, "3.75[hour]")
    .CHECK_OUTPUT(min+sec, "45.5[min]")
    .CHECK_OUTPUT(sec+min, "2730[sec]")

     .CHECK_OUTPUT(ton+kg, "7.05[ton]")
    .CHECK_OUTPUT(kg+ton, "7050[kg]")
  


    .CHECK_OUTPUT((km+=m), "5.4[km]")
    .CHECK_OUTPUT(km, "5.4[km]")
    .CHECK_OUTPUT(km-km, "0[km]")
    .CHECK_OUTPUT((m-=km), "400[m]")
    .CHECK_OUTPUT((m-=m), "0[m]")
    .CHECK_OUTPUT(+min, "45[min]")
    .CHECK_OUTPUT(-hour, "-3[hour]")

 .setname("My Incompatible dimensions")
    .CHECK_THROWS(km+min)
    .CHECK_THROWS(hour+ton)
    .CHECK_THROWS(ton+kg)
    .CHECK_THROWS(kg+min)
    .CHECK_THROWS(sec+kg)
    .CHECK_THROWS(kg+cm)
    .CHECK_THROWS(cm+sec)
    .CHECK_THROWS(sec+ton)
    .CHECK_THROWS(ton+km)
//    .CHECK_THROWS(hour!=PhysicalNumber(3, Unit::TON)


.setname("My boolean")
    .CHECK_EQUAL(hour==PhysicalNumber(3, Unit::HOUR), true)
    .CHECK_EQUAL(hour==PhysicalNumber(180, Unit::MIN), true)
    .CHECK_EQUAL(hour>PhysicalNumber(60, Unit::MIN), false)
    .CHECK_EQUAL(hour<PhysicalNumber(190, Unit::MIN), false)
    .CHECK_EQUAL(hour>PhysicalNumber(70, Unit::MIN), false)

    

    .setname("My Basic input")
    .CHECK_OK(istringstream("5[kg]") >> km)
    .CHECK_OUTPUT((km += PhysicalNumber(7, Unit::KG)), "12[kg]")
    .CHECK_THROWS(km -=PhysicalNumber(8,Unit::HOUR))
   


      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}