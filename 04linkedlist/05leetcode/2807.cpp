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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL & curr-> next != NULL){
            prev = curr;
            curr = curr-> next;
            int ans = __gcd(prev-> val , curr->val);

            ListNode* newNodeToPush = new ListNode(ans);
            newNodeToPush-> next = curr;
            prev-> next = newNodeToPush;
        }
        return head;
    }
};