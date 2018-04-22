#include <iostream>

using namespace std;

int main (void) 
{
	double r;
	const double PI = 3.14158;
	cout << "Ingresar radio:" << endl;
	cin >> r;
	PI = 3.1416;
	cout << PI * r * r << endl;
	return 0;
}
