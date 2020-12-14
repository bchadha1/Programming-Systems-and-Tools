#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

struct Queue
{
    char* array;
    bool flag;
	int front, rear, size;
	int stackLimit;

};

struct Queue* createQueue(unsigned stackLimit)
{
	struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
	queue->stackLimit = stackLimit;
	queue->front = queue->size = 0;
	queue->rear = stackLimit - 1;
	queue->array = (int*) malloc(queue->stackLimit * sizeof(int));
	return queue;
}

void enqueue(struct Queue* queue, int element)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1)%queue->stackLimit;
	queue->array[queue->rear] = element;
	queue->size = queue->size + 1;
	printf("%d Element Enqueued to the queue\n\n", element);
}

int isFull(struct Queue* queue)
{
    return (queue->size == queue->stackLimit);
}

int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}

int dequeue(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1)%queue->stackLimit;
	queue->size = queue->size - 1;
	return item;
}

int front(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

int rear(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

int main()
{
	struct Queue* queue = createQueue(1000);

	enqueue(queue, 4);
	enqueue(queue, 6);
	enqueue(queue, 5);
	dequeue(queue);
	enqueue(queue, 4);
	enqueue(queue, 3);
	dequeue(queue);
	dequeue(queue);

	printf("%d Element Dequeued from the queue\n", dequeue(queue));

	return 0;
}
