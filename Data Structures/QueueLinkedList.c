#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front, *rear, *temp, *newnode;
// 1. Enqueue
void enqueue(int value)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if (front == NULL && rear == NULL)
        front = rear = newnode;
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
// 2. Display
void display()
{
    if (front == NULL && rear == NULL)
        printf("Empty queue");
    else
    {
        temp = front;
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}
// 3. Dequeue
void dequeue()
{
    if (front == NULL && rear == NULL)
        printf("Empty queue\n");
    else if (front == rear)
    {
        temp = front;
        front = rear = NULL;
        free(temp);
    }
    else
    {
        temp = front;
        front = front->next;
        free(temp);
    }
}
// 4. Peek 
void peek()
{
    if (front == NULL && rear == NULL)
        printf("Empty queue\n");
    else
        printf("%d ", front->data);
}
int main()
{
   enqueue(10);
   enqueue(20);
   enqueue(30);
   enqueue(5);
   enqueue(100);

   display();

   dequeue();
   dequeue();
   dequeue();

   peek();
   display();
}