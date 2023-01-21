2. Find Intersection Point of Y linked List: https://leetcode.com/problems/intersection-of-two-linked-lists/
	Optimal Solution:

		class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* d1 = headA;
        ListNode* d2 = headB;
        ListNode* r1 = headA;
        ListNode* r2 = headB;
        while(d1 && d2)
        {
            d1 = d1->next;
            d2 = d2->next;
        }
        if(d1 == NULL)
        {
            while(d2)
            {
                r2 = r2->next;
                d2 = d2->next;
            }
        }
        else
        {
            while(d1)
            {
                r1 = r1->next;
                d1 = d1->next;
            }
        }
        while(r1 && r2)
        {
            if(r1 == r2)
            {
                return r1;
            }
            r1 = r1->next;
            r2 = r2->next;
        }
        return NULL;
    }
};

b. It can also be done by hashing address of one list and matching them with other.
