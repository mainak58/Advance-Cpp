#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int passData) {
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

void insertAtHead(Node*& head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void freeMemory(Node*& head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* node1 = new Node(10);

    Node* head = node1;
    printData(head);

    insertAtHead(head, 12);
    printData(head);

    insertAtHead(head, 15);
    printData(head);

    freeMemory(head); // Properly deallocating memory

    return 0;
}
