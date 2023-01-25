// Boundary Traversal:
/*
1. Traverse left side of tree until you reach leaf node and then push back data into vector
2. Important in left traversal if node->left is null in any situation travel to root->rights left tree
3. Traverse leaf nodes and push data value left->to->right
4. Now traverse right path in reverse from leaf node to root->right if right->right doent exist then travel to right->left->right
and push back the value into vector
5. we get the required output
*/
// Code
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>arr;
        left_traversal(arr,root);
        middle_traversal(arr,root);
        right_traversal(arr,root->right);
        return arr;
    }
    void left_traversal(vector<int>&arr,Node *root)
    {
        if(root  && (root->left == NULL && root->right == NULL))
        {
            return;
        }
        if(root == NULL)
        {
            return;
        }
        if(root->left == NULL && root->right)
        {
            left_traversal(arr,root->right);
        }
        if(root) arr.push_back(root->data);
        left_traversal(arr,root->left);
        return;
    }
    void right_traversal(vector<int>&arr,Node* root)
    {
        if(root && (root->left == NULL && root->right == NULL))
        {
            return;
        }
        if(root == NULL)
        {
            return;
        }
        if(root->right == NULL&& root->left)
        {
            right_traversal(arr,root->left);
        }
        right_traversal(arr,root->right);
        if(root) arr.push_back(root->data);
        return;
    }
    void middle_traversal(vector<int>&arr,Node *root)
    {
        if(root && root->left == NULL && root->right == NULL)
        {
            arr.push_back(root->data);
        }
        if(root == NULL)
        {
            return;
        }
        middle_traversal(arr,root->left);
        middle_traversal(arr,root->right);
        return;
    }
};
