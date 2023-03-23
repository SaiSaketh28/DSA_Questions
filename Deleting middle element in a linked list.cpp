// Leetcode link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description
// Slow and fast approach
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = NULL;
        while(slow && fast && fast->next)
        {   temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(temp == NULL)
        {
            return NULL;
        }
        temp->next = temp->next->next;
        return head;
    }
};