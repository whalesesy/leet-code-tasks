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
    vector<int> inorderTraversal(TreeNode* root) {
   vector<int> ans;
        TreeNode* temp = root;
        while(temp){
            if(temp->left==NULL){
                ans.push_back(temp->val);
                temp=temp->right;
            }
            else{
                TreeNode* pred = temp->left;
                while(pred->right) pred=pred->right;
                TreeNode* t=temp;
                pred->right=temp;
                temp=temp->left;
                t->left=NULL;
            }
        }
        return ans;
    }
};