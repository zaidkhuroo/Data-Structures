#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *tail;
struct node *temp;
struct node *head;
struct node *newnode;
int choice;

void insert()
{
 
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node)); //allocating space for the pointer
    printf("Enter Node -> ");
    scanf("%d", &newnode->data);
    // head->next=newnode;
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
void insertAtBeg()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter the node at beg\n");
    scanf("%d", &newnode->data);
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}
void insertAtEnd()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the node at end\n");
    scanf("%d", &newnode->data);
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    newnode->next = 0;
}
void insertatpos()
{
    int pos=0, i=0;
        printf("\nEnter position for insertion: ");
        scanf("%d", &pos);
    if (pos == 1)
    {
        insertAtBeg();
    }
    else
    {
        struct node *newnode; //*position;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the node: ");
        scanf("%d", newnode->data);
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
            newnode->prev = temp;
            newnode->next = temp->next;
            temp->next = newnode;
            newnode->next->prev = newnode;
            // position=tail->prev;
            // position->prev=newnode->next;
        }
    }
}
void reverse()
{
    struct node *current, *next; //*temp;
    //  current = head;
    temp = tail;
    printf("\nReverse: ");
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->prev;
        printf(" ");
    }
    printf("%d ", temp);
}
void display()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp);
}
void main()
{
    // insertAtEnd();
    insert();
    insert();
    insert();
    display();
    //insertAtBeg();
    //display();
    //insertAtEnd();
    //display();
    insertatpos();
    display();
    //reverse();
}
