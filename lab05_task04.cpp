#include<iostream>
using namespace std;

#define CAPACITY 6

class CircularQueue{
    int arr[CAPACITY];
    int size;
    int front;
    int rear;

    public:
    CircularQueue(){
        front = rear = -1;
        size = 0;
    }
    bool isempty(){
        if(front == -1){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(rear+1 == front)
        return true;

        return false;
    }

    void enqueue(int val){
        if(isFull()){
            return;
        }
        if(front == -1){
            front=0;
        }
        rear = (rear+1)%CAPACITY;
        arr[rear]= val;
        
    }
    void dequeue(){
        if(isempty()){
            return;
        }
        if(front==rear)
        rear=front=-1;
        else
        front = (front+1)%CAPACITY;
    }

    void display(){
        cout<<"FRONT -- ";
        for(int i = front;  ; i=(i+1)%CAPACITY){
            cout<<arr[i]<<" -- ";
            if(rear == i){
                break;
            }
    }
    cout<<"REAR"<<endl;
}
};

int main(){
    CircularQueue q;
    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.enqueue(104);
    q.enqueue(105);
    q.enqueue(106);

    //3 passenger boarded
    q.dequeue();
    q.dequeue();
    q.dequeue();

    //3 arrive at gate
    q.enqueue(107);
    q.enqueue(108);
    q.enqueue(109);

    //2 boarded
    q.dequeue();
    q.dequeue();

    //passenger 110
    q.enqueue(110);

    //1 boarded
    q.dequeue();

    //2 came on gate
    q.enqueue(111);
    q.enqueue(112);
    q.display();


    return 0;
}