/** @file IntElement.cpp
*@brief source file for IntElement
*/

#include "IntElement.h"


IntElement::IntElement() {
val = 0;
}

IntElement::IntElement(int v):val(v)
{
}
int IntElement::getVal() const {
return val;

}

void IntElement::setVal(int v) {
val = v;
}


IntElement::~IntElement() {

}

shared_ptr<Element> IntElement::clone() const {

shared_ptr<IntElement> cloneInt (new IntElement(val));
return cloneInt;
}


IntElement& IntElement::operator+=(const IntElement& i) {
val += i.val;
return *this;

}

IntElement& IntElement::operator-=(const IntElement& i) {
val -= i.val;
return *this;

}

IntElement& IntElement::operator*=(const IntElement& i) {
val *= i.val;
return *this;

}

bool IntElement::operator==(const IntElement& another) const{
    if (val==another.val)
    return true;
else return false;

}


IntElement operator+(const IntElement& i1, const IntElement& i2) {
IntElement result = i1;
result += i2;
return result;

}

IntElement operator-(const IntElement& i1, const IntElement& i2) {
IntElement result = i1;
result -= i2;
return result;


}

IntElement operator*(const IntElement& i1, const IntElement& i2) {
IntElement result = i1;
result *= i2;
return result;


}


 std::ostream& operator<<(std::ostream& os, const IntElement& i) {
 os << i.getVal();
 return os;


 }

 int IntElement::evaluate(const Valuation& v) const {
      return val;
  }

 string IntElement::toString() const {
 stringstream ss;
 ss << val;
 return ss.str();

 }

