
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
    // 1. Get the pages
    printf("\nEnter number of pages references : ");
    int num_pages = 0;
    scanf("%d", &num_pages);
    int page[num_pages];
    printf("\n");
    for(int i = 0 ; i < num_pages ; i++){
        printf("\t > Page #%d reference : ", i+1);
        scanf("%d", &page[i]);
    }

    // 2. Get the number of page frames
    printf("\nEnter number of pages frames : ");
    int num_frames = 0;
    scanf("%d", &num_frames);
    int *frame = (int*) calloc(sizeof(int), num_frames);
    printf("\n");

    // 3. Attempt to process page faults
    int page_faults = 0;
    for(int i = 0 ; i < num_pages ; i++){
        // [A] If the page is ALREADY existed in frame
        //     then DO NOT update the page faults
        //     ... and log the result for reference
        int proceed = 1;
        for (int j = 0 ; j < num_frames ; j++){
            if (page[i] == frame[j]){
                proceed = 0;;
                printf("\t > Page fault #%d : no change \n", 0);
            }
        }
        if (proceed == 0) continue;

        // [B] And If the page is NOT existed in frame
        //     then ONLY update the page faults
        //     ... and log the result for reference
        frame[page_faults%num_frames] = page[i%num_pages];
        page_faults++;
        printf("\t > Page fault #%d : [", page_faults);
        for (int j = 0 ; j < num_frames ; j++){
            printf(" %d ", frame[j]);
        }
        printf(" ]\n");
    }

    // DONE
    return 0;
}
