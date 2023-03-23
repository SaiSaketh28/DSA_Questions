// leetcode link: https://leetcode.com/problems/linked-list-cycle/description
// Approach1: Using Hashing uysing maps
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,int>map;
        ListNode* temp = head;
        if(temp == NULL)
        {
            return false;
        }
        while(1 && temp != NULL)
        {
            if(map.find(temp) == map.end())
            {
                map.insert({temp,temp->val});
            }
            else if(temp == NULL)
            {
                break;
            }
            else
            {   return true;
                break;
            }
            temp = temp->next;
        }
        return false;
    }
};

// Approach2:
// slow and fast approach
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
        {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(1 && slow != NULL && fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                return true;
            }
            else if(fast == NULL || slow == NULL)
            {
                return false;
            }
        }
        return false;
    }
};