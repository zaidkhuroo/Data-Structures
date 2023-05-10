#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

 
struct arrayADT
{
    int capacity;
    int lastIndex;
    int *ptr;
};


/*function declerations*/
struct arrayADT* createArray(int capacity); /*function decleration for creating an ADT array*/
int getItem(struct arrayADT *arr,int index); /*function decleration for getiing an item from array by index */
int editItem(struct arrayADT*,int index,int newValue); /*function decleration to edit a value at any index */
int countItems(struct arrayADT*); /*function decleration to count items in an arrayABT */        
int removeItem(struct arrayADT*,int index); /*function decleration to remove item from array*/
int setItem(struct arrayADT*, int index,int value); /*function decleration to put value in an array ADT*/
int search (struct arrayADT*, int item); /*function decleration to search an element in an array*/
void sort(struct arrayADT*);/*function decleration for sorting the array*/



struct arrayADT* createArray(int capacity) /*function definition for creating an ADT array*/
{
    struct arrayADT *arr; /*declaring array*/
    arr=(struct arrayADT*)malloc(sizeof(struct arrayADT)); /*here we will give the size of the arrayADT by malloc function*/
    arr->capacity=capacity; /*array assigining local variable capaci ty to member value capacity*/
    arr->lastIndex=-1;              /*-1 indicates the last index of array, when array is empty the
                                        index of array is -1 and same indx is for the last index of the array*/
    arr->ptr=(int*)malloc(arr->capacity*sizeof(int)); /*creating a pointer of type int to
                                            point it to array with the help of malloc. capacity*sizeof(int) here means
                                            eg: multiplying capacity(5) with size of int(4)= 20 bytes.
                                            (int*) means: typcasting the address of type int*/
    return(arr);  /*returning address of array whic is pointing to structure*/
}



int getItem(struct arrayADT *arr,int index) /*function definition for getting an item from array by index */
{

    if(arr->lastIndex<index || index<0) /*checking if last index is less than 0 index*/
    {
    printf("invalid index\n");
    return (-1); /*it will indicate that the last index is not valid*/
    }
    else
    {
        return(arr->ptr[index]); /*this will return last index of array */
    }

}


int setItem(struct arrayADT *arr, int index, int value) /*function definition to put value in an array ADT*/
{
    int i;
if(arr->lastIndex== arr->capacity-1)
{
printf("overflow\n");
return(0); /*insertion is not possible*/
}
if(index<0 || index>arr->lastIndex+1)           /*error*/
{
    printf("invalid index\n");
    return(0);
}
if(index <=arr->lastIndex)
{
    arr->lastIndex= arr->lastIndex+1; /*increamentng last index to insert new value*/
    i=arr->lastIndex; /* i is assigned the value of last index*/
    while(i!=index)
        {
        arr->ptr[i]=arr->ptr[i-1]; /* this loop will check when i is not equal to index till then it will keep decrementing the value
                                        and it will reach at the index where we want to put the value*/
     i--; /*decreamenting*/
    }
    arr->ptr[index]= value; /*insertion of value at the index */
    return(1);/*notifies insertion is successful*/
}
if(index==arr->lastIndex+1)
{
    arr->lastIndex= arr->lastIndex+1; /*if value of index is equal to value of last index then we will insert el as value of last index will be increased */
    arr->ptr[arr->lastIndex]= value; /*assigining value in the new made index*/
    return(1); /*means value is inserted succesfully*/
}

}


int editItem(struct arrayADT* arr,int index,int newValue)
{
if(index<0 || index>arr->lastIndex)
{
    printf("invalid index\n");
    return(0);
}
else{
    arr->ptr[index]= newValue;
    return(1);
}
}


int countItems(struct arrayADT *arr) /*function definition to count items present in array*/
{
return(arr->lastIndex+1);
}


int removeItem(struct arrayADT *arr,int index) /*function definition to remove item at any index in array*/
{
    if(index<0 || index>arr->lastIndex)
{
    printf("invalid index\n");
    return(0);
}

if(index<arr->lastIndex)
{
int i;
i=index;
while(i<arr->lastIndex)
{
        arr->ptr[i]=arr->ptr[i+1]; /* this loop will check when i is not equal to index till then it will keep decrementing the value
                                             and it will reach at the index where we want to put the value*/
        i++; /*increamenting*/
}
 arr->lastIndex=arr->lastIndex-1;
 return(1);
}
if(index==arr->lastIndex)
{
    arr->lastIndex=arr->lastIndex-1;
    return(1);
}

}

int search (struct arrayADT *arr, int item) /*function definition to search the elements in array*/
{
    int i;
    if(arr->lastIndex==-1)
    return(-1);
    for(i=0;i<=arr->lastIndex;i++)
    if(arr->ptr[i]==item)
    return(i);
    return(-1);
}

void sort(struct arrayADT* arr) /*function definition to sort the elements in array*/
{
    int r,n,i,t;
    n=arr->lastIndex+1;
    for(r=1;r<=n-1;r++)
    {
    for(i=0;i<=n-1-r;i++)
    {
     if(arr->ptr[i]>arr->ptr[i+1])
    {
 t=arr->ptr[i];
 arr->ptr[i]=arr->ptr[i+1];
 arr->ptr [i+1]=t;
  }
}
    }
}

int main()
{
    int i;
    struct arrayADT *arr;
arr=createArray(5);
setItem(arr,0,10);
setItem(arr,1,28);
setItem(arr,2,21);
setItem(arr,3,27);
editItem(arr,2,43);
removeItem(arr,1);

for(i=0;i<countItems(arr);i++)
    printf("%d",getItem(arr,i));
    sort(arr);
    printf("\n");
for(i=0;i<countItems(arr);i++)
    printf("%d",getItem(arr,i));
    i= search(arr,28);
    if(i==-1)
        printf("\nitem not found");
    else
        printf("\nitem found at index %d", i);
return 0;
}
