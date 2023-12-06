//
// Created by Jeon Hyeonbae on 2023/11/22.
//

#ifndef ALGORITHM_TEAM_6_DEPARTURE_SORT_H
#define ALGORITHM_TEAM_6_DEPARTURE_SORT_H

#include "sort.h"

// 파티션 함수
int dep_partition(object arr[], int left, int right )
{
    int pivot;
    object temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = arr[left].Ideparture;
    do {
        do
            low++;
        while (arr[low].Ideparture<pivot);
        do
            high--;
        while (arr[high].Ideparture>pivot);
        if (low<high) SWAP(&arr[low], &arr[high], &temp);
        } while (low<high);

    SWAP(&arr[left], &arr[high], &temp);
    return high;

    }

// 퀵정렬 함수
void dep_quicksort(object arr[], int left, int right)
{
    if (left<right){
        int pi = dep_partition(arr, left, right);
        dep_quicksort(arr, left, pi - 1);
        dep_quicksort(arr, pi + 1, right);
    }
}

void departure_sort(object obj[],int count)
{ dep_quicksort(obj,0,count); }
#endif //ALGORITHM_TEAM_6_DEPARTURE_SORT_H
