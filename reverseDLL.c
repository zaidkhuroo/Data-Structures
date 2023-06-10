#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; 
    struct node *next;
    struct node *prev; 
};
struct node *temp, *head, *tail, *newnode;
//int choice = 1;

void call()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the node\n");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;
    if (head == 0)
    {
        head = tail = newnode;   
    } 
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = NULL;
        tail = newnode;
    }
}

void reverse()
{
    struct node *current, *next, *temper;
    //  current = head;
    temper = tail;
   
    while (temper != NULL)
    {
        printf("%d ->", temper->data);
        temper = temper->prev;
        printf(" ");
    }
}
void Display()
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d", temp);
}

void main()
{
    call();
    call();
    call();

    Display();

    reverse();

   Display();
}
