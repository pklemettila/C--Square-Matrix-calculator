/** @file IntElement.h
* @brief The header file for IntElement
*/
#ifndef INTELEMENT_H_INCLUDED
#define INTELEMENT_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "element.h"
#include <sstream>



using namespace std;

/** Class for IntElement objects. */
class IntElement : public Element {

private:
 /** value contained by IntElement */
 int val = 0;

 public:

 /** Default constructor for IntElement */
 IntElement();
 /** Constructor for IntElement, receives an int parameter */
 IntElement(int v);
 /** Destructor for IntElement */
 ~IntElement();

 /** Clone constructor for IntElement, returns a pointer to the new IntElement */
 shared_ptr<Element> clone() const override;

 int evaluate(const Valuation& v) const override;

 string toString() const override;


 /** Returns the value of int val */
 int getVal() const;
 /** Receives int v as parameter and sets it as the value of val */
 void setVal(int v);

 /** Operator to add values of two IntElements together. Receives one IntElement as parameter, returns the result*/
 IntElement& operator+=(const IntElement& i);
 /** Operator to subtract one value of IntElement from another. Receives one IntElement as parameter, returns the result*/
 IntElement& operator-=(const IntElement& i);
 /** Operator to multiply two values of IntElement. Receives one IntElement as parameter, returns the result*/
 IntElement& operator*=(const IntElement& i);
/** Opetor receives IntElement as parameter, returns true if their values are equal*/
 bool operator==(const IntElement& another) const;
};
 /** Operator to add values of two IntElements that are received as parameters together returns the result*/
 IntElement operator+(const IntElement& i1, const IntElement& i2);
 /** Operator to subtract one value of IntElement from another. Receives two IntElements as parameters, returns the result*/
 IntElement operator-(const IntElement& i1, const IntElement& i2);
 /** Operator to multiply two values of IntElement that are received as parameters, returns the result*/
 IntElement operator*(const IntElement& i1, const IntElement& i2);
 /** An operator that receives an ostream and one IntElement as a parameter, outputs the IntElement into the stream and returns it */
 std::ostream& operator<<(std::ostream& os, const IntElement& i);





#endif // INTELEMENT_H_INCLUDED
