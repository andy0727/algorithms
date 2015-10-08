//
//  main.cpp
//  Construct Binary Tree from Inorder and Postorder Traversal
//
//  Created by Andy Zhu on 11/17/14.
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
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    
    if(inorder.size()<=0 || preorder.size()<=0|| inorder.size()!=preorder.size())
        return NULL;
    TreeNode* root= NULL;
    stack<TreeNode*> mystack;
    TreeNode* p;
    
    root=new TreeNode(preorder[0]);
    mystack.push(root);
    int in=0;
    int pre=1;
    while(true){
        if(mystack.top()->val==inorder[in])
        {
            p=mystack.top();
            mystack.pop();
            in++;
            
            if(in>=inorder.size())
                break;
            if(mystack.size() && mystack.top()->val==inorder[in])
                continue;
            
            p->right=new TreeNode(preorder[pre]);
            pre++;
            mystack.push(p->right);
        }
        else{
            p=mystack.top();
            p->left=new TreeNode(preorder[pre]);
            pre++;
            mystack.push(p->left);
        }
    }
    return root;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int>preorder;
    vector<int>inorder;
    preorder.push_back(-1);
    inorder.push_back(-1);
    TreeNode* root = buildTree(preorder, inorder);
    std::cout << "Hello, World!\n";
    return 0;
}
