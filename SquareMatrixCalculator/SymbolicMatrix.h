
/** @file SymbolicSquareMatrix.h
* @brief The header file for SymbolicSquareMatrix
*/
#ifndef SYMBOLICSQUAREMATRIX_H_INCLUDED
#define SYMBOLICSQUAREMATRIX_H_INCLUDED
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "IntElement.h"
#include "varelement.h"
#include "ConcreteMatrix.h"
/** Class for IntElement objects  */
class SymbolicSquareMatrix {

private:
 unsigned int n;
 std::vector<std::vector<shared_ptr<Element>>> elements;

public:

 /** Default constructor for SymbolicSquareMatrix */
 SymbolicSquareMatrix();

 /**Constructs a matrix from the string */
 SymbolicSquareMatrix(const std::string& str_m);

 /** Copy constructor for SymbolicSquareMatrix. Receives another SymbolicSquareMatrix as a parameter */
SymbolicSquareMatrix(const SymbolicSquareMatrix& m);

/** Move constructor for SymbolicSquareMatrix. Receives an rvalue reference to another SymbolicSquareMatrix as a parameter */
SymbolicSquareMatrix(SymbolicSquareMatrix&& m);

 /** Destructor for SymbolicSquareMatrix */
 ~SymbolicSquareMatrix();

 /** Creating concreteSquareMatrix out of the SymbolicSquareMatrix. Receives std::map as parameter */
 ConcreteSquareMatrix evaluate(const Valuation& val) const;

 /** Returns size n of SymbolicSquareMatrix */
 int getSize() const;

/** Copies values of one SymbolicSquareMatrix into another */
 SymbolicSquareMatrix& operator=(const SymbolicSquareMatrix& m);

/**Move assignment operator for SymbolicSquareMatrix, another SymbolicSquareMatrix as parameter */
 SymbolicSquareMatrix& operator=(SymbolicSquareMatrix&& m);


/** Transposes the current matrix */
 SymbolicSquareMatrix transpose() const;

  /** Receives an ostream as a parameter and prints out the ConcreteSquareMatrix */
 void print(std::ostream& os) const;

 /** Returns the ConcreteSquareMatrix in a string format */
 std::string toString() const;

bool operator==(const SymbolicSquareMatrix& m) const;

/** Friending ostream operator */
friend std::ostream& operator<<(std::ostream&, const SymbolicSquareMatrix&);


};


/** Operator to print a SymbolicSquareMatrix, receives ostream and SymbolicSquareMatrix as parameter */
std::ostream& operator<<(std::ostream&, const SymbolicSquareMatrix&);


#endif // SymbolicSquareMatrix_H_INCLUDED
