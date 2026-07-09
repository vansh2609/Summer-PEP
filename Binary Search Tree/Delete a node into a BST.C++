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
    int inOrderSuccessor(TreeNode* root) {
        TreeNode* temp = root->right;
        while(temp->left != NULL) {
            temp = temp->left;
        }
        return temp->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val == key) {

            if(!root->left)
                return root->right;

            if(!root->right)
                return root->left;

            int suc = inOrderSuccessor(root);
            root->val = suc;
            root->right = deleteNode(root->right, suc);
        }
        else if(root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};