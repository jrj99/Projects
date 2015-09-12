#include <iostream>
#include <cmath> 
using namespace std;
int main ()
{
	float a = 0; //first side length
	float b; //second side length	
	float c; //hypotenuse (the result)
	
	cout <<" Finding the length of a hypotenuse of a right triangle.\n";
	cout << "By Jared Jones";

	while (a >= 0 ){
	    cout << "\n\nEnter the length of the first side:";
	    cin >> a;
	    if ( a < 0){
		    return 0;
	    }
	    cout << "\nEnter the length of the second side:"; 
	    cin >> b;
	    c = sqrt (pow(a, 2) + pow(b, 2));	    

	    cout << "\n\nThe length of the hypotenuse is:" << c;
	}
	return 0;
}	
