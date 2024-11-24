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

void printValue(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void insert_at_first(Node* &head, Node* &tail , int i){
        
    if(head == NULL){
        Node* temp = new Node(i);
        head = temp;
        tail = temp;
        tail->next = temp;
        return;
    }
    Node* temp = new Node(i);
    temp->next = head;
    tail->next = temp;
    head = temp;
}

void insert_at_end(Node* &tail ,Node* &head, int i){
    if(tail == NULL){
        Node* temp = new Node(i);
        head = temp;
        tail = temp;
        tail->next = head;
    }
    Node* temp = new Node(i);
    tail->next = temp;
    temp->next = head;
    tail = temp;
}

void insert_at_position(Node* &head, Node* &tail , int position , int i){
    if(position == 1){
        insert_at_first(head, tail, i);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt ++;
    }
    
    if (temp->next == head) {
        // Insert at the end if position is out of bounds
        insert_at_end(tail, head, i);
        return;
    }

    Node* nodeToPush = new Node(i);
    nodeToPush->next = temp->next;
    temp->next = nodeToPush;

}

void delete_memory(Node* &head , int i){

    if(head == NULL){
        cout << "list is empty " << endl;
    }
    else{
        Node* prev = head;
        Node* curr = prev->next;

        while(curr->data != i){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if(head == curr){
            head = prev;
        }
        curr->next = NULL;
        delete curr;
    }

}
void freeMemory(Node*& head) {
    if (head == NULL) {
        return;
    }

    Node* temp = head;
    do {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    } while (temp != head);

    head = NULL;
}


int main(){

    Node* head = NULL;
    Node* tail = NULL;
    printValue(head);

    insert_at_first(head ,tail , 8);
    printValue(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    insert_at_end(tail ,head , 11);
    printValue(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    insert_at_position(head , tail , 1 , 9);
    printValue(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    insert_at_position(head , tail , 4 , 9);
    printValue(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    insert_at_position(head , tail , 5 , 10);
    printValue(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    delete_memory(head , 8);
    printValue(head);

    freeMemory(head);
    return 0;
}