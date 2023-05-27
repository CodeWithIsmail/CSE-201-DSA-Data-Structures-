#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *newnode, *temp, *previous, *nextnode;
// 1. Create
void create_node()
{
    head = NULL;
    int choice;
    do
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:\n");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Enter 1 for more data:\n");
        scanf("%d", &choice);
    } while (choice == 1);
}
// 2. Size
int size()
{
    int count = 0;
    temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
// 3. Display
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
// 4. Insert Begin
void insertBegin(int value)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}
// 5. Insert End
void insertEnd(int value)
{
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
// 6. Insert Position
void insertPoistion(int value, int position)
{
    if (position > size())
        printf("Invalid Position\n");
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = value;
        temp = head;
        int count = 1;
        while (count < position)
        {
            count++;
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
// 7. Delete begin
void deleteBegin()
{
    if (size())
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    else
        printf("List is empty\n");
}
// 8. Delete End
void deleteEnd()
{
    temp = head;
    while (temp->next)
    {
        previous = temp;
        temp = temp->next;
    }
    if (temp == head)
        head = NULL;
    else
        previous->next = NULL;
    free(temp);
}
// 9. Delete position
void deletePosition(int position)
{
    if (position > size())
        printf("Invalid Position\n");
    else
    {
        int count = 1;
        temp = head;
        while (count < position - 1)
        {
            temp = temp->next;
            count++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        free(nextnode);
    }
}
int main()
{
    create_node();
    printf("Size: %d\n", size());
    display();
    insertBegin(10);
    insertEnd(19);
    insertPoistion(23, 4);
    display();
    deleteBegin();
    deleteEnd();
    deletePosition(3);
    display();
}