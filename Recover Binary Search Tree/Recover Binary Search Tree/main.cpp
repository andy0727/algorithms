//
//  main.cpp
//  Recover Binary Search Tree
//
//  Created by Andy Zhu on 11/22/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void InOrderMorrisTraversal(TreeNode *root){
    TreeNode* prev= NULL, *cursor=root;
    TreeNode* first=NULL,*second=NULL,*last=NULL;
    while(cursor){
        if(cursor->left==NULL){
            if(!last){
                last=cursor;
                continue;
            }
            if(last->val>cursor->val){
                if(!first)
                    first=last;
                
                second =cursor;
            }
            last= cursor;
            cursor=cursor->right;
        }
        else{
            prev=cursor->left;
            while(prev->right&& prev->right!=cursor)
                prev=prev->right;
                
            if(!prev->right)
            {
                prev->right=cursor;
                cursor=cursor->left;
            }
            
            else{
                prev->right=NULL;
                if(!last){
                    last=cursor;
                    continue;
                }
                if(last->val>cursor->val){
                    if(!first)
                        first=last;
                    
                    second =cursor;
                }
                last= cursor;
                
                cursor=cursor->right;
            }
            
                
        }
    }
    if(first!=NULL&& second!=NULL){
        int tmp = first->val;
        first->val=second->val;
        second->val=tmp;
    }
    
}
void recoverTree(TreeNode *root) {
    InOrderMorrisTraversal(root);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* root=new TreeNode(0);
    TreeNode* node1=new TreeNode(1);
    root->left=node1;
    recoverTree(root);
    std::cout << "Hello, World!\n";
    return 0;
}
