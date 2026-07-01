class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;

        // If value < low, discard left subtree
        if (root->val < low)
            return trimBST(root->right, low, high);

        // If value > high, discard right subtree
        if (root->val > high)
            return trimBST(root->left, low, high);

        // Otherwise, recursively fix both sides
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};