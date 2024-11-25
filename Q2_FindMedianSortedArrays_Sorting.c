#include <stdio.h>

// Function to find the median of two sorted arrays
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Combine both arrays into a single array
    int arr[nums1Size + nums2Size];
    for (int i = 0; i < nums1Size; i++) {
        arr[i] = nums1[i];
    }
    for (int i = 0; i < nums2Size; i++) {
        arr[nums1Size + i] = nums2[i];
    }

    // Sort the combined array using a simple bubble sort
    for (int i = 0; i < nums1Size + nums2Size; i++) {
        for (int j = i + 1; j < nums1Size + nums2Size; j++) {
            if (arr[i] > arr[j]) {
                // Swap elements using arithmetic operations
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
    }

    // Find the median
    if ((nums1Size + nums2Size) % 2 == 0) {
        // If total number of elements is even, return the average of the two middle elements
        int l = (nums1Size + nums2Size) / 2;
        return (arr[l] + arr[l - 1]) / 2.0;
    } else {
        // If total number of elements is odd, return the middle element
        return arr[(nums1Size + nums2Size) / 2];
    }
}

// Main function for testing the findMedianSortedArrays function
int main() {
    // Input size of the first array
    int n1;
    printf("Enter the size of the first array: ");
    scanf("%d", &n1);

    // Dynamically allocate memory for the first array
    int* nums1 = (int*)malloc(n1 * sizeof(int));
    printf("Enter elements of the first array:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &nums1[i]);
    }

    // Input size of the second array
    int n2;
    printf("Enter the size of the second array: ");
    scanf("%d", &n2);

    // Dynamically allocate memory for the second array
    int* nums2 = (int*)malloc(n2 * sizeof(int));
    printf("Enter elements of the second array:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &nums2[i]);
    }

    // Call the function to find the median and display the result
    double median = findMedianSortedArrays(nums1, n1, nums2, n2);
    printf("The median of the combined sorted arrays is: %.2f\n", median);

    // Free allocated memory
    free(nums1);
    free(nums2);

    return 0;
}

