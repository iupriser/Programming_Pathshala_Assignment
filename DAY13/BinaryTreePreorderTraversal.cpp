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

// iterative solution with boolean marker

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<pair<TreeNode *, bool>> stk;
        if (!root)
            return res;
        stk.push(make_pair(root, false));
        pair<TreeNode *, bool> curr;
        while (!stk.empty())
        {
            curr = stk.top();
            stk.pop();
            if (curr.second == false) // children are not pushed in stack of this node
            {
                if (curr.first->right)
                    stk.push(make_pair(curr.first->right, false));
                if (curr.first->left)
                    stk.push(make_pair(curr.first->left, false));
                stk.push(make_pair(curr.first, true));
            }
            else
            {
                res.push_back(curr.first->val);
            }
        }
        return res;
    }
};

/*

// iterative solution(without using boolean marker)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        if(!root)   return res;
        stack<TreeNode *>stk;
        stk.push(root);
        TreeNode *curr;
        while(!stk.empty()) {
            curr = stk.top();
            res.push_back(curr->val);
            stk.pop();
            if(curr->right) stk.push(curr->right);
            if(curr->left)  stk.push(curr->left);
        }
        return res;
    }
};

*/

/*


// recursive solution

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        preorder(root,res);
        return res;
    }
    void preorder(TreeNode *root, vector<int>&res) {
        if(!root) return;
        res.push_back(root->val);
        preorder(root->left,res);
        preorder(root->right,res);
    }
        
};

*/
