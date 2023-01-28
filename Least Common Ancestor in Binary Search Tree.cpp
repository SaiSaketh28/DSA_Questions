// Link:https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
//My Approach: 
/* 1. Maintain two queues and push the nodes which comen in both the path paths until we reach p and q.
   2. Now run a loop and check the front nodes of two queues if they are same then update the common node.
   3. Continue this process until qny one of queue gets empty.
   4. Time Complexity: Average case: O(3LogN) :: Worst case: O(N)
   5. H1 - Height of p node.
   6. H2 - Height of q node.
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        {
            return NULL;
        }
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,int>>map;
        q.push(root,{0,0});
        while(!q.empty())
        {
            auto* temp = q.front();
            q.pop();
            auto* node= temp.first;
            int row = temp.second.first;
            int column = temp.second.second;
            map[temp->val][row].insert(column);
            if(root->left) q.push({root->left,{row+1,column-1}});
            if(root->right) q.push({root->right,{row+1,column+1}});
        }
        auto it1 = map.find(p->val);
        auto it2 = map.find(q->val);
        if(it1->second->second == it2->second->second)
        {
            if(it1->second->first<it2->second->first)
            {
                return p;
            }
            else
            {
                return q;
            }
        }
        
    }
};

// Optimised Solution:
// Time Complexity: O(logN)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root->val>p->val && root->val>q->val) return lowestCommonAncestor(root->left,p,q);
        if(root->val<p->val && root->val<q->val) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};