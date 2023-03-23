// Leetcode Link: https://leetcode.com/problems/sort-list/description
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL)
        {
            return NULL;
        }
        vector<int>vec;
        ListNode* temp = head;
        while(temp != NULL)
        {
            vec.push_back(temp->val);
            temp = temp->next;
        }
        sort(vec.begin(),vec.end());
        int i=0;
        ListNode* dum = head;
        while(dum != NULL)
        {
            dum->val = vec[i];
            i++;
            dum = dum->next;
        }
        return head;
    }
};