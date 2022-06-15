
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int *buffer;
    int size;
    int used;
    bool lock;
} resource;

resource file_a;

void producer(int data){
    printf(">> Attempt to produce :");
    if(file_a.lock == true){
        printf("\tFailed! \n>> The resource in unavailable.\n");
        return;
    }
    if(file_a.used == file_a.size){
        printf("\tFailed! \n>> The resource in already full.\n");
        return;
    }
    file_a.lock = true;
    file_a.buffer[file_a.used] = data;
    file_a.used++;
    file_a.lock = false;
    printf("\tDone! \n");
}

int consumer(void){
    printf(">> Attempt to consume :");
    if(file_a.lock == true){
        printf("\tFailed! \n>> The resource in unavailable.\n");
        return 0;
    }
    if(file_a.used == 0){
        printf("\tFailed! \n>> The resource is empty.\n");
        return 0;
    }
    file_a.lock = true;
    int data = 0;
    data = file_a.buffer[file_a.used];
    file_a.used--;
    file_a.lock = false;
    printf("\tDone! \n");
    return data;
}

int main(void){
    file_a.lock = false;
    file_a.used = 0;
    printf("Enter the size of buffer : ");
    scanf("%d", &file_a.size);
    file_a.buffer = (int*)calloc(sizeof(int), file_a.size);
    int ch = 0;
    while(ch != 3){
        printf("[1. Produce, 2. Consume, 3. Exit] choice : ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            producer(999);
            break;
        case 2:
            consumer();
            break;
        case 3:
            break;
        }

    }
    free(file_a.buffer);
    file_a.buffer = NULL;
    return 0;
}
