//
//  main.cpp
//  Binary Tree Preorder Traversal
//
//  Created by Andy Zhu on 11/1/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode *root) {
    vector<int> myvector;
    stack<TreeNode*> parents;
    unordered_map<TreeNode*, int> checked;
    //bool parentpushed = false;
    
    TreeNode* cursor = root;
    while (cursor != NULL)
    {
        if (checked[cursor]!=1){
            myvector.push_back( cursor->val);
            checked[cursor]=1;
        }
        if (cursor->left!=NULL){
            TreeNode* temp = cursor->left;
            cursor->left= NULL;
            parents.push(cursor);
        
            cursor=temp;
        }
        
        else if (cursor->right != NULL)
        {
            TreeNode* temp = cursor->right;
            cursor->right= NULL;
            parents.push(cursor);
            
            cursor=temp;
        }
        
        else if (!parents.empty())
        {
            cursor= parents.top();
            parents.pop();
        }
        else
            cursor =NULL;
    }
    
    return myvector;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* root = new TreeNode(2);
    TreeNode* node2 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    root->left = node2;
    root->right = node3;
    node3->left = node4;

    vector<int> myvector;
    myvector = preorderTraversal(root);
    for (auto it = myvector.begin(); it!= myvector.end();++it)
        std::cout << (*it)<<endl;
    return 0;
}





