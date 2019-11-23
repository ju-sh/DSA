struct stack_node;

int stack_push(struct stack_node **top, int data);
int stack_pop(struct stack_node **top);
void stack_disp(struct stack_node *top);

