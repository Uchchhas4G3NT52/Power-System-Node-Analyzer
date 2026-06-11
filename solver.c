#include <stdio.h>
#include <math.h>
#include "analyzer.h"

/*
 * Solves the linear system G * V = I using Gauss-Jordan Elimination.
 * Modifies the input Circuit struct by populating the voltage array.
 */
void solve_nodal_voltages(Circuit *c) {
    int n = c->num_nodes;
    
    // Create an augmented matrix [G | I]
    // The dimensions are n rows by (n + 1) columns
    double aug[MAX_NODES][MAX_NODES + 1];

    // Step 1: Populate the augmented matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aug[i][j] = c->conductance[i][j];
        }
        aug[i][n] = c->current[i];
    }

    // Step 2: Gauss-Jordan Elimination with Partial Pivoting
    for (int i = 0; i < n; i++) {
        // Find the pivot row (row with the largest absolute value in the current column)
        int max_row = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(aug[k][i]) > fabs(aug[max_row][i])) {
                max_row = k;
            }
        }

        // Swap the current row with the pivot row
        if (max_row != i) {
            for (int j = 0; j <= n; j++) {
                double temp = aug[i][j];
                aug[i][j] = aug[max_row][j];
                aug[max_row][j] = temp;
            }
        }

        // Check for a singular matrix (e.g., an isolated node with no ground path)
        // 1e-12 is used as a tolerance threshold for zero in double precision
        if (fabs(aug[i][i]) < 1e-12) {
            printf("Error: Singular matrix detected. Check circuit connections for floating nodes.\n");
            return;
        }

        // Normalize the pivot row so the diagonal element becomes 1.0
        double pivot = aug[i][i];
        for (int j = 0; j <= n; j++) {
            aug[i][j] /= pivot;
        }

        // Eliminate the current variable from all other rows
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = aug[k][i];
                for (int j = 0; j <= n; j++) {
                    aug[k][j] -= factor * aug[i][j];
                }
            }
        }
    }

    // Step 3: Extract the solved voltages from the augmented column
    for (int i = 0; i < n; i++) {
        c->voltage[i] = aug[i][n];
    }
}

/*
 * Outputs the exact nodal voltages to the console.
 */
void print_exact_results(const Circuit *c) {
    printf("--- Nodal Analysis Results ---\n");
    for (int i = 0; i < c->num_nodes; i++) {
        // Node numbers are 1-indexed in real-world schematics, but 0-indexed in our arrays
        printf("Node %d Voltage: %10.6f V\n", i + 1, c->voltage[i]);
    }
    printf("------------------------------\n");
}
