#include <stdio.h>
#include <stdlib.h>
void main()
{
  struct node
  {
    int data;
    struct node *next;
  };
  struct node *head =NULL,*pos=NULL,*tail =NULL;
  int ch,entry;
  while(1)
  {
      printf("\n 1.Insert \n 2.Display \n 3.Search an Element \n 4.Deletion \n 5.Exit");
      printf("\nEnter your choice\n");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1:
        {
          printf("\n Enter Data ");
          scanf("%d",&entry);
          if (head==NULL)
          {
            head=(struct node*)malloc(sizeof(struct node));
            head->data=entry;
            pos=head;
            tail=head;
          }
          else
          {
            tail->next=(struct node*)malloc(sizeof(struct node));
            tail=tail->next;
            tail->data=entry;
          }
          break;
       }
       case 2:
       {
         pos=head;
         printf("\n Elements are\n");
         while (pos!=NULL)
         {
            printf("%d",pos->data);
            pos=pos->next;
         }
         break;
       }
       case 3:
       {
         int r,flag=0;
         printf("\n Enter element to be searched\n");
         scanf("%d",&r);
         pos=head;
         while(pos!=NULL)
         {
           if(r==pos->data)
           {
             flag=1;
             break;
           }
           pos=pos->next;
         }
         if(flag==1)
           printf("\nelement found");
         else
           printf("\nelement not found");
         break;
         
       }
       case 4:
       {
         struct node *temp=head;
         printf("\n Enter postion of data");
         scanf("%d",&entry);
         if(entry==0)
         {
           head=head->next;
           temp->next=NULL;
           free(temp);
         }
         else
         {
           for(int i=0;i<entry-1;i++)
           {
             temp=temp->next;
           }
           struct node *del=temp->next;
           temp->next = temp->next->next;
           del->next=NULL;
           free(del);
         }
           break;
       }
       case 5:
       {
         printf("\n Goodbye");
         exit(0);
       }
      }
  }
}  
