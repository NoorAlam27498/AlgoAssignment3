#pragma once
#include <iostream>
#include "InsertionSort.h"


void bucketSort(int arr[], int n) {
    if (n <= 0) return;
    int minVal = arr[0], maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    int bucketCount = n;
    int range = maxVal - minVal + 1;
    int** buckets = new int* [bucketCount];
    int* bucketSizes = new int[bucketCount];
    int* bucketCapacities = new int[bucketCount];

    for (int i = 0; i < bucketCount; i++) {
        bucketSizes[i] = 0;
        bucketCapacities[i] = 2;
        buckets[i] = new int[bucketCapacities[i]];
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = ((arr[i] - minVal) * bucketCount) / range;
        if (bucketIndex >= bucketCount) bucketIndex = bucketCount - 1;
        if (bucketSizes[bucketIndex] == bucketCapacities[bucketIndex]) {
            bucketCapacities[bucketIndex] *= 2;
            int* newBucket = new int[bucketCapacities[bucketIndex]];
            for (int j = 0; j < bucketSizes[bucketIndex]; j++) {
                newBucket[j] = buckets[bucketIndex][j];
            }
            delete[] buckets[bucketIndex];
            buckets[bucketIndex] = newBucket;
        }
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
        delete[] buckets[i];
    }
    delete[] buckets;
    delete[] bucketSizes;
    delete[] bucketCapacities;
}