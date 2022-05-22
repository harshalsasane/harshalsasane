// Assignment 4
#include<iostream>
#include<math.h>
using namespace std;
struct node
{
int data;
node *left = NULL;
node *right = NULL;
};
class BST
{
int n;
int x;
int flag;
public:
node * root;
BST()
{
root = NULL;
}
node *NewNode(int in_data)
{
node * ptr = new node();
ptr->data = in_data;
ptr->left = NULL;
ptr->right = NULL;
return ptr;
}
node *insert( node *temp , int in_data)
{
if( temp == NULL )
{
temp = NewNode(in_data);
}
else if( temp->data > in_data)
{
temp->left = insert(temp->left , in_data);
}
else
{
temp->right = insert( temp->right , in_data);
} return temp;
}
void input()
{
cout<<"enter number of elements to be inserted";
cin>>n;
for(int i = 0 ; i < n ; i++)
{
cout<<"number = ";
cin>>x;
root = insert(root , x);
}
}
int search(node *temp ,int in_data)
{
if( temp != NULL)
{
if(temp->data == in_data)
{
cout<<"element found "<<endl;
return 1;
}
else if(in_data < temp->data)
{
this->search(temp->left, in_data);
}
else if(in_data > temp->data)
{
this->search(temp->left , in_data);
}
}
else
{
return 0;
}
}
void minvalue(node *temp)
{
while(temp->left != NULL)
{
temp = temp->left;
}
cout<<"min value = "<<temp->data<<endl;
}
void mirror(node *temp)
{
if(temp == NULL)
{
return;
}
else
{
node *ptr;
mirror(temp->left);
mirror(temp->right);
ptr = temp->left;
temp->left = temp->right;
temp->right = ptr;
}
}
void display()
{
cout<<endl<<"inorder traversal"<<endl;
inorder(root);
cout<<endl;
cout<<endl<<"preorder traversal"<<endl;
preorder(root);
cout<<endl;
cout<<endl<<"postorder traversal"<<endl;
postorder(root);
cout<<endl;
}
void inorder(node *temp)
{
if(temp != NULL)
{
inorder(temp->left);
cout<<temp->data<<" ";
inorder(temp->right);
}
}
void preorder(node *temp)
{
if(temp != NULL)
{
cout<<temp->data<<" ";
preorder(temp->left);
preorder(temp->right);
}
}
void postorder(node *temp)
{
if(temp != NULL)
{
postorder(temp->left);
postorder(temp->right);
cout<<temp->data<<" ";
}
}
int depth(node *temp)
{
if(temp == NULL)
return 0;
return (max((depth(temp->left)),(depth(temp->right))) +1);
}
};
int main()
{
BST T;
T.input();
T.display();
int a;
int z;
cout<<"enter the number to be searched";
cin>>z;
a = T.search(T.root,z);
if( a == 0)
{
cout<<"not found"<<endl;
}
else
{
cout<<"found"<<endl;
}
cout<<endl<<a<<endl;
T.minvalue(T.root);
T.mirror(T.root);
T.inorder(T.root);
cout<<endl<<"depth is "<<T.depth(T.root);
return 0;
}