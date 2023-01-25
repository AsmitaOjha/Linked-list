#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node *next;
};
struct node* head;
void RandomInsert(int item)
{ 
    int loc,i;

struct node* temp;
    struct node * ptr= (struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Overflow");
    }
    else{
        printf("Enter the location where you want to insert the item: \t");
            scanf("%d",&loc);
            
             ptr->data=item;
      
            temp=head;
            for(i=0; i<loc; i++)
            {
                temp=temp->next;
              
                if(temp==NULL)
                {
                    printf("\nCan't insert");
                    return;
                }
            }
            
            ptr->next=temp->next;
            temp->next=ptr;
            printf(" Node inserted at %d location.",loc);
        
    }
}
void traverse(struct node *p)
{ printf("The elements of the linked list are: \n");
    while(p !=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
int main()
{
   
    int  item;
    struct node *one;
    struct node *two;
    struct node *three;
    struct node *four;
    //allocate memory
    one= malloc(sizeof(struct node));
     two= malloc(sizeof(struct node));
      three= malloc(sizeof(struct node));
       four= malloc(sizeof(struct node));
       //assign values
       one->data=12;
       two->data=24;
       three->data=36;
       four->data=48;
       //connect nodes;
      head=one;
       one->next=two;
       two->next=three;
       three->next=four;
       four->next=NULL;
      
        traverse(head);
    
    
        printf("Enter the item you want to insert: \t");
        scanf("%d",&item);
        RandomInsert(item);
        traverse(head);
    
   
    return 0;
}