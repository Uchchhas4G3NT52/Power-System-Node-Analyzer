

A fast, memory-efficient command-line tool written in C for solving DC circuit nodal voltages. It utilizes Kirchhoff's Current Law (KCL) and Gauss-Jordan elimination to parse text-based circuit netlists and output exact voltage drops and current flows without rounding errors.

## 🚀 Features
* **Command-Line Interface:** Easy to run and integrate into automated scripts.
* **Exact Nodal Analysis:** Implements Gauss-Jordan Elimination with Partial Pivoting to prevent division-by-zero and minimize floating-point errors.
* **Dynamic Parsing:** Reads circuit network topologies directly from simple `.txt` files.

## 📂 Repository Structure

```

```text
README.md created successfully

```text
Power-System-Node-Analyzer/
├── analyzer.h          # Struct definitions and function prototypes
├── main.c              # Entry point and execution flow
├── parser.c            # Reads and parses the input circuit data
├── solver.c            # Mathematical engine (Gauss-Jordan elimination)
├── test_circuit.txt    # Sample node data for testing
└── Makefile            # Build configuration

```

## ⚙️ Prerequisites

To compile and run this project, you will need:

* **Git:** To clone the repository to your local machine.
* **C Compiler:** `gcc` (MinGW-w64 or MSYS2 recommended for Windows users, native GCC for Linux/macOS).
* **Make:** To automate the build process.

## 🛠️ Installation & Compilation

Follow these exact steps to get the project running on your local machine:

1. **Clone the repository:**
```bash
git clone [https://github.com/Uchchhas4G3NT52/Power-System-Node-Analyzer.git](https://github.com/Uchchhas4G3NT52/Power-System-Node-Analyzer.git)

```


2. **Navigate to the project directory:**
```bash
cd Power-System-Node-Analyzer

```


3. **Compile the code using Make:**
```bash
make

```


*This command will compile the C source files and generate an executable named `analyzer` (or `analyzer.exe` on Windows).*

## ▶️ Usage

Once compiled, run the executable and pass your circuit configuration file as the required command-line argument.

**For Windows (Command Prompt / PowerShell):**

```bash
.\\analyzer.exe test_circuit.txt

```

**For Git Bash / Linux / macOS:**

```bash
./analyzer test_circuit.txt

```

## 📝 Input File Format (`test_circuit.txt`)

The tool is designed to read plain text files formatted with specific syntax:

* `NODES <count>`: Defines the total number of independent nodes (excluding Ground / Node 0).
* `R <node1> <node2> <resistance>`: Defines a resistor (in Ohms) connected between two nodes.
* `I <node_leaving> <node_entering> <current>`: Defines an independent current source (in Amps).

**Example Circuit Netlist:**

```text
# Total nodes in the circuit
NODES 3

# Resistor configurations
R 1 0 10.0
R 1 2 5.0
R 2 3 2.0
R 3 0 4.0

# Current sources
I 0 1 2.5
I 2 3 1.0

```

## 🧹 Maintenance

To clean up the compiled object files and the executable from your directory, simply run:

```bash
make clean

```

""")
print("README.md created successfully")

```
Your Markdown (MD) file is ready
[file-tag: code-generated-file-0-1781186252469197089]

Here is the complete `README.md` file formatted specifically for your GitHub repository. It includes all the necessary badges, structured code blocks, and the step-by-step instructions from our guide.

**How to add this to your GitHub repository:**
1. On your GitHub repository page, click the pencil icon ✏️ on the `README.md` file that you currently have.
2. Delete any existing text in that file.
3. Open the downloaded `README.md` file provided above, copy all the text, and paste it into the GitHub editor.
4. Click **"Commit changes..."** in the top right corner.

This structure will immediately make your repository look highly professional to anyone visiting the page. Let me know if you need any adjustments to the descriptions or formatting!

```
