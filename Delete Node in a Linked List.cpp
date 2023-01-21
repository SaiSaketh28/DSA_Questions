1. // https://leetcode.com/problems/delete-node-in-a-linked-list/

Two Methods:
	1. Iterative approach(O(n)):

		class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode* prev = node;
        ListNode* current = node->next;
        while(current->next != NULL)
        {
            prev->val = current->val;
            prev = prev->next;
            current = current->next;
        }
         prev->val = current->val;
        prev->next = NULL;
        delete current;
    }
};


	2. Single Step Approach:
		
		class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};