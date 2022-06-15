// Using System Calls
// 1. fork()                : Creates the process
// 2. sleep(seconds)        : Halt for some time
// 3. wait(NULL)            : Halt till all process has done
// 4. exit(0)               : Terminates the process
// 5. getpid(), getppid()   : get process id
// 6. alarm(seconds)        : set time limit
//                          (managed by signals)
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void alarm_ring(void){
    printf("--> Oh! Alarm has Trigirred!\n");
}

int main() {
    // Get status
    printf("running on pid: %d(parent:%d)\n", getpid(), getppid());
    signal(SIGALRM, alarm_ring);
    
    // Create the child process
    // using fork()
    // Returns 0 for child process
    // Returns positive for parent process
    // Returns negative for Failier
    int status = fork();
    
    ///////////////////////////////////////////////
    // This is child process
    ///////////////////////////////////////////////
    if (status == 0){
        // Get status
        printf("--> running on pid:%d(parent:%d)\n", getpid(), getppid());
        printf("--> Hello from child\n");
        // Set alarm to be ringed after 2 sec
        alarm(4);
        // Wait for 10 sec
        // but ringing intrupts it.
        sleep(10);
        // Terminate process (i.e. child process)
        exit(0);
    }
    
    ///////////////////////////////////////////////
    // This is failier condition
    ///////////////////////////////////////////////
    if (status < 0){
        printf("Failed to create child process\n");
    }

    ///////////////////////////////////////////////
    // This is Parent process
    ///////////////////////////////////////////////
    // Wait untill all child process is finished.
    printf("pid: %d has terminated\n", wait(NULL));
    printf("Hello from Parent\n");
    return 0;
}