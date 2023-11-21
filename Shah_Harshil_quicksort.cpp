#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

// Function to find the median of three values
double medianOfThree(double a, double b, double c) {
    if ((a <= b && b <= c) || (c <= b && b <= a))
        return b;
    else if ((b <= a && a <= c) || (c <= a && a <= b))
        return a;
    else
        return c;
}

// Function to partition the array using the median-of-three pivot
int partition(std::vector<double>& arr, int low, int high) {
    double pivot = medianOfThree(arr[low], arr[(low + high) / 2], arr[high]);

    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        // Swap arr[i] and arr[j]
        std::swap(arr[i], arr[j]);
    }
}

// Function to perform quicksort with median-of-three
void quicksort(std::vector<double>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the two halves
        quicksort(arr, low, pivotIndex);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
        return 1;
    }

    // Open the input file
    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cerr << "Error: Unable to open input file" << std::endl;
        return 1;
    }

    // Read input values from the file into a vector
    std::vector<double> values;
    double value;
    while (inputFile >> value) {
        values.push_back(value);
    }

    // Close the input file
    inputFile.close();

    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now();

    // Perform quicksort with median-of-three
    quicksort(values, 0, values.size() - 1);

    // Stop measuring time
    auto stop = std::chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

    // Open the output file for sorted values
    std::ofstream outputFile(argv[2]);
    if (!outputFile) {
        std::cerr << "Error: Unable to open output file" << std::endl;
        return 1;
    }

    // Write sorted values to the output file
    for (double val : values) {
        outputFile << val << " ";
    }
    outputFile << "\nExecution Time (microseconds): " << duration;

    // Close the output file for sorted values
    outputFile.close();

    std::cout << "Sorting complete. Sorted values written to " << argv[2] << std::endl;

    // Open the output file for execution time
    std::ofstream executionTimeFile("Shah_Harshil_executiontime.txt");
    if (!executionTimeFile) {
        std::cerr << "Error: Unable to open execution time file" << std::endl;
        return 1;
    }

    // Write the execution time to the output file
    executionTimeFile << "Execution Time (microseconds): " << duration;

    // Close the output file for execution time
    executionTimeFile.close();

    std::cout << "Execution time written to executiontime.txt" << std::endl;

    return 0;
}