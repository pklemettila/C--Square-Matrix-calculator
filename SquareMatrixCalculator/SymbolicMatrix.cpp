#include "SymbolicMatrix.h"

SymbolicSquareMatrix::SymbolicSquareMatrix() {
}

SymbolicSquareMatrix::~SymbolicSquareMatrix() {
}


SymbolicSquareMatrix::SymbolicSquareMatrix(const string& str_m){
    if (str_m == "")
        throw invalid_argument("Invalid init string0");

vector <shared_ptr<Element>> RiviElementit;
int strsize = str_m.size();
int strtemp = 0;
int i;
int alkioMaara[10000];
int vaakaRiviLaskuri = 0;
int tempRivit;
int vaaditutPystyt[10000];
int rivinAlkiot = 0;
IntElement tempElement;
string isoluku = "";
bool lastWasLeftBracket, lastWasRightBracket, lastWasDigit, lastWasComma, lastWasMinus, lastWasVariable;
stringstream ss(str_m);
char merkki;

for(strtemp = strsize; ss >> merkki; strtemp--) {

if(strtemp == strsize-1) {

    if (merkki != '[') {
        throw invalid_argument("Invalid init string1");
     }
     lastWasLeftBracket=true;
     }


if (strtemp == strsize) {
    if (merkki != '[') {
        throw invalid_argument("Invalid init string2");
    }

    }

if (strtemp == 1) {

    if (merkki != ']' || lastWasRightBracket != true) {


        throw invalid_argument("Invalid init string3");
    }
}

if (strtemp > 1 && strtemp < strsize-1) {



    if (isdigit(merkki) && (lastWasLeftBracket == true || lastWasComma == true || lastWasMinus == true)) {
     lastWasDigit = true;
     lastWasRightBracket = false;
     lastWasLeftBracket = false;
     lastWasComma = false;
     lastWasVariable = false;
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
     lastWasVariable = false;

     RiviElementit.pop_back();
     isoluku += merkki;
     i = stoi(isoluku);


     shared_ptr<IntElement> ptElement (new IntElement(i));


     RiviElementit.push_back(ptElement);

     } else if (isalpha(merkki) && (lastWasLeftBracket == true || lastWasComma == true)) {

     lastWasDigit = false;
     lastWasRightBracket = false;
     lastWasLeftBracket = false;
     lastWasComma = false;
     lastWasVariable = true;
     rivinAlkiot++;



     shared_ptr<VariableElement> vrElement (new VariableElement(merkki));

     RiviElementit.push_back(vrElement);



     } else if (merkki == ',' && (lastWasDigit == true || lastWasVariable == true)) {
     lastWasDigit = false;
     lastWasRightBracket = false;
     lastWasLeftBracket = false;
     lastWasComma = true;
     lastWasMinus = false;
     lastWasVariable = false;
     isoluku = "";


     } else if (merkki == '-' && (lastWasComma == true || lastWasLeftBracket == true)) {
     lastWasDigit = false;
     lastWasRightBracket = false;
     lastWasLeftBracket = false;
     lastWasComma = false;
     lastWasMinus = true;
     lastWasVariable = false;

     isoluku += merkki;

    } else if (merkki == ']' && (lastWasDigit == true || lastWasVariable == true)) {
     lastWasDigit = false;
     lastWasRightBracket = true;
     lastWasLeftBracket = false;
     lastWasComma = false;
     lastWasMinus = false;
     lastWasVariable = false;






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
        throw invalid_argument("Invalid init string4");

    }

}
}


  for(int j=0; j < tempRivit; j++) {
         if(alkioMaara[j] != vaaditutPystyt[0]) {

        throw invalid_argument("Invalid init string5");

            }else if (tempRivit != vaaditutPystyt[0]) {
        throw invalid_argument("Invalid init string6");

            }
  }

n = tempRivit;
cout << "ännä: " << n << endl;


}




