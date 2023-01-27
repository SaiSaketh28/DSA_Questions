// link: https://leetcode.com/problems/insert-into-a-binary-search-tree/
// Approach: 1. Finding the exact position to insert node
// 2. Now inserting the node;
// Time Complexity : O(H) -- Height

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
        {
            return new TreeNode(val);
        }
        TreeNode* temp = root;
        while(temp)
        {
          if(temp->val > val)
          {   if(temp->left == NULL)
              {
                  temp->left = new TreeNode(val);
              }
              temp = temp->left;
          }
          else
          {   if(temp->right == NULL)
              {
                  temp->right = new TreeNode(val);
              }
              temp = temp->right;
          }
          if(temp->val == val)
          {
              break;
          }
        }
        return root;
    }
};