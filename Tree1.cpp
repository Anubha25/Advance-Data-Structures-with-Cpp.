//Basic Tree implementation with Nodes;
#include<queue>
#include<iostream>
using namespace std;
class Node
{
public:
Node * left;
int val;
Node * right;
Node(int n)
{   this->val=n;
    this->left=this->right=NULL;
}
~Node()
{cout<<this->val<<" deleted \n";}
};
class tree
{
    public:
    Node *root;
    tree()
    {
        this->root=NULL;
    }
    ~tree()
    {cout<<"Tree deleted \n";}
};
void preorder(Node *root)
{  if(root==NULL)
       return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node * root)
{
    if(root==NULL)
     return ;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int find_size(Node *root)
{
   if(root==NULL)
     return 0;
    return 1 +find_size(root->left)+find_size(root->right);
}
int find_sum(Node *root)
{
   if(root==NULL)
     return 0;
    return root->val +find_sum(root->left)+find_sum(root->right);
}
int find_max(Node *root)
{
    if (root==NULL)
       return 0;
    int a= find_max(root->left),b = find_max(root->right);
    if(a>b and a >root->val)
        return a;
    if(b>a and b> root->val)
        return b;
    return root->val;
}
int max(int a,int b)
{ if(a>b)
    return a;
  return b;
}
int height(Node * root)
{
    if(root==NULL)
        return 0;
    return 1+ max(height(root->left),height(root->right));
}
bool isBalanced(Node* root) {
    if(root==NULL)
      return true;
    bool left=isBalanced(root->left);
    bool right=isBalanced(root->right);
    if(left and right)
    {  cout<<"current root :"<<root->val<<endl;
      int l = height(root->left);
      int r = height(root->right);
      if(l-r<-1 or l-r>1)
         return false;
    return true;
    }
    return false;
    }
void helper(Node* root, int &dia)
{ if(root==NULL)
      return ;
    int h= height(root->left) + height(root->right);
    if(h>dia)        
       dia=h; 
    helper(root->left,dia);
    helper(root->right,dia);
}
int diameter(Node* root) {
        int dia=0;
        helper(root,dia);
        return dia;
    }
void elememntsoflevel(Node *root,int current,int req)
{ if(root==NULL)
    return ;
  if(current==req)
   { cout<<root->val<<' '; return ;}
  elememntsoflevel(root->left,current+1,req);
  elememntsoflevel(root->right,current+1,req);
}
void levelorder(Node *root)
{
    queue<Node *>q1;
    q1.push(root);q1.push(NULL);
    while(!q1.empty())
    {
        Node *tmp=q1.front();
        q1.pop();
        if(tmp==NULL and !q1.empty())
        { 
            q1.push(NULL); cout<<endl;}
        else
         {
            cout<<tmp->val<<" ";
            if(tmp->left!=NULL)
               q1.push(tmp->left);
            if(tmp->right!=NULL)
               q1.push(tmp->right);
         } 
        
    }
}
int main()
{   int n;
    Node *a= new Node(10);               //          10
    a->left = new Node(5);              //    5              20
    a->right=new Node(20);            //  3       7      15     25
    a->left->left = new Node(3);     //        50   70
    a->left->right = new Node(7);   //  80
    a->left->right->left = new Node(50);
    a->left->right->right = new Node(70);
    a->left->right->left = new Node(80);
    a->left->right->right->right = new Node(9); 
    a->left->left->right = new Node(4);
    a->right->left = new Node(15);
    a->right->right = new Node(25);
    inorder(a);
    cout<<"size of tree : "<<find_size(a)<<endl;
    cout<<"sum of tree : "<<find_sum(a)<<endl;
    cout<<"Maximum element :"<<find_max(a)<<endl;
    cout<<"Height of tree :"<<height(a)<<endl;
    cout<<"Balanced tree :"<<isBalanced(a)<<endl;
    cout<<"diameter of tree :"<<diameter(a)<<endl;
    cout<<"Enter the level you want to print :";
    cin>>n;
    cout<<endl;elememntsoflevel(a,0,n);
    levelorder(a);
}
