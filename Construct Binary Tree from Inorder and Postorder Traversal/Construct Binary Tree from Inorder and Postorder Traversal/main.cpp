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

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
   
    if(inorder.size()<=0 || postorder.size()<=0|| inorder.size()!=postorder.size())
        return NULL;
    TreeNode* root= NULL;
    stack<TreeNode*> mystack;
    TreeNode* p;
    
    root=new TreeNode(postorder.back());
    postorder.pop_back();
    mystack.push(root);
    while(true)
    {
        //the right side of current node is handled
        if(inorder.back()==mystack.top()->val)
        {
            p=mystack.top();
            mystack.pop();
            inorder.pop_back();
            if(inorder.size()==0)
                break;
            //case1 node doesn't have left. ti's the parent node
            if(mystack.size() && mystack.top()->val==inorder.back())
                continue;
            
            //case2 there is a left node;
            p->left=new TreeNode(postorder.back());
            postorder.pop_back();
            mystack.push(p->left);
        }
        //right side not yet handled
        else
        {
            p=mystack.top();
            p->right=new TreeNode(postorder.back());
            postorder.pop_back();
            mystack.push(p->right);
        }
    }
    
    return root;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
