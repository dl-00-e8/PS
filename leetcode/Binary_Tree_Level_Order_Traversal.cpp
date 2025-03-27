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

 #include <bits/stdc++.h>

 class Solution {
 public:
     vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> result;
         map<int, vector<int>> m; 
         queue<pair<TreeNode*, int>> q;
 
         if(root != NULL) {
             q.push(make_pair(root, 1));
         }
 
         while(!q.empty()) {
             pair<TreeNode*, int> now = q.front();
             q.pop();
 
             TreeNode* node = now.first;
             int lev = now.second;
 
             if(node != NULL) { 
                 m[lev].push_back(node->val);
                 if(node->left != NULL) {
                     q.push(make_pair(node->left, lev + 1));
                 }
                 if(node->right != NULL) {
                     q.push(make_pair(node->right, lev + 1));
                 }
             }
         }
 
         for(auto data: m) {
             int lev = data.first;
             vector<int> lev_list = data.second;
 
             result.push_back(lev_list);
         }
 
         return result;
     }
 };