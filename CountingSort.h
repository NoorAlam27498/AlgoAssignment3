#pragma once
#include <iostream>

void countingSort(int arr[], int n) {
    if (n <= 0) return;
    int minVal = arr[0], maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    int range = maxVal - minVal + 1;
    int* count = new int[range];
    for (int i = 0; i < range; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[arr[i] - minVal]++;
    }
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index++] = i + minVal;
            count[i]--;
        }
    }
    delete[] count;
}
