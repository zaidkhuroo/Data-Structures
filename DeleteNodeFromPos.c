#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
// creating 4 pointers to point over the nodes at different positions
struct node *temp, *head, *tail, *newnode;
int choice = 1;

void call()
{
//     allocating location
  newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the node\n");
        scanf("%d", &newnode->data);
//     as this is the doubly linked list so both the prev and next pointer are set to null/0
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
            tail = newnode;
        }
}

void DeleteFromPos()
{
    struct node *temp=head;
    
    int pos, i = 1;
    printf("\n Enter the position of node to be deleted\n ");
    scanf("%d", &pos);

    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}
void Display()
{
    // struct node *temp;
     temp = head;
    while (temp !=0)
     {
        printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("%d",temp);
}

void main()
{
    call();
    call();
    call();
    call();
    call();
    
    Display();

    DeleteFromPos();

    Display();
}
