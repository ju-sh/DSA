struct queue_node;

int queue_enqueue(struct queue_node **front, struct queue_node **back, int num);
int queue_dequeue(struct queue_node **front, struct queue_node **back);
void queue_disp(struct queue_node *front);

