/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

// Node *findMiddle(Node *head) {
//     Node *slow = head;
//     Node *fast = head;
    
//     while (fast != NULL && fast->next != NULL) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
    
//     return slow;
// }
Node *findMiddle(Node *head) {
    // First pass: count total nodes
    Node* temp = head;
    int count = 0;
    while(temp != NULL) {
        temp = temp->next;
        count++;
    }
    
    // Calculate middle position
    int middle = count / 2;
    
    // Second pass: traverse to middle
    temp = head;
    for(int i = 0; i < middle; i++) {
        temp = temp->next;
    }
    
    return temp;
}



