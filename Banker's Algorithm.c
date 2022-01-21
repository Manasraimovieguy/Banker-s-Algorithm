//Programming Assignment 3 (Manas Kumar Rai) - Banker's Algorithm
// Program collects user input on number of processes, resources to allocate, resource allocation table (for each process), Claim Vector & the Maximum Claim Table
// While running the program, it is best for user to enter inputs (in cases where multiple inputs are required) with a space between each number
#include <stdio.h>

int main(){
      int b = 0;
      int count = 0, m, n, process, temp, resource;
      int allocation_table[5] = {0, 0, 0, 0, 0}; // Here we initialize our arrays in which we store our processes, resources and variables
      int available[5], current[5][5], max_claim[5][5]; // current => allocated resource table, max_claim => (maximum number of resources required to complete each process)
      int maximum_resources[5], running[5], safe_state = 0;
      printf("\nEnter The Total Number Of Processes:\t");
      scanf("%d", &process);
      for(m = 0; m < process; m++) {
            running[m] = 1;
            count++;
      }
      printf("\nEnter The Total Number Of Resources You Wish To Allocate:\t");
      scanf("%d", &resource);
      printf("\nEnter The Claim Vector:\t");
      for(m = 0; m < resource; m++) {
            scanf("%d", &maximum_resources[m]);
      }
      printf("\nEnter Allocated Resource Table:\n"); // Based on number of resources and claim vector added by user, user must add number of allocated resources of each type for each process
      for(m = 0; m < process; m++) {
            for(n = 0; n < resource; n++)
            {
                  scanf("%d", &current[m][n]);
            }
      }
      printf("\nEnter The Maximum Claim Table:\n"); // User must define the total number of resources of each type required for each process to complete
      for(m = 0; m < process; m++) {
            for(n = 0; n < resource; n++)
            {
                  scanf("%d", &max_claim[m][n]);
            }
      }
      printf("\nThe Claim Vector \n"); // Program will print out the details entered by user
      for(m = 0; m < resource; m++) {
            printf("\t%d ", maximum_resources[m]);
      }
      printf("\n The Allocated Resource Table\n");
      for(m = 0; m < process; m++) {
            for(n = 0; n < resource; n++) {
                  printf("\t%d", current[m][n]);
            }
            printf("\n");
      }
      printf("\nThe Maximum Claim Table \n");
      for(m = 0; m < process; m++) {
            for(n = 0; n < resource; n++) {
                  printf("\t%d", max_claim[m][n]);
            }
            printf("\n");
      }
      for(m = 0; m < process; m++) {
            for(n = 0; n < resource; n++) {
                  allocation_table[n] = allocation_table[n] + current[m][n];
            }
      }
      printf("\nAllocated Resources \n");
      for(m = 0; m < resource; m++) {
            printf("\t%d", allocation_table[m]);
      }
      for(m = 0; m < resource; m++) {
            available[m] = maximum_resources[m] - allocation_table[m];
      }
      printf("\nAvailable Resources:");
      for(m = 0; m < resource; m++) {
            printf("\t%d", available[m]);
      }
      printf("\n");
      while(count != 0) {
            safe_state = 0;
            for(m = 0; m < process; m++) {
                  if(running[m]) {
                        temp = 1;
                        for(n = 0; n < resource; n++) {
                              if(max_claim[m][n] - current[m][n] > available[n]) { //if max resources - current resources > available resources we cannot proceed any further and process is in unsafe state
                                    temp = 0;
                                    break;
                              }
                        }
                        if(temp) {
                               printf("\nProcess %d Is In Execution \n", m + 1); // if temp != 0 then process is in execution and will complete, this will continue on for each process
                               running[m] = 0;
                               count--;
                               safe_state = 1;
                               for(n = 0; n < resource; n++) {
                                     available[n] = available[n] + current[m][n];
                               }
                               break;
                        }
                  }
            }
            if(!safe_state) {
                  printf("\nThe Processes Are In An Unsafe State \n"); // Once we get out of the loop, we will check if all processes are also in a safe state
                  break;
            }
            else {
                  printf("\nThe Process Is In A Safe State \n"); // Available Resources after coming out of the loop
                  printf("\nAvailable Vector\n");
                  for(m = 0; m < resource; m++)
                  {
                        printf("\t%d", available[m]);
                  }
                  printf("\n");
            }
      }
      return 0;
}
