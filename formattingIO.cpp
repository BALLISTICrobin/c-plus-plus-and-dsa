#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Set the showpos flag to display a plus sign for positive numbers
    cout.setf(ios::showpos);
    cout << -100.0 << "\n"; // displays +100.000
    
    // Set uppercase and scientific flags for exponential notation
    cout.setf(ios::uppercase|ios::scientific);
    cout << 100.12 << "\n"; // displays 1.001200E+02
    
    // Clear the uppercase flag
    cout.unsetf(ios::uppercase);
    cout << 100.12 << "\n"; // displays 1.001200e+02

    // Clear showpos, uppercase, and scientific flags
    cout.unsetf(ios::showpos | ios::uppercase | ios::scientific);

    // Set precision to 4 decimal places and a field width of 10 characters
    cout.precision(2);
    cout<<fixed;
    cout.width(10);
    cout << 10.12345 << "\n"; // displays 10.12

    // Set fill character to '*' and a field width of 10 characters
    cout.fill('*');
    cout.width(10);
    cout << 10.12345 << "\n"; // displays *****10.12

    // Reset fill character to default (space) and set field width to 10 characters
    cout.fill(' ');
    cout.width(10);
    cout << "Hi!"
         << "\n"; // displays *******Hi!

    // Set left justification
    cout.width(10);
    cout.fill('*');
    cout.setf(ios::left, ios::adjustfield);
    cout << 10.12345<<endl; // displays 10.12*****

    cout.setf(ios::hex, ios::basefield);
    cout.setf(ios::showbase);
    cout << 176 << endl;

     cout << hex << 100 << endl;
cout << setfill('?') << setw(10) << 2343.0<<endl;
// cout << setiosflags(ios::showpos);
cout << setiosflags(ios::showbase);
cout << 123 << " " << hex << 123<<endl;
cout<<resetiosflags(ios::showbase|ios::hex);
bool b;
b = true;
cout << b << " " << boolalpha << b << endl;
cout << "Enter a Boolean value: ";
cin >> boolalpha >> b;
cout << "Here is what you entered: " << b;


    return 0;
}
