#include <iostream>
using namespace std;
struct A {
A(string s) : name(s) {};
string name;
void print() { cout << name << " betalar hyran A" << endl; };
};
struct B : A {
B(string s) : A("Riksdagen"), name(s) {};
string name;
virtual void print() { cout << name << " betalar hyran B" << endl; };
};
struct C : A {
	C(string s) : A("ShitAboutToGetReal"), name(s) {};
string name;
virtual void print() { cout << name << " betalar hyran C" << endl; };
};
void f1(A & p) {
p.print();
}
void f2(A p) {
p.print(); // ingen dynamisk bindning
}
int main() {
B b1("Håkan");
C b2("EEEåkan");
A & aref(b1);
A & eref(b2);
A acopy = b1;

b1.print(); // ingen dynamisk bindning

aref.print();

eref.print();

acopy.print(); // ingen dynamisk bindning

f1(b1);

f2(b1); //
}