/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        //Base case: if we find one of the nodes return non null values; else return null. 
         if(root==NULL || root==p || root==q)               
            return root;
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);            //traverse the left subtree
        TreeNode *right = lowestCommonAncestor(root->right, p, q);          //traverse the right subtree
        
        //If both sub trees return non null values, we have found the LCA. 
        if(left && right)
            return root;

        //If one of the nodes is found in left subtree 
        if(left)
            return left;

        //If one of the nodes is found in right subtree 
        if(right)
            return right;
        
        return NULL;
    }
};