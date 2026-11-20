// roll no sorting system using bubble sort
#include <stdio.h>
 int main()
{
    int roll[20], n, i, j, temp;

    // Accept roll numbers
    printf("Enter the number of students: ");
    scanf("%d", &n);

     printf("Enter the roll numbers:\n");
     for(i = 0; i < n; i++)
     {
           scanf("%d", &roll[i]);
      }

    // Bubble Sort
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(roll[j] > roll[j + 1])
            {
                temp = roll[j];
                roll[j] = roll[j + 1];
                roll[j + 1] = temp;
            }
        }

        // Display intermediate pass
       printf("Pass %d: ", i + 1);
       for(j = 0; j < n; j++)
        {
            printf("%d ", roll[j]);
        }
        printf("\n");
    }

    // Display sorted roll numbers
   printf("\nSorted Roll Numbers: ");
   for(i = 0; i < n; i++)
    {
        printf("%d ", roll[i]);
    }

    printf("\n");

    return 0;
}
