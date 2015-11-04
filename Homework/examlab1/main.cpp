//main.cpp

#include <iostream>
#include <string>
#include "compare.h"
using namespace std;

int main(){

int var1;
int var2;

cout << endl << "Please enter an integer number: ";
cin >> var1;
cout << endl << "Please enter an additional number: ";
cin >> var2;

char o;
o = compare(var1, var2);
if (o == '=')
	cout << endl << var1 << " is equal to " << var2;
if (o == '<')
	cout << endl << var1 << " is less than " << var2;
if (o == '>')
	cout << endl << var1 << " is more than " << var2;
return 0;

}
