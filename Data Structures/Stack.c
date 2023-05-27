#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL, *temp, *newnode;
// 1. push
void push(int value)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}
// 2. pop
void pop()
{
    temp = top;
    top = top->next;
    free(temp);
}
// 3. size
void size()
{
    int count = 0;
    temp = top;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    printf("%d\n",count);
}
// 4. display
void display()
{
    if (top == NULL)
        printf("Empty stack\n");
    else
    {
        temp = top;
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
// 5.front
void front()
{
    if (top == NULL)
        printf("Empty stack\n");
    else
        printf("%d\n", top->data);
}

int main()
{
    push(5);
    push(10);
    push(19);
    display();
    size();
    pop();
    push(29);
    display();
    front();
}