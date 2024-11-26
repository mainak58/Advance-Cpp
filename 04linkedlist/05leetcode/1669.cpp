// recurssion

class Solution {
private:
    void addToList(ListNode* list1, ListNode* list2, int a, int count = 0) {
        if (count == a - 1) {
            ListNode* remainingList = list1->next;
            list1->next = list2;
            
            // Traverse to end of list2
            while (list2->next) {
                list2 = list2->next;
            }
            list2->next = remainingList;
            return;
        }
        addToList(list1->next, list2, a, count + 1);
    }
    
    void removeNodes(ListNode* list1, int a, int b, int count = 0) {
        if (count == a - 1) {
            ListNode* curr = list1->next;
            for (int i = a; i <= b; i++) {
                ListNode* temp = curr;
                curr = curr->next;
                delete temp;
            }
            list1->next = curr;
            return;
        }
        removeNodes(list1->next, a, b, count + 1);
    }

public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        removeNodes(list1, a, b);
        addToList(list1, list2, a);
        return list1;
    }
};
  



// linerar 

//   class Solution {
// private:
//     void addToList(ListNode* list1, ListNode* list2, int a) {
//         ListNode* prev = list1;
        
//         // Move to position a-1
//         for(int i = 0; i < a-1; i++) {
//             prev = prev->next;
//         }
        
//         // Find end of list2
//         ListNode* list2End = list2;
//         while(list2End->next != nullptr) {
//             list2End = list2End->next;
//         }
        
//         // Connect list2End to remaining part of list1
//         list2End->next = prev->next;
//         // Connect first part of list1 to start of list2
//         prev->next = list2;
//     }
    
//     void removeNodes(ListNode* list1, int a, int b) {
//         ListNode* prev = list1;
        
//         // Move to position a-1
//         for(int i = 0; i < a-1; i++) {
//             prev = prev->next;
//         }
        
//         // Store the node to connect to later
//         ListNode* connect = prev;
        
//         // Move to position b+1
//         ListNode* curr = prev->next;
//         for(int i = a; i <= b; i++) {
//             ListNode* temp = curr;
//             curr = curr->next;
//             delete temp;
//         }
        
//         connect->next = curr;
//     }

// public:
//     ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
//         removeNodes(list1, a, b);
//         addToList(list1, list2, a);
//         return list1;
//     }
// };
