//circular queue from array 
#include<iostream>
using namespace std;
class MyCircularQueue {
    int *arr;
    int front;
    int rear;
    int totalsize;
public:
    MyCircularQueue(int k) {
        this->arr= new int[k];
        front=rear=-1;
        totalsize=k;
    }  
    bool enQueue(int value) {
        if(front==0 && rear==totalsize-1)
           return false;
        if(rear==front-1)
           return false;
        if(front==-1)
        {  front=rear=0;
          arr[front]=value;return true; }
        if(rear==totalsize-1 )
          rear=-1;
        arr[++rear]=value;
        return true;
    }
    
    bool deQueue() {
        if(rear==-1)
            return false;
        if(front==rear)
        {front=rear=-1; return true;}
        if(front==totalsize-1)
            front=-1;
        front++;
        return true;
    }
    int Front() {
        if(front!=-1)
          return arr[front];
        return front;
    }
    
    int Rear() {
        if(rear!=-1)
            return arr[rear];
        return rear;
    }
    
    bool isEmpty() {
        if(front==-1)
        return true;
    return false;
    }
    
    bool isFull() {
        if((front==0 && rear==totalsize-1) or (rear+1==front))
            return true;
        return false;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */