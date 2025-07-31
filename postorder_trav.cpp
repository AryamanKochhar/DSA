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
      vector<int> postorderTraversal(TreeNode* root) {
          struct TreeNode* temp=root;
          vector<int> arr;
          postorder(root,arr);
          return arr;
      }
      void postorder(TreeNode* current,vector<int>& arr){
          if(current==NULL){
              return;
          }
          postorder(current->left,arr);
          postorder(current->right,arr);
          arr.push_back(current->val); 
      }
  };