#include<stdio.h>
#include<stdlib.h>
void create(int);
void begdelete();
struct node{
    int data;
    struct node * next;
};
struct node *head;
void traverse(struct node *p)
{
    while(p->next !=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
void create(int item)
{
    struct node *ptr= (struct node *)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("\nOverflow");
    }
    else{
        ptr->data=item;
        ptr->next=head;
        head=ptr;
        printf("\n Node inserted\n");
    }
}
void begdelete()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("/nLinkedlist is Empty");
    }
    else{
        ptr=head;
        head=ptr->next;
        printf("\n deleted element is: %d",ptr->data);
        free(ptr);
        printf("\nNode deleted from the beginning...");
    }
}
int main()
{
    int choice, item;
    do{
        printf("\n1. Create Linked list\n2. Delete node\n 3. Exit \n4.Traverse ");
        printf("Enter your choice: \t");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the item: \t");
            scanf("%d",&item);
            create(item);
            break;
            case 2: begdelete();
            break;
            case 3: exit(0);
            break;
            case 4: traverse(head);
            break;
            default: 
            printf("\n Invalid choice");

            
        }
    }while(choice !=3);
}
