//
//  main.cpp
//  Binary Tree Postorder Traversal
//
//  Created by Andy Zhu on 11/7/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    
    stack<TreeNode*> parents;
    TreeNode* cursor = root;
    
    while(cursor!=NULL)
    {
        if(cursor->left!=NULL){
            parents.push(cursor);
            
            TreeNode* temp = cursor->left;
            cursor->left=NULL;
            cursor=temp;
        }
        
        else if (cursor->right!=NULL){
            parents.push(cursor);
            
            TreeNode* temp = cursor->right;
            cursor->right=NULL;
            cursor=temp;
        }
        
        else{
            res.push_back(cursor->val);
            
            if(parents.empty())
                cursor=NULL;
            else{
                cursor=parents.top();
                parents.pop();
            }
        }
        
    }
    return res;
}
int main(int argc, const char * argv[]) {
    TreeNode* root=new TreeNode(0);
    TreeNode* node1=new TreeNode(1);
    TreeNode* node2=new TreeNode(2);
    root->right=node1;
    node1->left = node2;
    // insert code here...
    
    vector<int>res = postorderTraversal(root);
    
    for(auto it= res.begin();it!=res.end();++it)
        std::cout << *it<<endl;
    return 0;
}
