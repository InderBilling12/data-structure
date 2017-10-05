#include<stdio.h>
#include<stdlib.h>
struct bstnode//binary search tree
{
    int data;
    struct bstnode* left;//left child
    struct bstnode* right;//right child
};
struct bstnode* getNode(int data)
{
   struct  bstnode *temp;
     temp=(struct bstnode*)malloc(sizeof(struct bstnode));//allocating memory heap
    temp->data=data;
    temp->left=NULL;// currently it has no child...this we consider
    temp->right=NULL;
    return temp;

}
struct bstnode * insertion(int data,struct bstnode * root)//if we don't pass root and use it as global then we won't be able to make recursive calls easily
    {
        if(root==NULL)//base condition for recursive call...also used when there is empty tree
    {
        root=getNode(data);
        return root;
    }
    if(data>(root->data))//if data is greater then root 's data then put in right subtree else in left subtree
       root->right=insertion(data,root->right);//this value will be inserted in right subtree
       else if(data<root->data)
       root->left=insertion(data,root->left);
       return root;
}
void pretraverse(struct bstnode * root)//we are doing preorder traversal
{

    if(root==NULL)
        return;
    printf("%d ",root->data);
    pretraverse(root->left);
    pretraverse(root->right);
}
void posttraverse(struct bstnode * root)//we are doing postorder traversal
{

    if(root==NULL)
        return;
    posttraverse(root->left);
    posttraverse(root->right);
     printf("%d ",root->data);
}
void inorder(struct bstnode*root)//we are doing inorder traversal
{

    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main()
{
    struct bstnode * root=NULL;
    int n;
    printf("enter the no. of elements:\n");
    scanf("%d",&n);
    printf("enter the element:\n");
    while(n--)
    {
        int data;
        scanf("%d",&data);
        root=insertion(data,root);
    }
    pretraverse(root);
    printf("\n");
    posttraverse(root);
    printf("\n");
    inorder(root);
    printf("\n");
    return 0;
}
