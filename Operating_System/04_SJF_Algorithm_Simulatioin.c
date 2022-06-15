////////////////////////////////////////////////////////////////////////////////
//                "Shortest Job First" Algorithm Simulator                    //
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

// Structure for process
typedef struct {
    char name[30];
    int process_id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} process;

////////////////////////////////////////////////////////////////////////////////
//                              Main section                                  //
////////////////////////////////////////////////////////////////////////////////
int main(void) {
    // 1. Get the process info from user
    printf("Enter the number of processes : ");
    int n = 0;
    scanf("%d", &n);
    process ready_queue[n];
    for (int i = 0 ; i < n ; i++){
        printf("For Process %2d,\n", i+1);
        printf("\t ID and Name : ");
        scanf("%d %[^\n]", 
            &ready_queue[i].process_id, 
            ready_queue[i].name
        );
        printf("\t Burst Time : ");
        scanf("%d", &ready_queue[i].burst_time);
    }

    // 2. Sort the processes 
    //    w.r.t. Burst Time in DESC(i.e. decreasing) order
    for(int i = 0 ; i < n - 1 ; i++){
        for (int j = i + 1 ; j < n ; j++){
            if (ready_queue[i].burst_time 
                > ready_queue[j].burst_time){
                process temp = ready_queue[i];
                ready_queue[i] = ready_queue[j];
                ready_queue[j] = temp;
            }
        }
    }

    // 3.a. Calculate waiting_time
    int time_passeed = 0;
    for(int i = 0 ; i < n ; i++){
        ready_queue[i].waiting_time = time_passeed;
        time_passeed += ready_queue[i].burst_time;
    }
    
    // 3.b. Calculate turnaround_time
    for(int i = 0 ; i < n ; i++)
        ready_queue[i].turnaround_time
            = ready_queue[i].burst_time 
              + ready_queue[i].waiting_time;

    
    // 4. Display the allocation of processes using "Shortest Job First" algorithm
    printf("\nEach process have scheduled using \"Shortest Job First\" scheduling algorithm\n");
    for(int i = 0 ; i < n ; i ++){
        printf("\nFor process \"%s\" having id \"%d\" is scheduled as follows,\n"
                    , ready_queue[i].name
                    , ready_queue[i].process_id
        );
        printf("\t        Burst Time \t: %3d unit(s) of time. \n", ready_queue[i].burst_time);
        printf("\t      Waiting Time \t: %3d unit(s) of time. \n", ready_queue[i].waiting_time);
        printf("\t   Turnaround Time \t: %3d unit(s) of time. \n", ready_queue[i].turnaround_time);
    }
    
    // Done!
    return 0;
}
