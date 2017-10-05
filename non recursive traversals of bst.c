#include<stdio.h>
#include<stdlib.h>
#define max 50
struct bstnode* stack[max];//explicit stack we will be needing to implement traversal by non recursive approach
int top=-1;
void push(struct bstnode* item)
{
    if(top==max-1)//overflow condition
        printf("stack overflow occured\n");
    else
    stack[++top]=item;//increment top and push item

}
struct bstnode*pop()
{
    struct bstnode* item;
    if(top==-1)//empty stack
        printf("underflow condition\n");
    else
    {
       item=stack[top];
        top=top-1;//decrease top by 1
    }
    return item;
}
int isEMPTY()
{
    if(top==-1)
        return 0;
    else
        return 1;
}
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

void preorder(struct bstnode*root)// 6 step algo sk srivastav page-189
{
    struct bstnode*ptr=root;
    if(ptr==NULL)
    {
        printf("empty tree\n");
        return ;
    }
    push(ptr);//visit a node push it
    //now pop it and process it and push its:firstly right and then left child into stack ....repeat same procedure until stack os not empty
    while(isEMPTY())
    {
        ptr=pop();
        printf("%d ",ptr->data);
        if(ptr->right!=NULL)
            push(ptr->right);
        if(ptr->left!=NULL)
            push(ptr->left);
    }
    printf("\n");
}
void inorder(struct bstnode*root)
{
    struct bstnode*ptr=root;
    if(root==NULL)
    {
        printf("tree is empty\n");
        return ;
    }
    while(1)
    {
    while(ptr->left!=NULL)//reach at leftmost node,,,,if its leftmost is null no need to push it ..process it,,,,,,
    {
        push(ptr);
        ptr=ptr->left;
    }
    while(ptr->right==NULL)//till that keep processing nodes
    {
        //process it(left most node)
        printf("%d ",ptr->data);
        if(!isEMPTY())//if it is empty
            return;
        ptr=pop();
    }
    //when a node's right is not empty
    //process it and start processing its right subtree
    printf("%d ",ptr->data);
    ptr=ptr->right;
    }
}
void postorder(struct bstnode * root)
{
    struct bstnode*ptr=root,*q;//q to store just previously visited node
    if(root==NULL)
    {
        printf("tree is empty\n");
        return ;
    }
    q=root;
    while(1)
    {
        while(ptr->left!=NULL)//reach leftmost node
        {
            push(ptr);
            ptr=ptr->left;
        }
        while(ptr->right==NULL||ptr->right==q)//either right subtree is null or it is already visited
        {
            //process node
            printf("%d ",ptr->data);
            q=ptr;//most important
            if(!isEMPTY())
                return ;
            ptr=pop();
        }
        //now push it...whose right subtree exist but not visited yet
        push(ptr);
        ptr=ptr->right;
    }

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
    printf("the preorder traversal is:\n");
    preorder(root);
    printf("\nthe inorder traversal is:\n");
    inorder(root);
    printf("\nthe postorder traversal is:\n");
    postorder(root);
}
