#include<iostream>
using namespace std;

class Stack{
	int* arr;
	int size;
	int top;
	
	public:
		Stack(int s){
			size = s;
			arr = new int[size];
			top = -1;
		}
		
		void push(int x){
			if(top == size-1){
				cout<<"Stack is Full"<<endl;
				return;
			}
			arr[++top] = x;
		}
		
		void pop(){
		    if(top == -1){
		    	cout<<"Stack is empty"<<endl;
		    	return;
			}
			cout<<"\nPopped element: "<<arr[top]<<endl;
			top--;
		}
		
		int getTop(){
			cout<<"\nTop: ";
			return arr[top];
		}
		void display(){
			cout<<endl<<endl<<"Stack:\n\n";
			for(int i = top; i>=0 ; i--){
				cout<<" |  "<<arr[i]<<"  |"<<endl;
				cout<<"  ______ "<<endl;
			}
		}
};

int main(){
	Stack s(8);
	s.push(12);
	cout<<s.getTop();
	s.push(25);
	cout<<s.getTop();
	s.push(17);
	cout<<s.getTop();
	s.push(31);
	cout<<s.getTop();
	s.push(44);
	cout<<s.getTop();
	s.push(19);
	cout<<s.getTop();
	cout<<endl<<"Popping thrice: \n";
	s.pop();
	cout<<s.getTop();
	s.pop();
	cout<<s.getTop();
	s.pop();
	cout<<s.getTop();
		
	s.push(52);
	cout<<s.getTop();
	cout<<endl<<"Popping twice: \n";
	s.pop();
	cout<<s.getTop();
	s.pop();
	cout<<s.getTop();

s.display();
	
	return 0;
}



