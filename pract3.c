// Dynamic contact list management using linked list
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct contact
{
     char name[20];
     long int phone_no;
     struct contact *next;
};

struct contact *head=NULL;

int main()
{
  int choice;

  do {
      printf("\n--MENU--");
      printf("\n 1.Insert a new contact at beginning\n 2.Insert at end\n 3.Delete a contact using name\n 4.Search for a contact\n 5.Display all contacts\n");
      printf("Enter a choice");
      scanf("%d", &choice);

      switch(choice) {

         case 1://Insert a contact at Beginning
              {
                 struct contact *newcontact;
                 newcontact=(struct contact *)malloc(sizeof(struct contact));
                 printf("Enter the contact name");
                 scanf("%s", newcontact->name);
                 printf("Enter the phone number");
                 scanf("%ld", &newcontact->phone_no);
                 newcontact->next=head;
                 head=newcontact;
                 printf("Contact inserted successfully:");

                 break;
               }

         case 2://Insert a contact at end
              {
                struct contact *newcontact;
                struct contact *temp;
                newcontact=malloc(sizeof(struct contact));
                printf("Enter the contact name");
                scanf("%s", newcontact->name);
                printf("Enter the phone number");
                scanf("%ld", &newcontact->phone_no);
                newcontact->next=NULL;

                if(head==NULL)
                {
                   head=newcontact;
                }
                else
                {
                  temp=head;
                  while(temp->next!=NULL)
                  {
                    temp=temp->next;
                  }
                  temp->next=newcontact;
                }
                printf("Contact inserted successfully:");
                break;
              }

         case 3://Delete a contact from list
              {
                char name[20];
                struct contact *temp;
                struct contact *prev;
                printf("Enter the name to delete:");
                scanf("%s",name);
                temp=head;
                prev=NULL;

                while(temp!=NULL && strcmp(temp->name,name)!=0)
                {
                  prev=temp;
                  temp=temp->next;
                }

                if(temp==NULL)
                {
                  printf("Contact not found:");
                }
                else
                {
                  if(prev==NULL)
                  {
                    head=temp->next;
                  }
                  else
                  {
                    prev->next=temp->next;
                  }
                  free(temp);
                  printf("Contact deleted successfully:");
                }
                break;
              }

         case 4://Search a contact from list
              {
                char name[20];
                struct contact *temp;
                printf("Enter the name to search:");
                scanf("%s",name);
                temp=head;

                while(temp!=NULL)
                {
                  if(strcmp(temp->name,name)==0)
                  {
                    printf("\nContact found!");
                    printf("\nName: %s",temp->name);
                    printf("\nPhone Number: %ld",temp->phone_no);
                    break;
                  }
                  temp=temp->next;
                }

                if(temp==NULL)
                {
                  printf("Contact not found:");
                }
                break;
              }

         case 5://Display Contact list
              {
                struct contact *temp;
                if(head==NULL)
                {
                   printf("Contact list is empty:");
                }
                else
                {
                  temp=head;
                  printf("\n----CONTACT LIST----\n");
                  while(temp!=NULL)
                  {
                    printf("Name: %s\n",temp->name);
                    printf("Phone Number: %ld\n",temp->phone_no);
                    temp=temp->next;
                  }
                }
                break;
              }

         case 6:
              printf("Exiting program");
              break;

         default:
              printf("Invalid choice!");
         }
     }
  while(choice!=7);

  return 0;
}
