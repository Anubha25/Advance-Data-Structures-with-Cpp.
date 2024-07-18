//Basic Object oriented Programming and constructors
#include<iostream>
using namespace std;
class train
{
  public:
  string name;
  int cost;
  train() //default constructur (no arguments passed )
  {
    name="JAT Express";
     cost=90;
  }  
  train(string a,int b) //parameterised constructor 
  {
     name=a;
     cost=b;
  }
  train(train &f)
    { name = f.name+"fast ";
     cost = f.cost-200; }
};

int main()
{
    train locall;
    train *fast=new train("Shatabdi",850);
   // cout<<locall->name<<" cost: "<<locall->cost<<endl;
    cout<<fast->name<<" cost "<<fast->cost<<endl;
    train random(locall);
    cout<<random.name<<" cost"<<random.cost<<endl;
    train *fresh=new train(random);
    cout<<fresh->name<<fresh->cost;
}