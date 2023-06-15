#include<stdio.h>
#include<stdlib.h>
struct node   
{  
    int item;    
    struct node *next;  
};    
struct node *front;  
struct node *rear,*temp; 
int item; 

void insert()  
{  
    struct node *newnode;  
      
      
    newnode = (struct node *) malloc (sizeof(struct node));  
    if(newnode == NULL)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    else  
    {   
        printf("\nEnter value?\n");  
        scanf("%d",&item);  
        newnode -> data = item;  
        if(front == NULL)  
        {  
            front = newnode;  
            rear = newnode;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = newnode;  
            rear = newnode;  
            rear->next = NULL;  
        }  
    }  
}
display()
{

    while (temp != NULL)
    {
        printf("%d ->", temp->item);
        temp = temp->next;
    }
    printf("%d ", temp);
}
void main()
{
insert();
display();
}
