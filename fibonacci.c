#include <stdio.h>
#include <stdlib.h>

void generate_fibonacci(int n) {
    int fib = 0, b = 1, next;

    printf("Fibonacci series of %d terms:\n", n);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", fib);
        // add your code here. The fib value will change for each i and print
        // do not alter any of the printf functions. 
    }
    printf("\n");
}

int main(int argc, char** argv) {
    FILE *input_fp;

    if (argc >= 2) {
        input_fp = fopen(argv[1], "r");
    

        if (input_fp == NULL) {
            fprintf(stderr, "Error: Could not open input file.\n");
            return EXIT_FAILURE;
        }

        char buffer[255];
        int number = -1;

        // Read lines and extract a valid integer between 5 and 10
        while (fgets(buffer, sizeof(buffer), input_fp)) {
            if (sscanf(buffer, "%d", &number) == 1 && number >= 5 && number <= 10) {
                break;
            }
        }

        fclose(input_fp);  // Close the input file

        if (number < 5 || number > 10) {
            fprintf(stderr, "Error: No valid number (5-10) found in the input file.\n");
            return EXIT_FAILURE;
        }

        // Generate and print the Fibonacci series
        generate_fibonacci(number);
    }
    return 0;
}
