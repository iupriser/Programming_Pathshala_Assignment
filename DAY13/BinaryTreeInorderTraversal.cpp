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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;
        stack<pair<TreeNode *, bool>> stk;
        pair<TreeNode *, bool> curr;
        stk.push(make_pair(root, false));

        while (!stk.empty())
        {
            curr = stk.top();
            stk.pop();
            if (!curr.second)
            {
                if (curr.first->right)
                    stk.push(make_pair(curr.first->right, false));
                stk.push(make_pair(curr.first, true));
                if (curr.first->left)
                    stk.push(make_pair(curr.first->left, false));
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
// iterative solution without boolean marker- version 1

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        if(!root)   return res;
        stack<TreeNode *> stk;
        
        while(root) {
            stk.push(root);
            root=root->left;
        }
        
        TreeNode *curr;
        while(!stk.empty()) {
            curr = stk.top();
            stk.pop();
            res.push_back(curr->val);
            if(curr->right) {
                curr=curr->right;
                while(curr) {
                    stk.push(curr);
                    curr=curr->left;
                }
            }
        }
        return res;
    }
};

*/

/*
// iterative solution without boolean marker- version 2

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        if(!root)   return res;
        stack<TreeNode *> stk;
        while(root != NULL || !stk.empty()) {
            while(root!=NULL) {
                stk.push(root);
                root=root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};

*/

/*
// recursive soution

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        inorder(root,res);
        return res;
    }
    
    void inorder(TreeNode * root, vector<int>&res) {
        if(!root)   return;
        
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
};

*/