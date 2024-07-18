#include<iostream>
using namespace std;
class bus
{
    public:
    string name;
    int cost;
    bus()
    {
        name="local";
        cost=10;
    }
    bus(string str,int a)
    { name=str; cost=a; }
    bus(bus &f)
    {
     name= f.name;
     cost=f.cost;
    }

};
int main()
{ 
    bus fresh1;
    bus fresh2("Volvo",300);
    bus *fresh3= new bus(fresh2);
    cout<<fresh3->name<<fresh3->cost;
    //bus *fresh4=new bus(fresh3);
}