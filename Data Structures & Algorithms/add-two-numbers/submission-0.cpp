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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummyNode = new ListNode(0);
        ListNode* current = dummyNode;
        int carry = 0;

        while(l1 || l2 || carry != 0){

            int val1 = 0;
            if(l1 != NULL){

                val1 += l1->val;
                l1 = l1->next;
            }

            int val2 = 0;
            if(l2 != NULL){

                val2 += l2->val;
                l2 = l2->next;
            }

            int sum = val1 + val2 + carry;
            int unitDigit = sum % 10;
            carry = sum / 10;

            current->next = new ListNode(unitDigit);
            current = current->next;
        }

        ListNode* ans = dummyNode->next;
        delete dummyNode;
        return ans;
    }
};
