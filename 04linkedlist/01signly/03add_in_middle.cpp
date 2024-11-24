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


void insert_in_middle(Node* &middle ,int postition, int i){
    
    Node* temp = middle;
    int cnt = 1;

    while(cnt < postition - 1){
        temp = temp->next;
        cnt++;
    }

        Node* nodeToInsert = new Node(i);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
}

int main(){

    Node* head = new Node(10);  
    Node* tail = head;          

    printData(head); 

    insert_at_end(tail, 12);
    printData(head);            

    insert_at_end(tail, 15);
    printData(head);

    insert_in_middle(head, 3, 18);
    printData(head);
    freeMemory(head);          
    return 0;
}
