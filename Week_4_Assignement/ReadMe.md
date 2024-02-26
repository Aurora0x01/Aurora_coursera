## C Code for Reading File, Calculating Stats, and Printing to File

This repository contains C code that reads an integer array from a file, calculates its average and maximum value, and prints the results to the console and an output file.

### Instructions:

1. **Create a file named `data.txt`** with the following format:
    * The first line should contain an integer representing the number of elements in the array.
    * The remaining lines should each contain a single integer.

2. **Compile the code:**
    * Save the code as `read_file.c`.
    * Compile the code using a C compiler like GCC:
    ```bash
    gcc read_file.c -o read_file
    ```

3. **Run the code:**
    * Execute the compiled binary:
    ```bash
    ./read_file
    ```

### Explanation:

The code performs the following steps:

1. Opens the `data.txt` file for reading.
2. Reads the number of elements from the first line.
3. Allocates memory for an integer array based on the number of elements.
4. Reads the remaining lines of the file, storing the integer values in the array.
5. Calculates the sum and the maximum value of the elements in the array.
6. Calculates the average by dividing the sum by the number of elements.
7. Prints the array size, data elements, average, and maximum value to the console.
8. Opens an output file named `answer-hw3.txt` for writing.
9. Writes the same results (array size, data elements, average, and maximum value) to the output file.
10. Closes both the input and output files.

### Additional Notes:

* The code assumes that the input file is named `data.txt` and the output file is named `answer-hw3.txt`. You can modify these names as needed.
* The code includes error handling for opening the input and output files.
* The code uses clear comments to explain each step of the process.

**Feel free to modify and extend the code as needed.**
