/** @file element.h
* @brief the header for Element
*/

#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED
#include <memory>
#include "valuation.h"

class Element {


public:
    /** Clone function for Element*/
virtual shared_ptr<Element> clone() const = 0;
~Element();

/** Returns element in string format */
virtual string toString() const;

/** Returns value of element as int, receives Valuation as parameter */
virtual int evaluate(const Valuation& val) const;


};

std::ostream& operator<<(std::ostream& os, const Element& i);



#endif // ELEMENT_H_INCLUDED
