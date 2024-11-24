#include <iostream>

using namespace std;

class Node {

    public: 
    int data;
    Node* next;

    Node(int passData){
        this->data = passData;
        this->next = NULL;
    }
};

void printData(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void freeMemory(Node*& head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void insert_at_end(Node* &tail , int i){
    
    Node* temp = new Node(i);
    tail->next = temp;
    tail = temp;
}

int main(){

    Node* head = new Node(10);  
    Node* tail = head;          

    printData(head);     

    insert_at_end(tail, 12);
    printData(head);            

    insert_at_end(tail, 15);
    printData(head);            

    freeMemory(head);          
    return 0;
}
