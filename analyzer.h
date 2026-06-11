#ifndef ANALYZER_H
#define ANALYZER_H

#define MAX_NODES 50

// Structure to hold the circuit matrix
typedef struct {
    int num_nodes;
    // G-matrix (Conductance)
    double conductance[MAX_NODES][MAX_NODES]; 
    // I-vector (Current sources)
    double current[MAX_NODES];                
    // V-vector (Calculated Voltages)
    double voltage[MAX_NODES];                
} Circuit;

// Function Prototypes
int parse_circuit_file(const char *filename, Circuit *c);
void solve_nodal_voltages(Circuit *c);
void print_exact_results(const Circuit *c);

#endif
