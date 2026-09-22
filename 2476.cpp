class Solution {
private:
    void inorder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> nums;
        inorder(root, nums);

        vector<vector<int>> ans;
        for (int q : queries) {
            auto it = lower_bound(nums.begin(), nums.end(), q);
            
            int max_val = -1;
            int min_val = -1;

            if (it != nums.end()) {
                max_val = *it;
            }

            if (it != nums.end() && *it == q) {
                min_val = *it;
            } else if (it != nums.begin()) {
                min_val = *prev(it);
            }

            ans.push_back({min_val, max_val});
        }

        return ans;
    }
};