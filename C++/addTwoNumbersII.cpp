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
private:
    ListNode* reverse(ListNode* l1) {
        ListNode* reversed = new ListNode(l1->val);
        while (l1->next) {
            l1 = l1->next;
            ListNode* tmp = new ListNode(l1->val);
            tmp->next = reversed;
            reversed = tmp;
        }
        return reversed;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        int carry = 0, sum;
        ListNode* ans = new ListNode();
        ListNode* ansHead = ans;
        while (l1 || l2 || carry) {
            sum = 0;
            sum += carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            ListNode *digit = new ListNode(sum % 10);
            ans->next = digit;
            ans = ans->next;
            carry = sum/10;
        }
        
        ansHead = reverse(ansHead->next);
        return ansHead;
    }
};
