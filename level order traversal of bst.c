#include<stdio.h>//level order traversal we will be doing using queue
#include<stdlib.h>
int front=-1;//to keep track of top of queue
int rear=-1;//to keep rack of last added element
#define max 100
struct bstnode* queue[max];
void enqueue(struct bstnode* data)
{
    if(rear==max-1 && front==0||front==rear+1 )//if queue is full,,,here we need to check front for that
    {
        printf("overflow condition \n");
        exit(1);
    }
    else  if(front==-1)//if list is empty
    {
         front=0;
         rear=0;
    }
    else if(rear==max-1)//if rear is at last but front is not 0
    {
        rear=0;
    }
    else rear++;//normal case
     queue[rear]=data;

}
int isEMPTY()
{
    if(front==-1||front==rear+1)
    {
        return 0;
    }
    else
        return 1;
}
struct bstnode* dequeue()
{
    struct bstnode* data;
    if(front==-1||front==rear+1)
    {
        printf("underflow condition\n");
        exit(1);
    }
    data=queue[front];
    if(front==max-1)//if front is at last,then make it 0
        front=0;
    else if(front==rear)//if only one element
        front=rear=-1;
    else
        front++;
    return data;
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
void level_order(struct bstnode*root)
{
    struct bstnode*ptr=root;
    if(root==NULL)
    {
        printf("empty tree\n");
        return ;
    }
    enqueue(ptr);
    while(isEMPTY())//traverse till queue is not empty
    {
       ptr= dequeue();
       printf("%d ",ptr->data);//process it and push its left and right child into queue firstly left bczzz fifo
       if(ptr->left!=NULL)
            enqueue(ptr->left);
       if(ptr->right!=NULL)
        enqueue(ptr->right);
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
    printf("the level order traversal is:\n");
    level_order(root);
}
