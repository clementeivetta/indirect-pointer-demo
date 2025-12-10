# Usage Instructions for Indirect Pointer Demo

## Overview

The Indirect Pointer Demo is a C project designed to demonstrate the behavior of indirect pointers during file operations. This project provides a simple way to observe when an indirect pointer is utilized in the context of writing data to a file.

## Prerequisites

Before running the project, ensure you have the following installed on your system:

- A C compiler (e.g., GCC)
- Make utility
- Git (for cloning the repository)

## Setup

1. **Clone the Repository**:
   To get a local copy of the project, run the following command in your terminal:
   ```
   git clone https://github.com/yourusername/indirect-pointer-demo.git
   ```

2. **Navigate to the Project Directory**:
   Change into the project directory:
   ```
   cd indirect-pointer-demo
   ```

3. **Build the Project**:
   Use the Makefile to compile the project:
   ```
   make
   ```

## Usage

Run the demo binary:
```
./indirect_pointer_demo
```

The application writes 4KiB blocks to `archivo`, printing:
- “+1 block written”
- “current file size: N bytes”
- and at iteration 15: “indirect pointer is about to be used”

## Cleanup

To remove the compiled files and clean up the project directory, run:
```
make clean
```

## Contributing

If you would like to contribute to this project, please refer to the `CONTRIBUTING.md` file for guidelines on how to report issues and submit pull requests.

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.