#include <stdio.h>
#include <stdlib.h>
struct node
{ 
    int data;
    struct node *next;             
};  
// making head and temp pointers to point the beginning of node and random node respectively.  
// creating node temp to point to hover and point over a specific node
struct node *temp=0; 
// creating node head to point at the start of the node
struct node *head=0;
// creating new node
struct node *newnode;
// int choice=0;  
void insert()
{
//     creating a node
    struct node *newnode;
//     allocating memory
    newnode = (struct node *)malloc(sizeof(struct node)); 
    printf("Enter Node\n");
    scanf("%d", &newnode->data);
    newnode->next=0;
}
 
// function to display the result
void display()
{
    head= temp;
//     using while loop until head is not equal to 0
    while (temp != 0)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
   printf("%d", temp);
}
void main()
{
//     calling functions
    insert();
    insert();
    insert();
    display();
}
