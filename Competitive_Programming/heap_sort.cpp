#include <iostream>

using namespace std;
// To heapify a subtree rooted with node i which
// is index of arr[] and n is the size of heap
void heapify(int arr[], int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  // If left child is larger than root
  if (l < n && arr[l] > arr[largest]) largest = l;

  // If right child largest than root
  if (r < n && arr[r] > arr[largest]) largest = r;

  // If root is not largest
  if (largest != i) {
    swap(arr[i], arr[largest]);

    // heapifying the sub-tree repeatedly
    heapify(arr, n, largest);
  }
}
// Main function to do the heap sort
void heapSort(int arr[], int n) {
  // Build max-heap
  for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

  // Extracting element from the heap
  for (int i = n - 1; i >= 0; i--) {
    // Moving current root to last element of          //the array
    swap(arr[0], arr[i]);

    // Calling max heapify on the shrink heap
    heapify(arr, i, 0);
  }
}

// Function to print elements of the array
void Print(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << "\t";
  }
  cout << "\n";
}

int main() {
  int arr[] = {2, 1, 12, 14, 8};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Before Sorting  \n";
  Print(arr, n);

  heapSort(arr, n);

  cout << "After Sorting the array looks like:  \n";
  Print(arr, n);
}
