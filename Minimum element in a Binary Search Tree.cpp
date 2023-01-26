// Function to find the minimum element in the given BST.
// minimum element is always at the left most leaf node // left most node
// Time Complexity: O(H) -- Height of the least value node
int minValue(Node* root) {
    if(root == NULL)
    {
        return -1;
    }
    if(root && root->left == NULL && root->right == NULL || root && root->right && root->left == NULL)
    {
        return root->data;
    }
    root=root->left;
    return minValue(root);
}