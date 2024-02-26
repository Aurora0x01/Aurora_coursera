#include <stdio.h>

int main() {
    FILE *fp;
    int num_elements, i, max;
    double sum, average;

    // Open the file for reading
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read the number of elements from the first line
    fscanf(fp, "%d", &num_elements);

    // Allocate memory for the integer array
    int data[num_elements];

    // Initialize variables
    sum = 0.0;
    max = data[0]; // Assuming the first element is the max initially

    // Read the remaining elements into the array
    for (i = 0; i < num_elements; i++) {
        fscanf(fp, "%d", &data[i]);

        // Update max if necessary
        if (data[i] > max) {
            max = data[i];
        }

        // Add to the sum for calculating the average
        sum += data[i];
    }

    // Calculate the average
    average = sum / num_elements;

    // Close the file
    fclose(fp);

    // Print the results to the console
    printf("Array size: %d\n", num_elements);
    printf("Data: ");
    for (i = 0; i < num_elements; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    printf("Average: %.2lf\n", average);
    printf("Maximum: %d\n", max);

    // Open the output file for writing
    fp = fopen("answer-hw3.txt", "w");
    if (fp == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    // Write the results to the output file
    fprintf(fp, "Array size: %d\n", num_elements);
    fprintf(fp, "Data: ");
    for (i = 0; i < num_elements; i++) {
        fprintf(fp, "%d ", data[i]);
    }
    fprintf(fp, "\n");
    fprintf(fp, "Average: %.2lf\n", average);
    fprintf(fp, "Maximum: %d\n", max);

    // Close the output file
    fclose(fp);

    return 0;
}
