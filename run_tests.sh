#!/bin/bash

# Compile your QuickSort program
g++ -o quicksort_median_of_three Shah_Harshil_quicksort.cpp

# Compile your InputFileGenerator program
g++ -o inputfilegenerator InputFileGenerator.cpp

# Define input sizes
input_sizes=(10 100 1000)

# Loop through each input size
for size in "${input_sizes[@]}"; do
    # Generate 25 input files for each size
    for i in {1..25}; do
        ./inputfilegenerator input_${size}_$i.txt $size
        ./quicksort_median_of_three input_${size}_$i.txt output_${size}_$i.txt
    done

    # Record execution times in a file
    echo -e "Input Size\tExecution Time" > Shah_Harshil_executionTime.txt
    for i in {1..25}; do
        time=$(./quicksort_median_of_three input_${size}_$i.txt output_${size}_$i.txt | grep "Execution Time" | awk '{print $4}')
        echo -e "$size\t$time" >> Shah_Harshil_executionTime.txt
    done

    # Compute average execution time
    average_time=$(awk '{sum += $2} END {print sum / NR}' Shah_Harshil_executionTime.txt)

    # Record average execution time in a separate file
    echo -e "Input Size\tAverage Execution Time" > Shah_Harshil_averageExecutionTime.txt
    echo -e "$size\t$average_time" >> Shah_Harshil_averageExecutionTime.txt
done

# Clean up - remove temporary files
rm -f quicksort_median_of_three inputfilegenerator
