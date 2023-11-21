#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " output.txt num_elements" << endl;
        return 1;
    }

    const int numElements = atoi(argv[2]);
    if (numElements <= 0) {
        cerr << "Error: Please provide a positive number of elements." << endl;
        return 1;
    }

    ofstream outputFile(argv[1]);
    if (!outputFile) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    // Seed for the random number generator
    srand(time(nullptr));

    // Generate random floating-point numbers and write to the file
    for (int i = 0; i < numElements; ++i) {
        float randomNumber = static_cast<float>(rand()) / RAND_MAX * 200 - 100; // Range: -100 to 100
        outputFile << fixed << setprecision(2) << randomNumber << " ";
    }

    outputFile.close();

    cout << "Random numbers generated and written to " << argv[1] << endl;

    return 0;
}
