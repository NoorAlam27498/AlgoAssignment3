#pragma once
#include <iostream>

int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void countingSortByDigit(int arr[], int n, int exp) {
    int* output = new int[n];
    int count[10] = { 0 };
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    delete[] output;
}

void radixSortNonNegative(int arr[], int n) {
    int maxVal = getMax(arr, n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortByDigit(arr, n, exp);
    }
}

void radixSort(int arr[], int n) {
    int negCount = 0, posCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) negCount++;
        else posCount++;
    }
    int* negArr = new int[negCount];
    int* posArr = new int[posCount];
    int ni = 0, pi = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) negArr[ni++] = -arr[i];
        else posArr[pi++] = arr[i];
    }
    if (posCount > 0) {
        radixSortNonNegative(posArr, posCount);
    }
    if (negCount > 0) {
        radixSortNonNegative(negArr, negCount);
        for (int i = 0; i < negCount / 2; i++) {
            int temp = negArr[i];
            negArr[i] = negArr[negCount - i - 1];
            negArr[negCount - i - 1] = temp;
        }
    }
    int idx = 0;
    for (int i = 0; i < negCount; i++) {
        arr[idx++] = -negArr[i];
    }
    for (int i = 0; i < posCount; i++) {
        arr[idx++] = posArr[i];
    }
    delete[] negArr;
    delete[] posArr;
}
