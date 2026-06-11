#include <stdio.h>
#include <stdlib.h>
#include "analyzer.h"

int main(int argc, char *argv[]) {
    // Check for correct command-line usage
    if (argc != 2) {
        printf("Usage: %s <circuit_data_file.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Circuit c;
    printf("Parsing circuit file: %s...\n", argv[1]);
    
    // Step 1: Parse the file
    if (!parse_circuit_file(argv[1], &c)) {
        printf("Process aborted due to parsing error.\n");
        return EXIT_FAILURE;
    }

    printf("Successfully mapped %d independent nodes.\n", c.num_nodes);
    printf("Solving nodal matrices...\n\n");
    
    // Step 2: Calculate the voltages
    solve_nodal_voltages(&c);
    
    // Step 3: Print the results
    print_exact_results(&c);

    return EXIT_SUCCESS;
}
