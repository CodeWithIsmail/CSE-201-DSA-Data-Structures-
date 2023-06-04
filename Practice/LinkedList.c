#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode, *temp, *head, *previous, *nextnode;
void create()
{
    head = NULL;
    int c;
    do
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:\n");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (!head)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Enter 1 for more data:\n");
        scanf("%d", &c);
    } while (c == 1);
}
void display()
{
    temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int size()
{
    temp = head;
    int size = 0;
    while (temp)
    {
        size++;
        temp = temp->next;
    }
    return size;
}
void insertBegin(int value)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}
void insertEnd(int value)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void insertPosition(int value, int position)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    int count = 1;
    temp = head;
    while (count < position)
    {
        count++;
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void deleteBegin()
{
    temp = head;
    head = head->next;
    free(temp);
}
void deleteEnd()
{
    temp = head;
    while (temp->next)
    {
        previous = temp;
        temp = temp->next;
    }
    previous->next = NULL;
    free(temp);
}
void deletePosition(int position)
{
    temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}
int main()
{
    create();
    display();
    printf("size: %d\n", size());
    insertBegin(10);
    insertEnd(20);
    insertPosition(30, 3);
    display();
    printf("size: %d\n", size());
    deleteBegin();
    deleteEnd();
    deletePosition(3);
    display();
}