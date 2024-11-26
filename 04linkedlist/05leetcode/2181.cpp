/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {

    //     ListNode* dummy = new ListNode(0);
    //     ListNode* tail = dummy;
    //     ListNode* curr = head -> next;

    //     int addValue = 0;

    //     while(curr){
    //         if(curr -> val == 0){
    //         tail -> next  = new ListNode(addValue);
    //         tail = tail-> next;
    //         addValue = 0;
    //         }
    //         else{
    //         addValue += curr -> val;
    //         }
    //         curr = curr -> next;
    //     }  

    //        return dummy -> next;
    // }



    // using recurssion

    if(!head || head -> next == 0) return nullptr;

    ListNode* curr = head -> next;
    int sum = 0 ;

    while(curr && curr -> val != 0){
        sum += curr -> val;
        curr = curr -> next ;
    }

    ListNode* newNode = new ListNode(sum);
    newNode -> next = mergeNodes(curr);
    return newNode;
    }
};