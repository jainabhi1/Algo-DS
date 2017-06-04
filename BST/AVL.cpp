#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <set>
#include <map>
#include <functional>
#include <utility>
#include <queue>
using namespace std;
struct node
{
    int data;
    node *left,*right;
    int h;
    node(int data)
    {
        this->data=data;
        left=right=NULL;
        h=1;
    }
};
struct avl
{
    node *root;
    avl()
    {
        root=NULL;
    }
    int getheight(node *root)
    {
        if(!root)
            return 0;
        return root->h;
    }
    node *leftrotate(node *root)
    {
        node *a=root->right;
        node *b=a->left;
        a->left=root;
        root->right=b;

        root->h=max(getheight(root->left),getheight(root->right));
        a->h=max(getheight(a->left),getheight(a->right));

        return a;
    }

    node *rightrotate(node *root)
    {
        node *a=root->left;
        node *b=a->right;
        a->right=root;
        root->left=b;

        root->h=max(getheight(root->left),getheight(root->right));
        a->h=max(getheight(a->left),getheight(a->right));

        return a;
    }
    int getbalance(node *root)
    {
        return getheight(root->left)-getheight(root->right);
    }
    node* insertutil(node* root,int data)
    {
        if(!root)
            return new node(data);
        if(data < root->data)
            root->left=insertutil(root->left,data);
        else if(data > root->data)
            root->right=insertutil(root->right,data);
        else 
            return root;
        
        root->h=1+max(getheight(root->left),getheight(root->right));
        int balance = getbalance(root);
        
        if(balance>1 && data < root->left->data)
        {
            return rightrotate(root);
        }
        
        if(balance>1 && data > root->left->data)
        {
            root->left=leftrotate(root->left);
            return rightrotate(root);
        }

        if(balance<-1 && data > root->right->data)
        {
            return leftrotate(root);
        }

        if(balance<-1 && data < root->right->data)
        {
            root->right=rightrotate(root->right);
            return leftrotate(root);
        }
        
        return root;
    }
    int minvaluenode(node *root)
    {
        while(root->left)
            root=root->left;
        return root->data;
    }
    node* deleteutil(node *root,int data)
    {
        if(!root)
            return NULL;

        if(data < root->data)
            root->left=deleteutil(root->left,data);
        else if(data > root->data)
            root->right=deleteutil(root->right,data);
        else if(root->data==data)
        {
            if(root->left==NULL||root->right==NULL)
            {
                node *temp=(root->left!=NULL)?root->left:root->right;

                if(temp==NULL)
                {
                    temp=root;
                    free(temp);
                    return NULL;
                }
                else
                {
                    free(root);
                    return temp;
                }
            }
            else
            {
                int minvalue=minvaluenode(root->right);
                root->data=minvalue;
                root->right=deleteutil(root->right,minvalue);
            }
        }

        root->h=max(getheight(root->left),getheight(root->right));
        int balance=getbalance(root);

        if(balance>1 && getbalance(root->left)>=0)
            return rightrotate(root);
        if(balance>1 && getbalance(root->left)<0)
        {
            root->left=leftrotate(root->left);
            return rightrotate(root);
        }
        if(balance<-1 && getbalance(root->right)<=0)
            return leftrotate(root);
        if(balance<-1 && getbalance(root->right)>0)
        {
            root->right=rightrotate(root->right);
            return leftrotate(root);
        }

        return root;
    }

    void remove(int data)
    {
        root = deleteutil(root,data);
    }
    void insert(int data)
    {
        root = insertutil(root,data);
    }
    void inorder(node *root)
    {
        if(!root)
            return;
        inorder(root->left);

        printf("%d ", root->data);

        inorder(root->right);
    }
    void inorder()
    {
        inorder(root);
    }
};
int main()
{
   avl a;
   int arr[]={15,78,32,11,45,23,13,90};
   for(int i=0;i<8;i++)
     a.insert(arr[i]);
   a.inorder();
   cout<<endl;
   /* 11 13 15 23 32 45 78 90*/
   a.remove(23);
   a.inorder();
   /* 11 13 15 32 45 78 90*/
}