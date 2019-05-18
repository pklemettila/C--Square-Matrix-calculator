/** @file VariableElement.h
* @brief The header file for VariableElement
*/
#ifndef VariableElement_H_INCLUDED
#define VariableElement_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "element.h"
#include <sstream>

using namespace std;

/** Class for VariableElement objects. */
class VariableElement : public Element {

private:
 /** Variable contained by VariableElement */
 char var;

 public:

 /** Default constructor for VariableElement */
 VariableElement();
 /** Constructor for VariableElement, receives an int parameter */
 VariableElement(char v);
 /** Destructor for VariableElement */
 ~VariableElement();

 /** Clone constructor for VariableElement, returns a pointer to the new VariableElement */
 shared_ptr<Element> clone() const override;

 int evaluate(const Valuation& v) const override;

 string toString() const override;

 /** Returns the value of int val */
 char getVal() const;
 /** Receives int v as parameter and sets it as the value of val */
 void setVal(char v);


/** Operator receives VariableElement as parameter, returns true if their values are equal*/
 bool operator==(const VariableElement& another) const;
};

 std::ostream& operator<<(std::ostream& os, const VariableElement& i);





#endif // VariableElement_H_INCLUDED
