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
    // Use DFS inorder traversal to store tree objects onto a vector in order of ascending value
    void inorder(TreeNode *root, vector<TreeNode *> &v)
    {
        if (root == nullptr)
            return;

        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }

    // Build balanced BST from the array of inorder TreeNodes
    TreeNode *balance(int start, int end, vector<TreeNode *> &v)
    {
        if (start > end)
        {
            return nullptr;
        }

        int mid = start + (end - start) / 2;
        // Build current node
        v[mid]->left = balance(start, mid - 1, v);
        v[mid]->right = balance(mid + 1, end, v);
        return v[mid];
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        vector<TreeNode *> v;
        inorder(root, v); // inorder is sorted
        TreeNode *newRoot = balance(0, v.size() - 1, v);
        return newRoot;
    }
};