#include<iostream>
using namespace std;
 
int main()
{
double volume;
double Pi = 3.14;
int radius;
cout << "Enter Radius: " << endl;
cin >> radius;
volume = (radius * radius * radius) * Pi;	
cout << "The volume is: " << volume;
return 0;
}
