#include<iostream>
using namespace std;
class Node{
    public:
    Node *left;
    int val;
    Node *right;
    Node(int val)
    {
        this->val=val;
    }
};
int maxx(int a,int b)
{ if(a>=b)return a;
    return b;     }
int height(Node *root)
{
   if(root==NULL)
     return 0;
    return 1+maxx(height(root->left),height(root->right));  
}
Node * balanced(Node *root)
{
    if(root==NULL)
        return root;
    int balance= height(root->left)-height(root->right);
    if(-2<balance and balance<2)
        return root;
    Node *temp=NULL;
    if(balance<-1)  //right subtree is unbalanaced -2;
    {   temp=root->right;
        if(temp->left==NULL)
        { temp->left=root;
          root->right=NULL;
          cout<<"right right Rotation";
          return temp;
        } 
        else
        {   //RL rotation.
         int val = temp->val;
         temp->val=temp->left->val;
         temp->left->val=val;
         temp->right=temp->left;
         temp->left=root;
         root->right=NULL;
         cout<<"right left Rotation";
         return temp;
        }
    }
    else  ///left subtree is unbalanced +2;
    {  temp=root->left;
        if(temp->right==NULL) //ll
        {   temp->right=root;
            root->left=NULL ;
            cout<<"left left Rotation";
            return temp;  
        }
        else //lr
        { int val =temp->val;
        temp->val=temp->right->val;
        temp->right->val=val;
        temp->left=temp->right;
        temp->right=root;
        root->left=NULL;
        cout<<"left right Rotation";
        return temp;
        }
    }
return root;

}
void inorder(Node * root)
{
if(root==NULL)
   return;
inorder(root->left);
cout<<root->val<<" ";
inorder(root->right);
}
Node * insert(Node *root, int val)
{
  if(root==NULL)
     root= new Node(val);  
 else if(val<root->val)
  root->left= insert(root->left,val);
 else if(root->val<val)
  root->right=insert(root->right,val);
  
   root=balanced(root);
return root;
}
int main()
{
Node *root=NULL;
int n,val=0;
cout<<"Press 1 to insert, 2 to check height, 3 for Inorder Traversal :";
cin>>n;
while(n!=0)
{   if(n==1){
    cout<<"Enter the Value to be Inserted :";
        cin>>val;
    if(root==NULL)
        root=new Node(val);
    else
      root=insert(root,val); }
    else if(n==2)
      cout<<height(root)<<endl;
    else if(n==3)
      inorder(root); 

cout<<"\nPress 1 to insert, 2 to check height, 3 for Inorder Traversal :";
cin>>n;
}
}