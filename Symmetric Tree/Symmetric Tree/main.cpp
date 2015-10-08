//
//  main.cpp
//  Symmetric Tree
//
//  Created by Andy Zhu on 11/5/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode*  left;
    TreeNode*  right;
    TreeNode(int x): val(x),left(NULL), right(NULL){}
};

bool helper (TreeNode * l, TreeNode* r){
    if (l==NULL && r==NULL)
        return true;
    else if (l==NULL|| r==NULL)
        return false;
    
    if (l->val == r->val)
        return helper(l->left, r->right) && helper(l->right, r->left);
    else
        return false;
}


bool isSymmetric(TreeNode *root) {
        if(root== NULL)
            return true;
    stack<TreeNode*> ls,rs;
    TreeNode* l = root->left;
    TreeNode* r = root->right;
    while (l!=NULL || r!=NULL){
        
        if (l==NULL && r==NULL)
            return true;
        else if (l==NULL||r==NULL)
            return false;
        
        while(l->left!= NULL){
            if(r->right==NULL)
                return false;
            
            TreeNode* temp;
            
            ls.push(l);
            temp = l->left;
            l->left =NULL;
            l=temp;
            rs.push(r);
            temp = r->right;
            r->right=NULL;
            r= temp;

        }
        
        while(l->right!= NULL){
            if(r->left==NULL)
                return false;
            TreeNode* temp;
            
            ls.push(l);
            temp = l->right;
            l->right =NULL;
            l=temp;
            rs.push(r);
            temp = r->left;
            r->left=NULL;
            r=temp;
        }

        
        if (l->val != r->val)
            return false;
        
        if ((l->left ==NULL && r->right!=NULL)||(l->right ==NULL && r->left!=NULL))
            return false;
        
        if (l->left==NULL && l->right==NULL && !ls.empty()){
            l= ls.top();
            r= rs.top();
            ls.pop();
            rs.pop();
        }
        
        else if(l->left==NULL && l->right==NULL && ls.empty()) {
            l=NULL;
            r=NULL;
        }
        
    }
    
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* root= new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(4);
    TreeNode* node6 = new TreeNode(3);
    //TreeNode* node7 = new TreeNode(-100);
    //TreeNode* node8 = new TreeNode(-15);
    root->left= node1;
    root->right=node2;
    //node1->left = node3;
    node1->right = node4;
    node2->left= node5;
    node2->right=node6;
    
    //node4->left=node7;
    //node5->right = node8;
    if (isSymmetric(root))
        std::cout << "Hello, World!\n";
    return 0;
}
