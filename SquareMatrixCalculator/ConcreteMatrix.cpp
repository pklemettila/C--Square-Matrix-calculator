/** @file ConcreteSquareMatrix.cpp
* @brief Source file for class ConcreteSquareMatrix */
#include "ConcreteMatrix.h"

ConcreteSquareMatrix::ConcreteSquareMatrix() {
n=0;

}
ConcreteSquareMatrix::ConcreteSquareMatrix(const std::string& s){


    if (s == "")
        throw invalid_argument("Invalid init string");

vector <shared_ptr<IntElement>> RiviElementit;
int strsize = s.size();
int strtemp = 0;
int i;
int alkioMaara[10000];
int vaakaRiviLaskuri = 0;
int tempRivit;
int vaaditutPystyt[10000];
int rivinAlkiot = 0;
IntElement tempElement;
string isoluku = "";
bool lastWasLeftBracket, lastWasRightBracket, lastWasDigit, lastWasComma, lastWasMinus;
stringstream ss(s);
char merkki;

for(strtemp = strsize; ss >> merkki; strtemp--) {

if(strtemp == strsize-1) {

    if (merkki != '[') {
        throw invalid_argument("Invalid init string");
     }
     lastWasLeftBracket=true;
     }


if (strtemp == strsize) {
    if (merkki != '[') {
        throw invalid_argument("Invalid init string");
    }

    }

if (strtemp == 1) {

    if (merkki != ']' || lastWasRightBracket != true) {


        throw invalid_argument("Invalid init string");
    }
}

if (strtemp > 1 && strtemp < strsize-1) {



    if (isdigit(merkki) && (lastWasLeftBracket == true || lastWasComma == true || lastWasMinus == true)) {
     lastWasDigit = true;
     lastWasRightBracket = false;
     lastWasLeftBracket = false;
     lastWasComma = false;
     rivinAlkiot++;

     i = merkki-'0';

     if (lastWasMinus==true) {
        i*=(-1);

     }

     lastWasMinus = false;


     shared_ptr<IntElement> ptElement (new IntElement(i));

     RiviElementit.push_back(ptElement);



     isoluku += merkki;




     } else if (isdigit(merkki) && lastWasDigit == true) {
     lastWasDigit = true;
     lastWasRightBracket = false;
     lastWasLeftBracket = false;
     lastWasComma = false;
     lastWasMinus = false;

     RiviElementit.pop_back();
     isoluku += merkki;
     i = stoi(isoluku);


     shared_ptr<IntElement> ptElement (new IntElement(i));


     RiviElementit.push_back(ptElement);




     } else if (merkki == ',' && lastWasDigit == true) {
     lastWasDigit = false;
     lastWasRightBracket = false;
     lastWasLeftBracket = false;
     lastWasComma = true;
     lastWasMinus = false;
     isoluku = "";


     } else if (merkki == '-' && (lastWasComma == true || lastWasLeftBracket == true)) {
     lastWasDigit = false;
     lastWasRightBracket = false;
     lastWasLeftBracket = false;
     lastWasComma = false;
     lastWasMinus = true;
     isoluku += merkki;

    } else if (merkki == ']' && lastWasDigit == true) {
     lastWasDigit = false;
     lastWasRightBracket = true;
     lastWasLeftBracket = false;
     lastWasComma = false;
     lastWasMinus = false;





     elements.push_back(RiviElementit);
     isoluku="";


     vaaditutPystyt[vaakaRiviLaskuri] = rivinAlkiot;
     alkioMaara[vaakaRiviLaskuri] = rivinAlkiot;
     RiviElementit.clear();

     rivinAlkiot = 0;
     vaakaRiviLaskuri++;
     tempRivit = vaakaRiviLaskuri;

    }

    else if (merkki == '[' && lastWasRightBracket == true) {
     lastWasDigit = false;
     lastWasRightBracket = false;
     lastWasLeftBracket = true;
     lastWasComma = false;
    } else {
        throw invalid_argument("Invalid init string");

    }

}
}



  for(int j=0; j < tempRivit; j++) {

         if(alkioMaara[j] != vaaditutPystyt[0]) {

        throw invalid_argument("Invalid init string");

            }else if (tempRivit != vaaditutPystyt[0]) {
        throw invalid_argument("Invalid init string");

            }

  }
n = tempRivit;


}



ConcreteSquareMatrix::ConcreteSquareMatrix(const ConcreteSquareMatrix& m) {
n = m.n;
vector <shared_ptr<IntElement>> RiviElementit;

for(int k=0; k < m.elements.size(); k++) {
    for(auto& a : m.elements[k]) {

    shared_ptr<IntElement> copiedElement = dynamic_pointer_cast<IntElement> (a->clone());
    RiviElementit.push_back(copiedElement);

    }
    elements.push_back(RiviElementit);
    RiviElementit.clear();
}


}
 ConcreteSquareMatrix::~ConcreteSquareMatrix() {
}

ConcreteSquareMatrix::ConcreteSquareMatrix(ConcreteSquareMatrix&& m) {
elements = m.elements;
n = m.n;
m.elements.clear();
m.n = 0;
}



int ConcreteSquareMatrix::getSize() const {
return n;
}

void ConcreteSquareMatrix::setSize(int siz) {
n = siz;
}


