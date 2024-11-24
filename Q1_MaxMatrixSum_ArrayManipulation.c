#include <limits.h> // For INT_MAX
#include <stdlib.h> // For abs()

int min(int a, int b) {
    return (a < b) ? a : b;
}

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