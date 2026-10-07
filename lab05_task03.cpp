#include<iostream>
using namespace std;

class Node{
    public:
    Node* next;
    string jobname;

    Node(string j){
        jobname = j;
        next = NULL;
    }
};
class Queue{
    public:
    Node* front;
    Node* rear;
    Queue(){
        front = rear = NULL;
    }
    void enqueue(string j){
        Node* newNode = new Node(j);
        if(front ==NULL){
            front =rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    string dequeue(){
        Node* temp = front;
        if(front==NULL){
            cout<<"Queue is empty"<<endl;
            return "-";
        }
    
        string dequeued = temp->jobname;
        if(front==rear){
            rear =NULL;
        }
        front = front->next;
        delete temp;
        

        return dequeued;
    }

    void display(){
        Node* temp =front;
        cout<<"FRONT -- ";
        while(temp!=NULL){
        cout<<temp->jobname<<" --  ";
        temp =temp->next;
        }
        cout<<"REAR"<<endl;
    }
};

class Stack{
public:
    Node* top;

    Stack(){
        top = NULL;
    }

    void push(string w){
        Node* newNode = new Node(w);
        newNode->next = top;
        top = newNode;
    }

    void pop(){
        Node* temp = top;
        top = top->next;
        delete temp;
        temp = NULL;
    }

    bool isempty(){
        if(top==NULL)
        return true;

        return false;
    }

};

void reverseFirstK(Queue &q, int k){
    Stack record;
    for(int i = 0;i<k;i++){
        string temp = q.dequeue();
        record.push(temp);
    }
    Node* t =record.top;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next = q.front;
    q.front = record.top;
}

int main(){
    Queue q;
    q.enqueue("J1");
    q.enqueue("J2");
    q.enqueue("J3");
    q.enqueue("J4");
    q.enqueue("J5");
    q.enqueue("J6");
    q.enqueue("J7");

    q.display();
    reverseFirstK(q,3);
    q.display();

    return 0;
}