std::string ConcreteSquareMatrix::toString() const {
stringstream sqrstring;
sqrstring << "[[";
for(unsigned int k=0; k < n; k++) {

bool eka = true;
    for(auto& a : elements[k]) {
        if(!eka) sqrstring << ",";
        sqrstring << *a;
        eka = false;
    }
if (k != elements.size()-1)
sqrstring << "][";
}
sqrstring << "]]";

return sqrstring.str();
}

ConcreteSquareMatrix ConcreteSquareMatrix::transpose() const {

ConcreteSquareMatrix transposed(*this);

int c = 0;
for(int k=0; k < n; k++) {
    for(auto& a : elements[k]) {
        *transposed.elements[k][c] = *elements[c][k];
    c++;
    }
   c = 0;

}

return transposed;
}

void ConcreteSquareMatrix::print(std::ostream& os) const {
os << "[[";
for(int k=0; k < elements.size(); k++) {

bool eka = true;
    for(auto& a : elements[k]) {
        if(!eka) std::cout << ",";
        std::cout << *a;
        eka = false;
    }
if (k != elements.size()-1)
os << "][";
}
os << "]]";
}


ConcreteSquareMatrix& ConcreteSquareMatrix::operator+=(const ConcreteSquareMatrix& m) {



    if (n != m.n) {
        throw invalid_argument("Matrices not the same size");
    }
vector<vector<shared_ptr<IntElement>>>::const_iterator cit = elements.begin();
for(int i = 0;cit != elements.end(); cit++){
int j=0;
for(auto& a : elements[i]) {
    *elements[i][j]+= *m.elements[i][j];
    j++;

}
i++;

}
return *this;
}
ConcreteSquareMatrix& ConcreteSquareMatrix::operator-=(const ConcreteSquareMatrix& m) {
    if (n != m.n) {
        throw invalid_argument("Matrices not the same size");
    }
vector<vector<shared_ptr<IntElement>>>::const_iterator cit = elements.begin();
for(int i = 0;cit != elements.end(); cit++){
int j=0;
for(auto& a : elements[i]) {
    *elements[i][j]-= *m.elements[i][j];
    j++;

}
i++;

}

return *this;
 }
 ConcreteSquareMatrix& ConcreteSquareMatrix::operator*=(const ConcreteSquareMatrix& m) {
     if (n != m.n) {
        throw invalid_argument("Matrices not the same size");
    }

ConcreteSquareMatrix uusSquare(*this);

for(int i=0; i < n; i++) {
   for(int j=0; j < n; j++) {
       uusSquare.elements[i][j]->setVal(0);
        for(int k=0;k < n; k++) {
          *uusSquare.elements[i][j] += *elements[i][k] * *m.elements[k][j];

        }

   }


}
*this=uusSquare;
return *this;

 }

 ConcreteSquareMatrix& ConcreteSquareMatrix::operator=(const ConcreteSquareMatrix& m) {

 elements = m.elements;
 n = m.n;
 return *this;

 }

 ConcreteSquareMatrix& ConcreteSquareMatrix::operator=(ConcreteSquareMatrix&& m) {

 if (this != &m) {


    elements = m.elements;
    n = m.n;
    m.elements.clear();
    m.n = 0;



 }
return *this;
 }




bool ConcreteSquareMatrix::operator==(const ConcreteSquareMatrix& m) const {

for(int k=0; k < m.elements.size(); k++) {
int j=0;
    for(auto& a : m.elements[k]) {

    if (elements[k][j]->getVal() != m.elements[k][j]->getVal()) {
                return false;
    }
j++;
}

}
return true;
}
ConcreteSquareMatrix operator+(const ConcreteSquareMatrix& sq1, const ConcreteSquareMatrix& sq2) {

if (sq1.getSize() != sq2.getSize()) {
        throw invalid_argument("Matrices not the same size");
    }
ConcreteSquareMatrix result(sq1);

for(unsigned int i=0; i < sq1.n; i++) {
int j=0;
    for(auto& a : sq1.elements[i]) {
        *result.elements[i][j] += *sq2.elements[i][j];
        j++;
     }
}


return result;
}

ConcreteSquareMatrix operator-(const ConcreteSquareMatrix& sq1, const ConcreteSquareMatrix& sq2) {

if (sq1.getSize() != sq2.getSize()) {
        throw invalid_argument("Matrices not the same size");
    }
ConcreteSquareMatrix result(sq1);

for(unsigned int i=0; i < sq1.n; i++) {
int j=0;
    for(auto& a : sq1.elements[i]) {
        *result.elements[i][j] -= *sq2.elements[i][j];
        j++;

     }
}
return result;
}

ConcreteSquareMatrix operator*(const ConcreteSquareMatrix& sq1, const ConcreteSquareMatrix& sq2) {
     if (sq1.getSize() != sq2.getSize()) {
        throw invalid_argument("Matrices not the same size");
    }

ConcreteSquareMatrix uusSquare(sq1);

for(int i=0; i < sq1.n; i++) {
   for(int j=0; j < sq1.n; j++) {
       uusSquare.elements[i][j]->setVal(0);
        for(int k=0;k < sq1.n; k++) {
          *uusSquare.elements[i][j] += *sq1.elements[i][k] * *sq2.elements[k][j];

        }

   }


}
return uusSquare;

 }
std::ostream& operator<<(std::ostream& os, const ConcreteSquareMatrix& sq) {
os << "[[";
for(int k=0; k < sq.n; k++) {

bool eka = true;
    for(auto& a : sq.elements[k]) {
        if(!eka) os << ",";
        os << *a;
        eka = false;
    }
if (k != sq.n-1)
os << "][";
}
os << "]]";



return os;
}
