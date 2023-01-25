#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;

};
struct node *head;
void insert(int item)
{
    struct node *ptr= (struct node*)malloc(sizeof(struct node));
    struct node *temp;
    if(ptr==NULL)
    {
        printf("Overflow\n");
    }
    else{
        ptr->data=item;
        if(head==NULL)
        {
            ptr->next=NULL;
            head=ptr;
            printf("First node is inserted\n");
        }
        else{
            temp=head;
            while(temp->next !=NULL)
            {
                temp =temp->next;
            }
            temp->next=ptr;
            ptr->next= NULL;
            printf("\nNode inserted\n");
        }
    }
}
void randomInsert(int item){
    struct node*p= (struct node*)malloc(sizeof(struct node));
    struct node *box;
    int i, loc;
    if(p==NULL)
    {
        printf("Overflow\n");
    }
    else{
        printf("Enter the location:\t ");
        scanf("%d",&loc);
        p->data=item;
        box=head; //initialize the box naa
    //    printf("%d",head->data);
        for(i=0;i<loc;i++){
            box=box->next;
            if(box==NULL)
            {
                printf("Cannot insert\n");
                return;
            }
        }
        p->next=box->next;
        box->next=p;
        printf("Node is inserted in the location\n");

    }
}
void traverse(struct node *p)

{ printf("The elements of linked list are: \n");
    while(p->next !=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
int main()
{
    int item;
    int choice;
    int data;
    do{

    
  printf("\nEnter the elment to insert in the linked list: \t");
  scanf("%d",&item);
  insert(item);
  printf("\nwant to insert more: press 0\t");
  scanf("%d",&choice);
    }while(choice==0);
    traverse(head);
printf("Enter the data for the location: \t");
scanf("%d",&data);
    randomInsert(data);

    traverse(head);
    return 0;
}