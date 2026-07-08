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
    map<TreeNode*, int> count;

    int dfs(TreeNode* root){
        if(!root) return 0;
        count[root] = 1 + dfs(root->left) + dfs(root->right);
        return count[root];
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root);   // build subtree sizes

        TreeNode* curr = root;

        while(curr != NULL){
            int leftCount = curr->left ? count[curr->left] : 0;
            int curr_rank = leftCount + 1;

            if(k == curr_rank){
                return curr->val;
            }
            else if(k < curr_rank){
                curr = curr->left;
            }
            else{
                k -= curr_rank;
                curr = curr->right;
            }
        }

        return -1;
    }
};