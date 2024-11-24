#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MAX

// Function to return the smaller of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to calculate the maximum matrix sum
long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize; // Number of rows
    long long sum = 0; // To store the sum of absolute values
    int mi = INT_MAX; // Smallest absolute value (initialized to a large value)
    int count = 0; // To count the number of negative elements

    // Traverse the matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            // Add absolute value to the sum
            sum += abs(matrix[i][j]);

            // Update the minimum absolute value
            mi = min(mi, abs(matrix[i][j]));

            // Count negatives
            if (matrix[i][j] < 0) {
                count++;
            }
        }
    }

    // If there is an even number of negatives, we can flip all signs
    if (count % 2 == 0) {
        return sum;
    } else {
        // Otherwise, one negative must remain; subtract twice the smallest absolute value
        return sum - 2 * mi;
    }
}

// Main function for testing
int main() {
    int rows, cols;

    // Input matrix dimensions
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Dynamically allocate memory for the matrix
    int** matrix = (int**)malloc(rows * sizeof(int*));
    int* matrixColSize = (int*)malloc(rows * sizeof(int));

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        matrixColSize[i] = cols;
    }

    // Input matrix elements
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Call the maxMatrixSum function
    long long result = maxMatrixSum(matrix, rows, matrixColSize);

    // Print the result
    printf("Maximum Matrix Sum: %lld\n", result);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(matrixColSize);

    return 0;
}
