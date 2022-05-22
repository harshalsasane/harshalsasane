#include <iostream>
#include <string>
using namespace std;
class Telephone
{
long mobile_no[10];
string name[10];
long key;
int address;
public:
Telephone()
{
for(int i=0;i<10;i++)
{
mobile_no[i]=-1;
}
}
void insertRecord_LP()
{
// for(int j=0; j<n ;j++)
// {
//ask for choice linear /quadratic
//switch case
cout<<"Enter Mobile Number : "<<endl;
cin>>key;
int hash_address = key%10;
while (1)
{
if(mobile_no[hash_address]==-1)
{
mobile_no[hash_address]=key;
cout<<"Enter Name: "<<endl;
cin>>name[hash_address];
break;
}
else
{
hash_address ++;
if(mobile_no[hash_address]<10)
{
if(mobile_no[hash_address]==-1)
{
mobile_no[hash_address]=key;
cout<<"Enter Name: "<<endl;
cin>>name[hash_address];
break;
}
}
else
hash_address=0;
}
} //}
}
void insertRecord_QP()
{
// for(int j=0; j<n ;j++)
// {
//ask for choice linear /quadratic
//switch case
cout<<"Enter Mobile Number : "<<endl;
cin>>key;
int hash_address = key%10;
while (1)
{
if(mobile_no[hash_address]==-1)
{
mobile_no[hash_address]=key;
cout<<"Enter Name: "<<endl;
cin>>name[hash_address];
break;
}
else
{
int i=1;
hash_address += (i*i);
//address = address%10;
i++;
if(mobile_no[hash_address]<10)
{
if(mobile_no[hash_address]==-1)
{
mobile_no[hash_address]=key;
cout<<"Enter Name: "<<endl;
cin>>name[hash_address];
break;
}
}
else
hash_address=0;
}
}
//case 2: { Quadratic
//}
}
void display()
{
for (int k = 0; k<10; k++)
{
cout<<k<<" "<<mobile_no[k]<<" "<<name[k]<<endl;
}
}
};
int main()
{
Telephone obj;
int choice;
do
{
cout << "\n1.Insert Record(Linear Probing)";
cout << "\n2.Insert Record(Quadratic Probing)";
cout << "\n3.Display Records";
cout << "\n4.Exit";
cout << "\n\nEnter your choice: ";
cin >> choice;
switch (choice)
{
case 1:
int n;
// cout<<"Enter number of records you want to enter : "<<endl;
// cin>>n;
obj.insertRecord_LP();
break;
case 2:
obj.insertRecord_QP();
break;
case 3:
obj.display();
break;
}
}while(choice!=4);
return 0;
}