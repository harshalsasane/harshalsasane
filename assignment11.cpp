#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include <unistd.h>
int main()
{
ofstream o1;
string s1;
o1.open("Sample.txt");
cout << "\nWriting the File...\n";
sleep(3);
cout << "Enter student name: ";
getline(cin, s1);
o1 << "Name: " << s1 << endl;
cout << "Enter student roll no: ";
getline(cin, s1);
o1 << "Roll no: " << s1 << endl;
// Reading
ifstream i1;
i1.open("Sample.txt");
cout << "\nReading the File:\n";
sleep(3);
while (i1)
{
getline(i1, s1);
cout << s1 << endl;
}
cout << endl;
return 0;
}