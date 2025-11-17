/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

/*
Using BFS
Order of find is : root -> left -> right; then left's left->right and right's
left->right So for each level, we use queue to serve this order
*/
class Solution {
  vector<vector<int>> bfs;

public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr)
      return bfs;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      vector<int> buffer;
      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();
        if (node->left != nullptr)
          q.push(node->left);
        if (node->right != nullptr)
          q.push(node->right);
        buffer.push_back(node->val);
      }
      bfs.push_back(buffer);
    }
    return bfs;
  }
};