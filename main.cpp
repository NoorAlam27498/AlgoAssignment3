#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "BubbleSort.h"
#include"BucketSort.h"
#include"CountingSort.h"
#include"HeapSort.h"
#include"InsertionSort.h"
#include"MergeSort.h"
#include"QuickSort.h"
#include"RedixSort.h"
#include <chrono>



void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::ifstream file("data.csv"); 
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file.\n";
        return 1;
    }

    std::string line;
    std::vector<int> values;

    if (std::getline(file, line)) {
    }
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        int num;
        if (ss >> num) {
            values.push_back(num);
        }
    }
    file.close();
    int n = values.size();
    int newnsquare = double(n) * 0.05;
    int newnlogn = double(n) * 0.10;
    int* arrnsquare = new int[newnsquare];
    for (int i = 0; i < newnsquare; i++) {
        arrnsquare[i] = values[i];
    }
    int* arrnlogn = new int[newnlogn];
    for (int i = 0; i < newnlogn; i++) {
        arrnlogn[i] = values[i];
    }
    /*std::cout << "Data from CSV:\n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << "\n";
    }*/

    int choice;

    std::cout << "==== Sorting Algorithms Menu ====\n";
    std::cout << "1. Insertion Sort\n";
    std::cout << "2. Bubble Sort\n";
    std::cout << "3. Merge Sort\n";
    std::cout << "4. Heap Sort\n";
    std::cout << "5. Quick Sort\n";
    std::cout << "6. Counting Sort\n";
    std::cout << "7. Radix Sort\n";
    std::cout << "8. Bucket Sort\n";
    std::cout << "=================================\n";

    // Input validation loop
    while (true) {
        std::cout << "Enter your choice (1-8): ";
        if (std::cin >> choice) {
            if (choice >= 1 && choice <= 8) {
                break; // valid input
            }
            else {
                std::cout << "Invalid choice! Please enter a number between 1 and 8.\n";
            }
        }
        else {
            // Handle non-integer input
            std::cout << "Invalid input! Please enter a valid number.\n";
            std::cin.clear(); // clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard bad input
        }
    }
    auto start = std::chrono::high_resolution_clock::now();
    // Menu handling with if-else
    if (choice == 1) {
        std::cout << "You chose Insertion Sort.\n";
        insertionSort(arrnsquare, newnsquare);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Elapsed time: " << duration.count() << " ms" << std::endl;
    }
    else if (choice == 2) {
        std::cout << "You chose Bubble Sort.\n";

        bubbleSort(arrnsquare, newnsquare);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Elapsed time: " << duration.count() << " ms" << std::endl;
    }
    else if (choice == 3) {
        std::cout << "You chose Merge Sort.\n";
        mergeSort(arrnlogn, 0, newnlogn - 1);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Elapsed time: " << duration.count() << " ms" << std::endl;
    }
    else if (choice == 4) {
        std::cout << "You chose Heap Sort.\n";
        heapSort(arrnlogn, newnlogn);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Elapsed time: " << duration.count() << " ms" << std::endl;
    }
    else if (choice == 5) {
        std::cout << "You chose Quick Sort.\n";
        quickSort(arrnlogn, 0, newnlogn - 1);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Elapsed time: " << duration.count() << " ms" << std::endl;
    }
    else if (choice == 6) {
        std::cout << "You chose Counting Sort.\n";
        countingSort(arrnlogn, newnlogn);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Elapsed time: " << duration.count() << " ms" << std::endl;
    }
    else if (choice == 7) {
        std::cout << "You chose Radix Sort.\n";
        radixSort(arrnlogn, newnlogn);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Elapsed time: " << duration.count() << " ms" << std::endl;
    }
    else if (choice == 8) {
        std::cout << "You chose Bucket Sort.\n";
        bucketSort(arrnlogn, newnlogn);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Elapsed time: " << duration.count() << " ms" << std::endl;
    }






    return 0;
}
