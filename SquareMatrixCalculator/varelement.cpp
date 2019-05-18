/** @file varelement.cpp
* @brief Test file for IntElement */


#include "varelement.h"

VariableElement::VariableElement() {

}

VariableElement::VariableElement(char v) {
var = v;

}

VariableElement::~VariableElement() {
}

char VariableElement::getVal() const {
return var;
}

void VariableElement::setVal(char v) {
var = v;
}

shared_ptr<Element> VariableElement::clone() const {

shared_ptr<VariableElement> cloneVar (new VariableElement(var));
return cloneVar;
}

 int VariableElement::evaluate(const Valuation& v) const{
 Valuation kopio = v;
 int valuated;

 if(kopio.count(var)) {
 valuated = kopio[var];
 return valuated;

 } else throw invalid_argument ("Value not initialized");

 }

 string VariableElement::toString() const {
 stringstream ss;
 ss << var;
 return ss.str();

 }


bool VariableElement::operator==(const VariableElement& another) const{
    if (var==another.var)
    return true;
else return false;

}

 std::ostream& operator<<(std::ostream& os, const VariableElement& i) {

os << i.getVal();
return os;


 }
