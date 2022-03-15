#include <iostream>
using namespace std;
#include <string>

class Node {
    public:
        int data;
        Node *previous;
    
        Node(int in_data, Node *in_previous){
            data = in_data;
            previous = in_previous;
        };
};

class Stack {
    private:
        Node *head = NULL;
        int size = 0;
        
    public:
    
    int isEmpty()
    {
        return head == NULL;
    }
    
    int peek(void){
        return head->data;
    }
    
    void display(void){
        Node* pNode;
        pNode = head;
        cout<<"display: ";
        while (pNode){
            cout<<pNode->data<<" ";
            pNode = pNode->previous;
        }
        cout<<endl;
    }
        
    void push(int data){                
        Node* new_node = new Node(data, head);
        head = new_node;
        
        size += 1;
    }
    
    void pop(void){
        Node* temp;
        
        if(!isEmpty()){
            temp = head;
            head = head->previous;
            
            free(temp);
            
            size -=1;
        }
    }
};
    
int main ()
{   
    Stack mystack;
    //cout<<"peek: " <<mystack.peek()<<endl;
    
    if(!mystack.isEmpty()){
        cout<<"peek: " <<mystack.peek()<<endl;
    }
    else{
        cout<<"stack empty"<<endl;
    }
    
    mystack.display();
    
    for(int i = 1; i <= 5; i++){
        mystack.push(i); 
        
        if(!mystack.isEmpty()){
            cout<<"peek: " <<mystack.peek()<<endl;
        }
        else{
            cout<<"stack empty"<<endl;
        }
        mystack.display();
    }
    
    while(!mystack.isEmpty()){
        if(!mystack.isEmpty()){
            cout<<"peek: " <<mystack.peek()<<endl;
        }
        else{
            cout<<"stack empty"<<endl;
        }
        
        mystack.display();
        
        mystack.pop();
    }   

  return 0;
}