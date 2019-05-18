#include "element.h"

Element::~Element() {};




string Element::toString() const {}

int Element::evaluate(const Valuation& val) const {}

std::ostream& operator<<(std::ostream& os, const Element& i) {
os << i;
return os;
}
