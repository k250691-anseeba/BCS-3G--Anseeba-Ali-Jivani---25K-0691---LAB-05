#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
    Node* next;
    string word;

    Node(string w){
        word =w;
        next =NULL;
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

    string pop(){
        Node* temp = top;
        string popped = top->word;
        top = top->next;
        delete temp;
        temp = NULL;
        return popped;
    }

    bool isempty(){
        if(top==NULL)
        return true;

        return false;
    }

    void clear(){
        Node* temp = top;
        while(temp!=NULL){
            top= top->next;
            delete temp;
            temp=top;
        }
    }
};

class TextEditor{
    string document;
    Stack history;
    Stack redoWord;

    void type(string word){
        history.push(word);
        document = document + word + " ";
        redoWord.clear();
    }
    void undo(){
        string poppedword = history.pop();
        redoWord.push(poppedword);
        //remove from document string as well
        int length = poppedword.length() + 1; 
        document.erase(document.length() - length);
    }
    void redo(){
        string poppedword = redoWord.pop();
        history.push(poppedword);
        document = document + poppedword + " ";
    }
    public:
    TextEditor(){
        document = "";
    }
    void executecommand(char c){
        if(c == 'U'){
            if(!history.isempty())
            undo();
        }
        else if (c == 'R'){
            if(!redoWord.isempty())
            redo();
        }
        else if(c == 'T'){
            string word;
            cout<<"Enter a word: ";
            cin>>word;
            type(word);
        }
        
    }

    void print(){
        cout<<"-- DOCUMENT --"<<endl;
        cout<<document<<endl;
    }
};

int main(){
    TextEditor t;
    t.executecommand('T');
    t.executecommand('T');
    t.print();
    t.executecommand('U');
    t.print();
    t.executecommand('R');
    t.print();
    t.executecommand('U');
    t.print();
    t.executecommand('T');
    t.print();

    return 0;
}