/****************************************************************

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
        

*****************************************************************/



Node* reverseLinkedList(Node* head) {
    // Base case: If the list is empty or has only one node, return head
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Recursive case: Reverse the rest of the list
    Node* newHead = reverseLinkedList(head->next);

    // Adjust the pointers
    head->next->next = head; // Make the next node point to the current node
    head->next = NULL;       // Set the current node's next pointer to NULL

    return newHead; // Return the new head of the reversed list
}
