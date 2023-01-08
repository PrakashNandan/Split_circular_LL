#include <iostream>

using namespace std;
class Node{
    
    public:
    int data;
    Node* next;
    
    // constructor
    Node(int d){
        
        this->data=d;
        this->next=NULL;
    }
    
    // Destructor
    
    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
            
        }
        
        cout<<"memory is free with data "<<value<<endl;
    }
    
};

void insertNode(Node* &tail, int element, int d){
    
    //empty list
    if(tail==NULL){
        
        Node* temp1=new Node(d);
        tail = temp1;
        temp1->next=temp1;
    }
    
    else{
        
        // assuming that the element is present in the list
        
        Node* temp=tail;
        
        while(temp->data!=element){
            temp=temp->next;
        }
        
        Node* curr = temp;
        
        Node* NodeToinsert = new Node(d);
        NodeToinsert->next = curr->next;
        curr->next=NodeToinsert;
        
    }
 
}

void deleteNode(Node* &tail, int value){
    
    // empty list
    if(tail==NULL){
        cout<<"list is empty "<<endl;
    }
    
    else{
        
        Node* prev=tail;
        Node* curr= prev->next;
        
        while(curr->data!= value){
            prev=curr;
            curr=curr->next;
        }
        
        prev->next = curr->next;
        
        if(curr==prev){
            tail=NULL;
        }
        
        else if(tail==curr){
            tail=prev;
        }
        
        curr->next=NULL;
        delete curr;
    }
    
}

void print(Node* tail){
    Node* temp = tail;
    
    if(tail==NULL){
        cout<<"the list is already empty"<<endl;
        return ;
    }
    
    do{
        
        cout<<temp->data<<" ";
        temp=temp->next;
        
        
    } while(temp!=tail);
    
    cout<<endl;
    
}


void splitCircularLL(Node* head){
    
    
    // if(head==NULL || head->next == NULL){
        
    //     return head;
        
    // }
    
    int cnt = 1;
    Node* temp = head;
    
    while(temp->next != head){
        cnt++;
        temp=temp->next;
    }
    
    int mid = (cnt+1)/2;
    
    Node* curr=  head;
    Node* forward = head->next;
    int i=1;
    
    while(i<mid){
        curr=forward;
        forward = forward->next;
        i++;
        
    }
    
    curr->next = head;
    Node* head2 = forward;
    
    while(forward->next != head){
        forward= forward->next;
    }
    
    forward->next = head2;
    
    print(head);
    cout<<endl;
    print(head2);
 
}
void splitCLL(Node* head){
    
    Node* slow= head;
    Node* fast = head;
    
    while(fast->next != head && fast->next->next !=head){
        
        fast=fast->next->next;
        slow=slow->next;
     
    }
    
    if(fast->next->next==head){
        fast= fast->next;
    }
    
    Node* head2 = slow->next;
    
    slow->next=head;
    fast->next=head2;
    
    
    print(head);
    cout<<endl;
    print(head2);
    
}

int main()
{
    Node* tail = NULL;
    insertNode(tail,5,2);
    print(tail);
    
   
    insertNode(tail,2,5);
    print(tail);
     
    insertNode(tail,5,9);
    print(tail);
    
    insertNode(tail,9,14);
    print(tail);
    
    insertNode(tail,5,7);
    print(tail);
    
    // insertNode(tail,2,17);
    // print(tail);
    
    // splitCircularLL(tail);
    
    splitCLL(tail);
    
    
    // deleteNode(tail, 5);
    // print(tail);


    return 0;
}