SymbolicSquareMatrix::SymbolicSquareMatrix(const SymbolicSquareMatrix& m) {
n = m.n;
vector <shared_ptr<Element>> RiviElementit;

for(int k=0; k < m.elements.size(); k++) {

    for(auto& a : m.elements[k]) {


    shared_ptr<Element> copiedInt = (a->clone());

    RiviElementit.push_back(copiedInt);

    }
    elements.push_back(RiviElementit);
    RiviElementit.clear();
}


}


 ConcreteSquareMatrix SymbolicSquareMatrix::evaluate(const Valuation& val) const {

stringstream sqrstring;
sqrstring << "[[";
for(unsigned int k=0; k < n; k++) {

bool eka = true;
    for(auto& a : elements[k]) {

       if(!eka) sqrstring << ",";

    if (dynamic_pointer_cast<IntElement>(a)) {
        sqrstring << *dynamic_pointer_cast<IntElement>(a);

    } else {
        sqrstring << dynamic_pointer_cast<VariableElement>(a)->evaluate(val);
         }
         eka = false;
    }
if (k != elements.size()-1)
sqrstring << "][";
}
sqrstring << "]]";

ConcreteSquareMatrix fromSymbolic(sqrstring.str());
return fromSymbolic;
}

SymbolicSquareMatrix::SymbolicSquareMatrix(SymbolicSquareMatrix&& m) {
elements = m.elements;
n = m.n;
m.elements.clear();
m.n = 0;
}

 SymbolicSquareMatrix& SymbolicSquareMatrix::operator=(const SymbolicSquareMatrix& m) {

 elements = m.elements;
 n = m.n;
 return *this;

 }

 SymbolicSquareMatrix& SymbolicSquareMatrix::operator=(SymbolicSquareMatrix&& m) {

 if (this != &m) {


    elements = m.elements;
    n = m.n;
    m.elements.clear();
    m.n = 0;



 }
return *this;
 }

 SymbolicSquareMatrix SymbolicSquareMatrix::transpose() const {

SymbolicSquareMatrix transposed(*this);

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

std::string SymbolicSquareMatrix::toString() const {
stringstream sqrstring;
sqrstring << "[[";
for(unsigned int k=0; k < n; k++) {

bool eka = true;
    for(auto& a : elements[k]) {

       if(!eka) sqrstring << ",";

    if (dynamic_pointer_cast<IntElement>(a)) {
        sqrstring << *dynamic_pointer_cast<IntElement>(a);

    } else {
        sqrstring << *dynamic_pointer_cast<VariableElement>(a);
         }
         eka = false;
    }
if (k != elements.size()-1)
sqrstring << "][";
}
sqrstring << "]]";

return sqrstring.str();
}

bool SymbolicSquareMatrix::operator==(const SymbolicSquareMatrix& m) const {

for(int k=0; k < m.elements.size(); k++) {
int j=0;
    for(auto& a : m.elements[k]) {

    if (elements[k][j] == m.elements[k][j]) {

    } else return false;
j++;
}

}
return true;
}


void SymbolicSquareMatrix::print(std::ostream& os) const {
os << "[[";
for(int k=0; k < elements.size(); k++) {

bool eka = true;
    for(auto& a : elements[k]) {
        if(!eka) std::cout << ",";
        if (dynamic_pointer_cast<IntElement>(a)) {
        cout << *dynamic_pointer_cast<IntElement>(a);

    } else {
        cout << *dynamic_pointer_cast<VariableElement>(a);
         }
        eka = false;
    }
if (k != elements.size()-1)
os << "][";
}
os << "]]";
}

std::ostream& operator<<(std::ostream& os, const SymbolicSquareMatrix& sq) {
os << "[[";
for(int k=0; k < sq.n; k++) {

bool eka = true;
    for(auto& a : sq.elements[k]) {
        if(!eka) os << ",";
        if (dynamic_pointer_cast<IntElement>(a)) {
        os << *dynamic_pointer_cast<IntElement>(a);

    } else {
        os << *dynamic_pointer_cast<VariableElement>(a);
         }
         eka = false;
    }

if (k != sq.n-1)
os << "][";
}
os << "]]";



return os;
}
