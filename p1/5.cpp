#include <iostream>

using namespace std;

int main (void)
{
	int n = 2;
	n = n + (++n);
	cout << n << endl;
	return 0;
}
