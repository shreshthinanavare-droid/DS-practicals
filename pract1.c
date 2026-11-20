// pract 1 : Array operations and searching

#include<stdio.h>
int main()
{
  int marks[20],n,i,choice,del,key,insert,search,found;
  do
  {
    printf("\n==MENU==");
    printf("\n 1.Insert Marks\n 2.Display Marks\n 3.Delete Marks\n 4.Linear search of marks\n 5.Binary search of marks\n 6.Exit\n");
    printf("\n Enter your choice");
    scanf("%d",&choice);
    switch(choice)
    {

  case 1://Insert the Marks
        printf("Enter the total marks ");
        scanf("%d",&n);
        printf("Enter your marks");
        for(i=0;i<n;i++)
        {
            scanf("%d",&marks[i]);
        }
  break;

  case 2://Display the Marks
        printf("marks:\n");
        for(i=0;i<n;i++)
        {
            printf("%d\n",marks[i]);
        }
  break;

  case 3://Delete Marks
        printf("Enter the marks you want to delete:");
        scanf("%d",&del);
        for(i=del;i<n-1;i++)
        {
              marks[i]=marks[i+1];
        }
        printf("Marks at index %d deleted successfully",del);
        n=n-1;
  break;

  case 4://Marks to find by linear search
        printf("enter the marks you want to search:");
        scanf("%d",&search);
        found = 0;

       for(i=0;i<n;i++)
        {
          if(marks[i]==search)
          {
            printf("marks found at %d", i+1);
            found = 1;
            break;
          }
        }
          if(found == 0)
          {
            printf("Marks not found");
           }

  break;

  case 5:// Marks to find by binary search
        int low=0, high=n-1, mid;
        found=0;
        printf("\n Enter the marks for binary search:");
        scanf("%d",&key);
        while(low<=high)
        {
            mid=(low+high)/2;

            if (marks[mid] == key)
            {
                printf("Marks found at position %d",mid+1);
                found=1;
                break;
            }
            else if(marks[mid] < key)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
          if(found==0)
          {
            printf("Marks not found");
          }

  break;

  case 6:
        printf("Exiting program...\n");

  break;

  default:
        printf("\n Enter valid choice:");
       }
    }while (choice!=6);

  return 0;

}
