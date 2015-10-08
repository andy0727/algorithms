//
//  main.cpp
//  Binary Tree Level Order Traversal II
//
//  Created by Andy Zhu on 11/7/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void helper(TreeNode*root, vector<vector<int> >&res, int level)
{
    if(root==NULL)
        return;
    while(res.size()<=level)
        res.push_back(vector<int>());
    res[level].push_back(root->val);
    
    if(root->left!=NULL)
        helper(root->left,res, level+1);
    
    if(root->right!=NULL)
        helper(root->right,res, level+1);
    
}

vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > res;
    if (root== NULL)
        return res;
    
    helper(root, res, 0);
    return vector<vector<int> >( res.rbegin(), res.rend());
}
int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* root = new TreeNode(0);
    
    vector<vector<int> > res = levelOrderBottom(root);
    
    for(auto i= res.begin();i!=res.end();++i)
    {
        
        for(auto j= i->begin(); j!= i->end(); ++j)
            cout<<*j<<" ";
        cout<<endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
