# High Performance Matrices C++

A high-performance C++ program for dynamic allocation and manipulation of large matrices, capable of handling up to 10,000×10,000 matrices (100 million elements).

## Features

- **Dynamic Memory Allocation**: Efficient memory management using triple pointers for 2D arrays
- **Large-Scale Operations**: Successfully handles matrices up to 10,000×10,000 elements
- **Random Population**: Uses modern C++ random library for matrix initialization
- **Performance Benchmarking**: Built-in timing analysis for optimization studies
- **Memory Efficient**: Optimized allocation strategies for minimal memory overhead

## Performance Results

| Matrix Size | Elements | Memory Usage | Execution Time |
|-------------|----------|--------------|----------------|
| 10,000×10,000 | 100,000,000 | ~800MB | 29 seconds |

*Tested on: XPS 13 9310*

## Technical Implementation

### Memory Management
- Uses triple pointer allocation (`int***`) for dynamic 2D arrays
- Supports both contiguous and non-contiguous allocation methods
- Proper deallocation to prevent memory leaks
- Handles large memory footprints (400MB+ per matrix)

### Random Number Generation
- Modern C++ `<random>` library implementation
- Configurable distribution ranges
- Efficient population of large datasets

## Building and Running

### Prerequisites
- C++ compiler with C++11 support or later
- Sufficient RAM (1GB+ recommended for large matrices)

### Compilation
```bash
g++ -std=c++11 -O2 -o matrix_program main.cpp
```

### Usage
```bash
./matrix_program
```

## Code Structure

```
├── main.cpp              # Main program entry point
└── README.md            # This file
```

## Key Functions
- `allocateMatrix`
- `deallocateMatrix`
- `PopulateMatrix`
- `PopulateEmptyMatrix`
- `addMatrices`
- `PrintMatrix`


## Future Enhancements

- [ ] Multithreading optimization for population and operations
- [ ] Matrix arithmetic operations (addition, multiplication)
- [ ] Different allocation method comparisons
- [ ] Memory usage profiling
- [ ] Cache performance analysis
- [ ] Template-based implementation for different data types

## Memory Usage Breakdown

For two 10,000×10,000 integer matrices:
- **Data storage**: ~400MB per matrix
- **Row pointers**: ~40KB per matrix  
- **Total**: ~800MB+ for complete program

## Performance Notes

- Execution time scales approximately O(n²) with matrix dimensions
- Memory allocation strategy significantly impacts performance at large scales
- Random number generation represents a significant portion of execution time

## Learning Outcomes

This project demonstrates:
- Advanced memory management in C++
- Performance considerations for large-scale data structures
- Modern C++ standard library usage
- System-level programming concepts
- Empirical performance analysis

## License

GNU LISCENSE

---

**Note**: This program is designed for educational purposes and performance analysis. For production use, consider established linear algebra libraries like Eigen or BLAS.
