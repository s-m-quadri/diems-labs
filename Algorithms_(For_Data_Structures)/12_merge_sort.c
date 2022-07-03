// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 28th January 2022



// ###########################
//      Header Section
// ###########################
#include <stdio.h>
#define MAX 5
int array[MAX];


// ###########################
//     Definition Section
// ###########################
void merge(int start1 , int end1 , int start2 , int end2){
    // Declare a temporary array
    // Initialize counter i to start of first sub-array
    // Initialize counter j to start of second sub-array
    // Initialize counter k to start of temporary array
    int temp[MAX];  
    int i = start1; 
    int j = start2; 
    int k = 0;  
    
    // While both are non empty
    while (i <= end1 && j <= end2){ 
            if (array[i] < array[j])
            // If the specified element of first sub array 
            // is less than specified element of second sub array
            // Then put the value of it specified element of FIRST array 
            // into temporary array, also incrementing as per the requirement
            temp[k++] = array[i++]; 
        else
            // If the specified element of first sub array 
            // is NOT less than specified element of second sub array
            // Then put the value of it specified element of SECOND array 
            // into temporary array, also incrementing as per the requirement
            temp[k++] = array[j++];
    }
    
    // While there remain some element in first sub array
    while (i <= end1)
        temp[k++] = array[i++];
        
    // While there remain some element in second sub array
    while (j <= end2)
        temp[k++] = array[j++];
    
    // Overide the original array with the sorted array
    for (i = start1, j = 0; i <= end2; i++, j++)
        array[i] = temp[j];
        
    // At the ending of block temporary array will be destroyed !
} // End of merge

void sort(int start, int end){
    if (start < end){
    // if the index indicated by start
    // is less than the index indicated by end, then only..
        // Calculate the middle index of the passed array
        int mid = (start + end) / 2;
        // sort the left half
        // then sort the right half as,
        sort(start, mid); 
        sort(mid + 1, end);
        // merge the divided two sub array of the passed array
        // from lower to upper level
        merge(start, mid, mid + 1, end);
    }
}


// ###########################
//        Main Section
// ###########################
int main(){
    int i = 0;
    // Get the Array
    printf("Please enter %d elements,\n", MAX);
    for(i = 0 ; i < MAX ; i++){
        printf("\t Element %02d : ", i+1);
        scanf("%d", &array[i]);
    }
    
    // Input Array
    printf(" Input array : ");
    for(i = 0 ; i < MAX ; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    
    // Sort the Array
    sort(0 , MAX-1);
    
    // Output Array
    printf("Sorted array : ");
    for(i = 0 ; i < MAX ; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    
    // Done !
    return 0;
}
