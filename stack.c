#include<stdio.h>
#include<stdlib.h>

struct stack_node
{
    int data;
    struct stack_node *link;
};

int stack_push(struct stack_node **top, int data)
{
    struct stack_node *nn = malloc(sizeof(struct stack_node));
    if(nn==NULL)
    {
        perror("Error: could not allocate memory for new stack node.\n");
        return -1;
    }
    nn->data = data;
    nn->link = NULL;
    if(*top!=NULL) //if stack not empty
    {
        nn->link = *top;
    }
    *top = nn;
    return 0;
}

int stack_pop(struct stack_node **top)
{
    if(*top==NULL)
    {
        perror("Stack empty. Nothing to delete!"); 
        return -1;
    }
    int del_node_val;
    struct stack_node *del_node = *top;
    del_node_val = del_node->data;
    free(del_node);
    *top = (*top)->link;
    return del_node_val;
}

void stack_disp(struct stack_node *top)
{
    if(top==NULL)
    {
        perror("Stack empty.\n");
        return;
    }
    printf("The stack is: ");
    for(struct stack_node *rider=top; rider!=NULL; rider=rider->link)
    {
        printf("%d, ", rider->data);
    }
    printf("\n");
}

// int main()
// {
//     struct stack_node *top = NULL;
//     int rv;
//     stack_disp(top);
//     stack_push(&top, 32);
//     stack_push(&top, 33);
//     stack_push(&top, 34);
//     stack_disp(top);
// 
//     rv = stack_pop(&top);
//     printf("%d\n", rv);
//     stack_disp(top);
// }
