/** @file intelement_tests.cpp
* @brief Test file for IntElement */


#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "valuation.h"
#include "IntElement.h"
#include "ConcreteMatrix.h"
#include "SymbolicMatrix.h"
/** Test function for IntElement */
TEST_CASE("IntElement testing", "[intelement]") {
IntElement ie_default();
IntElement ie(7);
CHECK(ie.getVal() == 7);
IntElement ie_other(-15);
ie += ie_other;
CHECK(ie.getVal()==-8);
IntElement ie_sum = ie + ie_other;
CHECK(ie_sum.getVal()==-23);
IntElement ie1(5);
IntElement ie2(6);
IntElement ie_vahennys = ie2 - ie1;
CHECK(ie_vahennys.getVal() == 1);
IntElement ie_tulo = ie1 * ie2;
CHECK(ie_tulo.getVal() == 30);
ie_tulo.setVal(5);
CHECK(ie_tulo.getVal() == 5);
ie1 -= ie2;
CHECK(ie1.getVal() == -1);
ie1 *= ie2;
CHECK(ie1.getVal() == -6);
ie1.clone();
}


/** Test function for ConcreteSquareMatrix */
TEST_CASE("Square matrix calculations", "[matrix]") {
ConcreteSquareMatrix uusMatrix("[[4,5][6,7]]");
ConcreteSquareMatrix transiksi("[[5,6][7,8]]");
ConcreteSquareMatrix m("[[5,6][7,8]]");
CHECK_FALSE(m == ConcreteSquareMatrix("[[5,6][7,9]]"));
CHECK(transiksi.transpose() == ConcreteSquareMatrix("[[5,7][6,8]]"));
CHECK(uusMatrix.transpose().toString() == "[[4,6][5,7]]");
CHECK(uusMatrix.toString()=="[[4,5][6,7]]");
ConcreteSquareMatrix kopioituMatrix(uusMatrix);
CHECK(kopioituMatrix.toString()=="[[4,5][6,7]]");
ConcreteSquareMatrix SqurriMatrix("[[100,-200,3,4][10,12,14,15][3,4,5,6][7,8,1,2]]");
CHECK(SqurriMatrix.toString()=="[[100,-200,3,4][10,12,14,15][3,4,5,6][7,8,1,2]]");
ConcreteSquareMatrix transposematrix = SqurriMatrix.transpose();
ConcreteSquareMatrix plusMatrix("[[1,4][5,6]]");
ConcreteSquareMatrix plusMatrix2("[[2,4][7,8]]");
CHECK(plusMatrix2 == ConcreteSquareMatrix("[[2,4][7,8]]"));
plusMatrix+=plusMatrix2;
CHECK(plusMatrix.toString()=="[[3,8][12,14]]");
plusMatrix -= plusMatrix2;
std::cout << plusMatrix << "plusmatriisi eka" << std::endl;

CHECK(plusMatrix.toString()=="[[1,4][5,6]]");
ConcreteSquareMatrix summaMatrix(plusMatrix2);

std::cout << plusMatrix << "plusmatriisi" << std::endl;

std::cout << plusMatrix2 << "miinusmatriisi" << std::endl;

summaMatrix = plusMatrix+plusMatrix2;
CHECK(summaMatrix.toString()=="[[3,8][12,14]]");

std::cout << plusMatrix << "plusmatriisi" << std::endl;

std::cout << plusMatrix2 << "miinusmatriisi" << std::endl;

summaMatrix = plusMatrix-plusMatrix2;
CHECK(summaMatrix.toString()=="[[-1,0][-2,-2]]");


ConcreteSquareMatrix kertoMatrix("[[1,0][-3,2]]");
ConcreteSquareMatrix kertoMatrix2("[[-1,4][3,5]]");
kertoMatrix *= kertoMatrix2;
CHECK(kertoMatrix.toString()=="[[-1,4][9,-2]]");
ConcreteSquareMatrix kertoMatrix3("[[4,6,8][2,1,4][6,9,3]]");
ConcreteSquareMatrix kertoMatrix4("[[1,5,8][4,3,2][7,6,5]]");
kertoMatrix3 *= kertoMatrix4;
CHECK(kertoMatrix3.toString()=="[[84,86,84][34,37,38][63,75,81]]");
ConcreteSquareMatrix kertoMatrix5("[[1,0][-3,2]]");
ConcreteSquareMatrix kertoMatrix6("[[-1,4][3,5]]");
ConcreteSquareMatrix kerrottuMatrix = kertoMatrix5 * kertoMatrix6;
CHECK(kerrottuMatrix.toString()=="[[-1,4][9,-2]]");
kertoMatrix6 = kerrottuMatrix;
CHECK(kertoMatrix6.toString() =="[[-1,4][9,-2]]");


}

TEST_CASE("VarElement", "[tests]") {
VariableElement vari;
vari.setVal('c');
Valuation d;
d['c']=4;
CHECK(vari.evaluate(d) == 4);




}

TEST_CASE("SymbolicMatrix", "[tests]") {
SymbolicSquareMatrix uusMatrix("[[4,5][6,x]]");
CHECK(uusMatrix.toString() == "[[4,5][6,x]]");
uusMatrix.print(cout);
Valuation d;
d['x']=10;
CHECK(uusMatrix.evaluate(d).toString() == "[[4,5][6,10]]");
uusMatrix.evaluate(d).print(cout);

}
