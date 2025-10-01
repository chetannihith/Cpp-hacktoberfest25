#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Merge Sort Algorithm
 * Time Complexity: O(n log n) in all cases
 * Space Complexity: O(n)
 * 
 * Merge Sort is a divide-and-conquer algorithm that divides the array
 * into two halves, recursively sorts them, and then merges the sorted halves.
 */

/**
 * Merge function to merge two sorted subarrays
 * arr[left...mid] and arr[mid+1...right]
 */
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back into arr[left...right]
    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray
    
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

/**
 * Main merge sort function
 * Recursively divides the array and sorts it
 */
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;
        
        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

/**
 * Utility function to print array
 */
void printArray(const vector<int>& arr, const string& message) {
    cout << message;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

/**
 * Function to create a copy of original array for testing
 */
vector<int> copyArray(const vector<int>& original) {
    return vector<int>(original);
}

int main() {
    cout << "\n=== Merge Sort Algorithm Demonstration ===\n" << endl;
    
    // Test data
    vector<int> originalArr = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42, 30, 5, 77, 55};
    
    printArray(originalArr, "Original array: ");
    cout << endl;
    
    // Test Merge Sort
    vector<int> arr = copyArray(originalArr);
    mergeSort(arr, 0, arr.size() - 1);
    printArray(arr, "Merge Sort result: ");
    
    cout << "\n=== Performance Analysis ===\n";
    cout << "Time Complexity: O(n log n) in all cases (best, average, and worst)" << endl;
    cout << "Space Complexity: O(n)" << endl;
    cout << "\n=== Characteristics ===\n";
    cout << "- Stable sort: Yes (maintains relative order of equal elements)" << endl;
    cout << "- Adaptive: No (always performs the same number of comparisons)" << endl;
    cout << "- Best for: Large datasets, linked lists, external sorting" << endl;
    cout << "- Divide and Conquer approach" << endl;
    
    // Test with edge cases
    cout << "\n=== Testing Edge Cases ===\n";
    
    // Empty array
    vector<int> emptyArr = {};
    mergeSort(emptyArr, 0, emptyArr.size() - 1);
    printArray(emptyArr, "Empty array: ");
    
    // Single element
    vector<int> singleArr = {42};
    mergeSort(singleArr, 0, singleArr.size() - 1);
    printArray(singleArr, "Single element: ");
    
    // Already sorted
    vector<int> sortedArr = {1, 2, 3, 4, 5};
    mergeSort(sortedArr, 0, sortedArr.size() - 1);
    printArray(sortedArr, "Already sorted: ");
    
    // Reverse sorted
    vector<int> reverseArr = {5, 4, 3, 2, 1};
    mergeSort(reverseArr, 0, reverseArr.size() - 1);
    printArray(reverseArr, "Reverse sorted: ");
    
    // Duplicate elements
    vector<int> duplicateArr = {5, 2, 8, 2, 9, 1, 5, 5};
    mergeSort(duplicateArr, 0, duplicateArr.size() - 1);
    printArray(duplicateArr, "With duplicates: ");
    
    return 0;
}
