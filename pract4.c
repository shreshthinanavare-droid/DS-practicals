// browser navigation system
#include<stdio.h>
#include<string.h>

int main()
{
    int max=10;
    int size=50;

    char BackStack[max][size];
    char ForwardStack[max][size];

    int Btop=-1;
    int Ftop=-1;

    char currentpage[50]="Home";
    char newpage[50];

    int choice;

    do
    {
        printf("\n----------MENU----------");
        printf("\n 1.Visit new page.\n 2.Back Navigation.\n 3.Forward Navigation.\n 4.Display Current Page.\n 5.Exit.\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            // Visit new page.
            case 1:
                printf("Enter the page you want to visit: ");
                scanf("%s",newpage);

                Btop++;
                strcpy(BackStack[Btop],currentpage);
                Ftop=-1;

                strcpy(currentpage,newpage);

                printf("Current Page: %s",currentpage);

                break;

            // Back Navigation.
            case 2:
                if(Btop==-1)
                {
                    printf("\n No Back Navigation possible.");
                }
                else
                {
                    Ftop++;
                    strcpy(ForwardStack[Ftop],currentpage);

                    strcpy(currentpage,BackStack[Btop]);
                    Btop--;

                    printf("Current page: %s",currentpage);
                }

                break;

            // Forward Navigation.
            case 3:
                if(Ftop==-1)
                {
                    printf("\n No Forward Navigation Possible.");
                }
                else
                {
                    Btop++;
                    strcpy(BackStack[Btop],currentpage);

                    strcpy(currentpage,ForwardStack[Ftop]);
                    Ftop--;

                    printf("Current page: %s",currentpage);
                }

                break;

            // Display current page.
            case 4:
                printf("Current page: %s",currentpage);
                break;

            case 5:
                printf("\n Exit Navigation.");
                break;

            default:
                printf("\n Invalid Choice.");
                break;
        }

    }while(choice != 5);
}
