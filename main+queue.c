#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int data;
    struct node *next ;
} node;
typedef struct
{
    node *front ;
    node * rear;
} queue;
queue *initialize ()
{
    queue *q=malloc(sizeof(queue));
    q->front =NULL;
    q->rear=NULL;
}
node *newnode(int x)
{
    node*n=malloc(sizeof(node));
    n->data=x;
    n->next=NULL;
    return n;
}
int isempty(queue*q)
{
    if(q->front==NULL)
        return 1;
    else
        return 0;
}
void enqueue(queue*q,int x)
{
    node *n=newnode(x);
    if(q->rear==NULL)
    {
        q->front=n;
        q->rear=n;
    }
    else
    {
        q->rear->next=n;
        q->rear=n;
    }
}
int dequeue(queue*q)
{
    int x=q->front->data;
    if(q->front==NULL)
        return 0;
    else
        {
            node *n=q->front ;
            q->front=q->front->next;
            free(n);
            q->rear=NULL;
        return x;
    }
}
int main()
{
    queue *q=initialize();
    enqueue(q,8);
    enqueue(q,5);
    enqueue(q,1);
    while(!isempty(q))
    {
        int y=dequeue(q);
        printf("%d",y);
    }
    return 0;
}
