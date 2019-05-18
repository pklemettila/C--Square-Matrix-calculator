/** @file ConcreteSquareMatrix.h
* @brief The header file for ConcreteSquareMatrix
*/
#ifndef CONCRETESQUAREMATRIX_H_INCLUDED
#define CONCRETESQUAREMATRIX_H_INCLUDED
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include "IntElement.h"

/** Class for IntElement objects  */
class ConcreteSquareMatrix {

private:
 unsigned int n;
 std::vector<std::vector<shared_ptr<IntElement>>> elements;

public:

 /** Default constructor for ConcreteSquareMatrix */
 ConcreteSquareMatrix();

 /**Constructs a matrix from the string */
 ConcreteSquareMatrix(const std::string& s);

 /** Copy constructor for ConcreteSquareMatrix. Receives another ConcreteSquareMatrix as a parameter */
ConcreteSquareMatrix(const ConcreteSquareMatrix& m);

/** Move constructor for ConcreteSquareMatrix. Receives an rvalue reference to another ConcreteSquareMatrix as a parameter */
ConcreteSquareMatrix(ConcreteSquareMatrix&& m);

 /** Destructor for ConcreteSquareMatrix */
 ~ConcreteSquareMatrix();

 /** Returns size n of ConcreteSquareMatrix */
 int getSize() const;

 /** Sets the size of ConcreteSquareMatrix to int siz */
 void setSize(int siz);

/** Copies values of one ConcreteSquareMatrix into another */
 ConcreteSquareMatrix& operator=(const ConcreteSquareMatrix& m);

/**Move assignment operator for ConcreteSquareMatrix, another ConcreteSquareMatrix as parameter */
 ConcreteSquareMatrix& operator=(ConcreteSquareMatrix&& m);


/** Transposes the current matrix */
 ConcreteSquareMatrix transpose() const;

 /** An operator to add two ConcreteSquareMatrix objects together. Receives a ConcreteSquareMatrix as a parameter, returns the sum */
 ConcreteSquareMatrix& operator+=(const ConcreteSquareMatrix& m);

 /** An operator to subtract one ConcreteSquareMatrix from another. Receives one ConcreteSquareMatrix as a parameter, returns the result */
 ConcreteSquareMatrix& operator-=(const ConcreteSquareMatrix& m);

 /** An operator to multiply two ConcreteSquareMatrix objects. Receives one ConcreteSquareMatrix as parameter, returns the result */
 ConcreteSquareMatrix& operator*=(const ConcreteSquareMatrix& m);

 /** Returns true if two SquareMatrices are equal. Receives ConcreteSquareMatrix as parameter */
 bool operator==(const ConcreteSquareMatrix& m) const;

 /** Receives an ostream as a parameter and prints out the ConcreteSquareMatrix */
 void print(std::ostream& os) const;

 /** Returns the ConcreteSquareMatrix in a string format */
 std::string toString() const;

 /** Making friends with ConcreteSquareMatrix operators */
friend ConcreteSquareMatrix operator+(const ConcreteSquareMatrix&, const ConcreteSquareMatrix&);
friend ConcreteSquareMatrix operator-(const ConcreteSquareMatrix&, const ConcreteSquareMatrix&);
friend ConcreteSquareMatrix operator*(const ConcreteSquareMatrix&, const ConcreteSquareMatrix&);
friend std::ostream& operator<<(std::ostream&, const ConcreteSquareMatrix&);


};

/** Receives two square matrices as parameter, returns their sum */
ConcreteSquareMatrix operator+(const ConcreteSquareMatrix&, const ConcreteSquareMatrix&);
/** Receives two square matrices as parameter, subtracts one and returns the result */
ConcreteSquareMatrix operator-(const ConcreteSquareMatrix&, const ConcreteSquareMatrix&);
/** Receives two square matrices as parameter, multiplies them with each other and returns the result */
ConcreteSquareMatrix operator*(const ConcreteSquareMatrix&, const ConcreteSquareMatrix&);
/** Operator to print a ConcreteSquareMatrix, receives ostream and ConcreteSquareMatrix as parameter */
std::ostream& operator<<(std::ostream&, const ConcreteSquareMatrix&);


#endif // ConcreteSquareMatrix_H_INCLUDED
