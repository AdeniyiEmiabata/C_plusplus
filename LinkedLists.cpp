#include <iostream>
#include <algorithm>
#include <vector>

// Define struct of linked list
struct Node{
    int value;
    Node* next;
};


// Function to Insert new element at end of linked list
void Insert_Element(Node*& head, int val){

    // new node to insert
    Node* insert = new Node();
    insert -> value = val;
    insert -> next = nullptr;

    if(head == nullptr){
        head = insert;
        return;
    }

    Node* temp = head;
    //temp = head;
    // go to end of linked list
    while(temp->next != nullptr){
        temp = temp-> next;
    }
    temp -> next = insert;
    
}

Node* InsertAtFront(Node*& head, int val){
    if (head == nullptr){
        head ->next = nullptr;
        head -> value = val;
        return head;
    }
    Node* new_head = new Node();
    new_head -> next = head;
    new_head -> value = val;

    return new_head;
}

void InsertSomewhere(Node*&head, int val, int n){    // n is how many nodes after the head

    if (head == nullptr){
        head ->next = nullptr;
        head -> value = val;
        return;
    }

    Node* new_node = new Node();
    new_node -> value = val;

    int count = 0;

    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        if(count == n){
            break;
        }
        else{
            count++;
            prev = temp;
            temp = temp -> next;
        }        
    }

    new_node -> next = temp;
    prev -> next = new_node;
    //while(head!= nu)

}

void DisplayElements(Node *head){
    Node* temp = new Node();
    temp = head;
    // traverse through all of the list
    while (temp != nullptr){
        std::cout << temp->value << "\n";
        temp = temp -> next; 
    }
}

Node* ReverseElements(Node*& head){
    Node* curr = head;
    Node* prev = nullptr;
    Node* next_node = nullptr;

    while(curr != nullptr){
        next_node = curr-> next;
        curr->next = prev;

        prev = curr;
        curr = next_node;
    }
    return prev;
}

int main(){
    // std::cout << "yes";
    //define a node
    Node* head = new Node();
    head -> value = 23;
    head -> next = nullptr;

    Insert_Element(head, 25);
    Insert_Element(head, 35);
    Insert_Element(head, 45);
    Insert_Element(head, 55);
    Insert_Element(head, 65);
    head = InsertAtFront(head, 199);
    InsertSomewhere(head, 73, 2);
    std::cout << "OLD LIST: \n"; 
    DisplayElements(head);
    head = ReverseElements(head);
    std::cout << "\n\n\n";
    std::cout << "NEW LIST: \n";
    DisplayElements(head);
}

