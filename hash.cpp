#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct dic
{
char word[30];
char meaning[30];
int chain;
};
class Hash
{
public:
int n,sum,x,c,location=-1,i;
char w[30],m[30];
dic d[10];
public:
Hash()
{ for(int i=0;i<10;i++)
{
strcpy(d[i].word," ");
d[i].chain=-1;
}
}
void insert();
void search();
void dele();
void display();
};
void Hash::insert()
{
cout<<"\n Enter no. of words in Dictionary : ";
cin>>n;
for(int j=0;j<n;j++)
{
cout<<"\n\n Enter the word:";
cin>>w;
cout<<"\n enter the meaning of that word "<<w<<" meaning =";
cin>>m;
sum=0;
for(i=0;w[i]!='\0';i++)
{
sum=sum+w[i];
}
x=sum%10;
c=x;
while(1)
{
if(strcmp(d[x].word," ")==0)
{
strcpy(d[x].word,w);
strcpy(d[x].meaning,m);
if(c!=x)
{
d[c].chain=x;
}
break;
}
else
x=(x+1)%10;
if(c==x)
{ cout<<"\n hash table is full";
break;
}
}
}
}
void Hash::display()
{
for(int i=0;i<10;i++)
{
cout<<"\n "<<d[i].word<<"\t "<<d[i].meaning<<"\t"<<d[i].chain;
}
}
void Hash::search()
{
cout<<"\n enter the word whose meaning you want = ";
cin>>w;
sum=0;
for(int i=0;i<strlen(w);i++)
{ sum=sum+(int)w[i];
}
x=(sum/strlen(w))%10;
c=x;
while(1)
{
if(!strcmp(d[x].word,w))
{ cout<<"\n MEANING-> "<<d[x].word<<"="<<d[x].meaning;
break;
}
x=(x+1)%10;
if(c==x)
{ cout<<"\n word not found";
break;
}
}
}
void Hash::dele()
{
cout<<"\n enter the word which is to be deleted";
cin>>w;
sum=0;
for(int i=0;i<strlen(w);i++)
{
sum=sum+(int)w[i];
}
x=(sum/strlen(w))%10;
c=x;
while(1)
{
if(!strcmp(d[x].word,w))
{ cout<<"\n"<<d[x].word<<" word deleted";
strcpy(d[x].word," "); strcpy(d[x].meaning," ");
break;
}
x=(x+1)%10;
if(c==x)
{ cout<<"\n word not found";
break;
}
}
}
int main()
{
Hash h;
h.insert();
h.display();
h.search();
h.dele();
return 0;
}