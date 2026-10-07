#include<iostream>
using namespace std;

class Node{
    public:
    Node* next;
    int data;

    Node(int val){
        next =NULL;
        data = val;
    }
};

class Stack{
public:
    Node* top;
    
    Stack(){
        top =NULL;
    }

    void push(int val){
        Node* newNode =new Node(val);
        newNode->next=top;
        top=newNode;
    }
    int pop(){
        if(top==NULL){
            return -1;
        }
        Node*temp = top;
        int popped = temp->data;
        top= top->next;
        delete temp;
        return popped;

    }
    bool isEmpty(){
        return top==NULL;
    }
};

class myQueue{
    public:
    Stack incoming;
    Stack outcoming;
    void enqueue(int val){
        incoming.push(val);
    }

    int dequeue(){
        if(outcoming.isEmpty()){
        while(incoming.top !=NULL){
            int popped = incoming.pop();
            outcoming.push(popped);
        }
    }
    
    return outcoming.pop();
    }



};

int main(){
    myQueue q;
    cout<<"Enqueue: 1-2-3-4"<<endl;
    cout<<"Dequeue items: "<<endl;
q.enqueue(1);
q.enqueue(2);
cout<<q.dequeue()<<endl ;
q.enqueue(3);
cout<<q.dequeue()<<endl; 
q.enqueue(4);
cout<<q.dequeue()<<endl;


    return 0;
}