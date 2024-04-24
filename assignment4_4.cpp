#include <iostream>
#include <cmath>

using namespace std;

int main()
{
int binary, mod;
int hexDec = 0;
int base = 1;
cout << "Enter the binary number: " << endl;
cin >> binary;
while (binary) 
{
	mod = binary % 10;
	binary = binary / 10;
	hexDec += mod * base;
	base = base * 2;
	}
cout << "Equivalent hexadecimal value: " << hexDec << endl;
return 0;
}
