//compare.cpp
#include <iostream>
#include <string>
using namespace std;

char compare(int &param1, int &param2){
param1 = -param1;
param2 = -param2;
char a = '=';
char b = '<';
char c = '>';
if (param1 == param2)
	return a;
if (param1 < param2)
	return b;
if (param1 >= param2)
	return c;
}



