class Solution {
private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev;
            }
            second = root;
        }
        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};