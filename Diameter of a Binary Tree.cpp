/* we have to find the maximum distance between any two nodes in a tree even if the path doenot pass through root*/
/*My Approach was to calculate individual diameters of left subtree and right subtree and max(height of left + height of right) with max(diameter of left subtree and right subtree)
 I considered height of leaf node to be zero and it is the reason it cost me code to be high*/
// leetcode link :https://leetcode.com/problems/diameter-of-binary-tree/description/
// My code:
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
class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if ((root && (root->left == NULL) && root->right) || (root && root->left && (root->right == NULL)))
        {
            int d1;
            if (root->left)
            {
                d1 = diameterOfBinaryTree(root->left);
            }
            if (root->right)
            {
                d1 = diameterOfBinaryTree(root->right);
            }
            return max(d1, height(root));
        }
        if (root && (root->left == NULL) && (root->right == NULL))
        {
            return 0;
        }
        // if(root && root->left && root->right)
        int d1 = diameterOfBinaryTree(root->left);
        int d2 = diameterOfBinaryTree(root->right);
        int x = height(root->left) + height(root->right) + 2;
        return max(x, max(d1, d2));
    }

    int height(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL && root)
        {
            return 0;
        }
        // if(root == NULL)
        // {
        //     return 0;
        // }
        int h1 = 0, h2 = 0;
        if (root->left != NULL)
        {
            h1 = height(root->left);
        }
        if (root->right != NULL)
        {
            h2 = height(root->right);
        }
        int h = max(h1, h2) + 1;
        return h;
    }
};
// Optimised Solution:

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
class Solution
{
public:
    int maxHeight(TreeNode *root, int &dia)
    {

        // base case -> if leaf node, return height 0.
        if (root == NULL)
        {
            return 0;
        }

        // recursive call for to find max height of each subtree
        int leftHeight = maxHeight(root->left, dia);
        int rightHeight = maxHeight(root->right, dia);

        // if the sum of new max heights greater than already existing diameter
        dia = max(dia, leftHeight + rightHeight);

        // return max height of the subtree + 1 for the root node
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int dia = 0;
        maxHeight(root, dia);
        return dia;
    }
};