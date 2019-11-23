#include<stdio.h>
#include<stdlib.h>

struct queue_node
{
    int data;
    struct queue_node *link;
};

int queue_enqueue(struct queue_node **front, struct queue_node **back, int num)
{
    struct queue_node *nn = malloc(sizeof(struct queue_node));
    if(nn==NULL)
    {
        perror("Could not allocate memory for new queue node!\n"); 
        return -1;
    }
    nn->data = num;
    nn->link = NULL;
    if(*back==NULL)
    {
        *front = *back = nn;
    }
    else
    {
        (*back)->link = nn;
        *back = nn;
    }
    return 0;
}

int queue_dequeue(struct queue_node **front, struct queue_node **back)
{
    if(*front==NULL)
    {
        perror("Queue empty. Nothing to delete!"); 
        return -1;
    }
    int del_node_val;
    struct queue_node *del_node = *front; 
    del_node_val = del_node->data;
    *front = (*front)->link;
    if(*front==NULL)
    {
        *back = NULL;
    }
    free(del_node);
    return del_node_val;
}

void queue_disp(struct queue_node *front)
{
    if(front==NULL)
    {
        perror("Queue empty.\n");
        return;
    } 
    printf("The queue is: ");
    for(struct queue_node *rider=front; rider!=NULL; rider=rider->link)
    {
        printf("%d, ", rider->data); 
    }
    printf("\n");
}

// int main()
// {
//     struct queue_node *front, *back; 
//     int rv;
//     front = back = NULL;
//     queue_disp(front);
//     queue_enqueue(&front, &back, 32);
//     queue_enqueue(&front, &back, 33);
//     queue_enqueue(&front, &back, 34);
//     queue_disp(front);
//     rv = queue_dequeue(&front, &back);
//     printf("rv: %d\n", rv);
//     queue_disp(front);
//     queue_enqueue(&front, &back, 35);
//     queue_disp(front);
//     rv = queue_dequeue(&front, &back);
//     printf("rv: %d\n", rv);
//     queue_disp(front);
// }
