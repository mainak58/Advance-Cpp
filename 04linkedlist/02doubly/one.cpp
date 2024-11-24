#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int passData){
        this->data = passData;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "Free memory " << value << endl;
    }
};

void printValue(Node* head){
        Node* temp = head;
        while (temp != NULL)
        {
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

    void insert_at_beg(Node* &head , Node* &tail , int i){

        if (head == NULL){
            Node* temp = new Node(i);
            head = temp;
            tail = temp;
        }
        else{
            Node* temp = new Node(i);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

void insert_at_end(Node* &tail ,Node* &head , int i){

        if(tail == NULL){
            Node* temp = new Node(i);
            tail = temp;
        }
        else{
            Node* temp = new Node(i) ;
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }

}

void insert_at_position(Node* &head , Node* &tail , int position , int i){
    if(position == 1){
            insert_at_beg(head, tail, i);
            return;
    }

    Node* temp = head;
    int cnt = 1;
    while( cnt < position - 1){
            temp = temp->next;
            cnt++;
    }
        
        if(temp == NULL){
            insert_at_end(tail, head , i);
        }

        Node* nodeToPush = new Node(i);
        nodeToPush->next = temp->next;
        temp->next->prev = nodeToPush; 
        temp->next = nodeToPush;
        nodeToPush->prev = temp;
}

void deleteNode(Node* &head , int position){
    if(position == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
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

        curr->next = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    printValue(head);

    insert_at_beg(head, tail, 8);
    printValue(head);

    insert_at_end(tail ,head, 11);
    printValue(head);

    insert_at_position(head, tail, 2 , 9);
    printValue(head);

    insert_at_position(head, tail, 3 , 9);
    printValue(head);

    // deleteNode(head , 1);
    // printValue(head);

    // freeMemory(head);
    return 0;
}