#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node * head;
void create_end(int item)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *temp;

    if(ptr==NULL)
    {
        printf("Linked list is ful\nl");
    }
    else{
        ptr->data=item;
if(head==NULL)
{
    ptr->next=NULL;
    head=ptr;
    printf("Node inserted\n");

}
    
    else{
        temp=head;
        while(temp->next !=NULL)
        {
            temp=temp->next;
        }
       
        temp->next=ptr;
        ptr->next=NULL;
        printf("\n Node inserted.\n");
    }
    }
}
void delete_end()
{
    struct node *ptr;
    struct node *ptr1;
   
   
    if(head==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    else if(head->next==NULL){
        head=NULL;
        free(head);
        printf("\n Only node of list is deleted\n");
    }
    else{ 
        ptr=head;
        while(ptr->next !=NULL)
        {
           ptr1=ptr;
           ptr=ptr->next;
        }
        ptr1->next=NULL;
        printf("\nDeleted node from the list is: %d",ptr->data);
        free(ptr);


    }
}
void traverse(struct node *p)
{
    if(p==NULL)
    {
        printf("No element to display\n");
    }
    else{
        printf("The elements of linkedlist are: \n");
        while(p->next !=NULL)
        {
            printf("%d\n",p->data);
            p=p->next;
        }
    }
}
int main()
{
    int item, choice;
    do{
    printf("1.Insert\n 2.Delete\n 3.Display \n 4.Exit\n");
    printf("Enter your choice: \t");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Enter the item you want to insert: \t");
        scanf("%d",&item);
        create_end(item);
        break;
        case 2: delete_end();
        break;
        case 3: traverse(head);
        break;
        case 4: exit(0);
       break;
        default:
        printf("Invalid choice\n");
    }
    }while(choice != 4);
}