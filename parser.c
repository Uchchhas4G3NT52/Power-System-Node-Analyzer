#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "analyzer.h"

/*
 * Reads the circuit configuration from a text file and builds the G-matrix and I-vector.
 * Returns 1 on success, 0 on failure.
 */
int parse_circuit_file(const char *filename, Circuit *c) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return 0;
    }

    // Initialize all matrices and vectors to exactly zero
    c->num_nodes = 0;
    memset(c->conductance, 0, sizeof(c->conductance));
    memset(c->current, 0, sizeof(c->current));
    memset(c->voltage, 0, sizeof(c->voltage));

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Ignore comments (#) and empty lines
        if (line[0] == '#' || line[0] == '\n') continue;

        if (strncmp(line, "NODES", 5) == 0) {
            sscanf(line, "NODES %d", &c->num_nodes);
            if (c->num_nodes > MAX_NODES) {
                printf("Error: Node count exceeds MAX_NODES (%d).\n", MAX_NODES);
                fclose(file);
                return 0;
            }
        } 
        // Parse Resistors (R)
        else if (line[0] == 'R') {
            int n1, n2;
            double resistance;
            sscanf(line, "R %d %d %lf", &n1, &n2, &resistance);
            
            if (resistance <= 0) {
                printf("Error: Invalid resistance value.\n");
                continue;
            }
            
            double g = 1.0 / resistance; // Convert resistance to conductance
            
            // Add to the diagonal elements
            if (n1 > 0) c->conductance[n1 - 1][n1 - 1] += g;
            if (n2 > 0) c->conductance[n2 - 1][n2 - 1] += g;
            
            // Subtract from the mutual elements
            if (n1 > 0 && n2 > 0) {
                c->conductance[n1 - 1][n2 - 1] -= g;
                c->conductance[n2 - 1][n1 - 1] -= g;
            }
        } 
        // Parse Current Sources (I)
        else if (line[0] == 'I') {
            int n_out, n_in;
            double current_val;
            // Format: I <node_leaving> <node_entering> <value>
            sscanf(line, "I %d %d %lf", &n_out, &n_in, &current_val);
            
            if (n_out > 0) c->current[n_out - 1] -= current_val; // Leaving node
            if (n_in > 0)  c->current[n_in - 1]  += current_val; // Entering node
        }
    }
    
    fclose(file);
    return 1;
}
