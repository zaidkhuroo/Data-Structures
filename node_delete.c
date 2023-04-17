#include <stdio.h>
#include <stdlib.h>
struct node
{ 
    int data;
    struct node *next;
};
// making head and temp pointers to point the beginning of node and random node respectively. 
struct node *temp=0; 
struct node *head=0;
struct node *newnode;
// int choice=0; 
void insert()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node)); 
    printf("Enter Node\n");
    scanf("%d", &newnode->data);
    newnode->next=0;
}

void display()
{
    head= temp;
    while (temp != 0)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
   printf("%d", temp);
}
void main()
{
    insert();
    insert();
    insert();
    display();
}
