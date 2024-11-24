#include<iostream>

using namespace std;

    class Node {

        public:
        int data;
        Node* next;

        Node(int passValue){
            this->data = passValue;
            this->next = NULL;
        }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "Free memory" << value << endl;
    }
    };

void printValue(Node* head){
        Node* temp = head;
        while(temp != NULL){
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

void insert_at_beg(Node* &head , int i){
    Node* temp = new Node(i);
    temp->next = head;
    head = temp;
}

void insert_at_end(Node* &tail , int i){
    Node*temp = new Node(i);
    tail->next = temp;
    tail = temp;
}

void insert_at_middle(Node* &head , int position , int i){
    Node* temp = head;
    int cnt = 1;

    while(cnt < position - 1){
        temp = temp->next;
        cnt++;
    }

    Node* nodeToInsert = new Node(i);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head , int position){
    if (position == 1)
    {   
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main(){

    Node* node1 = new Node(18);

    Node* head = node1;
    Node*tail = head;
    printValue(head);

    insert_at_beg(head, 17);
    printValue(head);

    insert_at_beg(head, 16);
    printValue(head);

    insert_at_beg(head, 15);
    printValue(head);

    insert_at_end(tail , 19);
    printValue(head);

    insert_at_middle(head, 3 , 17);
    printValue(head);

    deleteNode(head , 1);
    printValue(head);

    freeMemory(head); // Properly deallocating memory
    return 0;
}