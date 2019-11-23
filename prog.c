//gcc prog.c stack.c queue.c -o a.out

#include<stdio.h>

#include "stack.h"
#include "queue.h"

int main()
{
    int rv;

    //Stack trial
    struct stack_node *top = NULL;
    stack_disp(top);

    stack_push(&top, 32);
    stack_push(&top, 33);
    stack_push(&top, 34);
    stack_disp(top);

    rv = stack_pop(&top);
    printf("rv: %d\n", rv);
    stack_disp(top);

    stack_push(&top, 35);
    stack_disp(top);

    //Queue trial
    struct queue_node *front, *back;
    front = back = NULL;
    queue_disp(front);

    queue_enqueue(&front, &back, 32);
    queue_enqueue(&front, &back, 33);
    queue_enqueue(&front, &back, 34);

    rv = queue_dequeue(&front, &back);
    printf("rv: %d\n", rv);
    queue_disp(front);

    queue_enqueue(&front, &back, 35);
    queue_disp(front);
}
