//  hospital patient registration using queue
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Patient
{
  int patientID;
  char arrivalTime[20];
};

int main()
{

 struct Patient queue[MAX];
 int front = -1;
 int rear = -1;
 int choice, i;

 do {
    printf("\n======Hospital Patient Registration System======\n");
    printf("1. Add Patient\n");
    printf("2. Attend Patient\n");
    printf("3. View Patients\n");
    printf("4. Check Queue Empty\n");
    printf("5.Exit\n");
    printf("Enter Choice: ");
    scanf("%d" , &choice);

    switch (choice) {
    //Add patient
      case 1:
         if (rear == MAX - 1)
         {
            printf("Queue Overflow!\n");
         }
         else {
            if (front == -1)
            {
              front = 0;
            }
            rear++;

            printf("Enter Patient ID: ");
            scanf("%d", &queue[rear].patientID);
            printf("Enter Arrival Time: ");
            scanf("%s", queue[rear].arrivalTime);

            printf("Patient Added Successfully\n");

            }
            break;

      //ATTEND PATIENT
      case 2:
          if(front==-1 || front>rear)
          {
            printf("Queue is Empty\n");
          }
          else
          {
            printf("Attending Patient ID: %d\n",queue[front].patientID);
            printf("Arrival Time: %s\n",queue[front].arrivalTime );
            front++;

              if(front>rear)
              {
                front=rear=-1;
              }
            }
            break;

      //VIEW PATIENTS
      case 3:

          if(front==-1 || front>rear)
          {
            printf("Queue is Empty\n");
          }
          else
          {
            printf("Patients in queue: \n");

              for(i=front;i<=rear;i++)
              {
              printf("Patient ID: %d\n",queue[i].patientID);
              printf("Arrival Time: %s\n",queue[i].arrivalTime);
              }
            }
            break;

      // CHECK QUEUE EMPTY
      case 4:
          if(front==-1 || front > rear)
          {
          printf("Queue is Empty\n");
          }
          else
          {
          printf("Queue is not Empty\n");
          }
          break;

      // EXIT
      case 5:
          printf("Exiting the System.\n");
          break;

      }
    }while(choice != 5);

    return 0;
}
