#include <bits/stdc++.h>
using namespace std;

// Below is the code for Merge Sort which is Based on Divide And Conquer Technique

// Time Complexity Analysis:
// Best Case:O(n*logn)
// Worst Case:O(n*logn)
// Average Case:O(n*logn)



/**
 * Merges two sorted sub-arrays into a single sorted array.
 * This is the "Conquer" step of the Merge Sort algorithm.
 * *  arr The main array containing the sub-arrays.
 *  left Start index of the first sub-array.
 *  mid End index of the first sub-array (and start of the second sub-array is mid + 1).
 *  right End index of the second sub-array.
 */
void merge(vector<int>& arr, int left, int mid, int right) {
    // Determine the size of the two sub-arrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    
    vector<int> L(n1);
    vector<int> R(n2);

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temp arrays back into arr[left..right]
    int i = 0; // Initial index of first sub-array
    int j = 0; // Initial index of second sub-array
    int k = left; // Initial index of merged sub-array

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/**
 * Recursive function that sorts the array by dividing it into two halves,
 * recursively calling itself for the halves, and then merging the two halves.
 * This is the "Divide" step of the Merge Sort algorithm.
 * * Time Complexity: O(n log n)
 * Space Complexity: O(n) due to temporary arrays created during merging

 */
void mergeSortRecursive(vector<int>& arr, int left, int right) {
    // Base Case: If the segment has one or zero elements, it is already sorted.
    if (left >= right) {
        return;
    }

    // Find the middle point
    int mid = left + (right - left) / 2;

    // Recursively sort the first half
    mergeSortRecursive(arr, left, mid);

    // Recursively sort the second half
    mergeSortRecursive(arr, mid + 1, right);

    // Merge the two sorted halves
    merge(arr, left, mid, right);
}



// Code For Printing the values in the vector
void printArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {

    // Test Data
    vector<int> data = {12, 11, 13, 5, 6, 7};
    int n = data.size();

    cout << "Given array is " << endl;
    printArray(data);

    // Call the recursive Merge Sort function
    mergeSortRecursive(data, 0, n - 1);

    cout << " Sorted array is " <<endl;
    printArray(data);

    return 0;
}