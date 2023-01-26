// LeetCode link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
// Approach:
/* 1. First we assign row number and column number to each node by level order traversal;
   2. Pass them into map<map<>> data structre
   3. next we run a loop and puhh back data values with same column 
*/
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>>map;
        if(root == NULL)
        {
            return ans;
        }
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int column = temp.second.second;
            int row = temp.second.first;
            map[column][row].insert(node->val);
            if(node->left) q.push({node->left,{row+1,column-1}});
            if(node->right) q.push({node->right,{row+1,column+1}});
        }
        for(auto p:map)
        {
            vector<int>col;
            for(auto q:p.second)
            {
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};