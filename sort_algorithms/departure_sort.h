//
// Created by Jeon Hyeonbae on 2023/11/22.
//

#ifndef ALGORITHM_TEAM_6_DEPARTURE_SORT_H
#define ALGORITHM_TEAM_6_DEPARTURE_SORT_H

#include "sort.h"

void departure(object obj[])
{
}

// 파티션 함수
int partition(object arr[], int left, int right )
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
        if (low<high) SWAP(arr[low], arr[high], temp);
        } while (low<high);

    SWAP(arr[left], arr[high], temp);
    return high;

    }



// 퀵정렬 함수
void quicksort(object arr[], int left, int right)
{
    for (int i = 0; i < 30000; ++i)
    {
     int a =    arr[i].Ideparture;
    }

    if (left<right){
        int pi = partition(arr, left, right);
        quicksort(arr, left, pi - 1);
        quicksort(arr, pi + 1, right);
    }
}
#endif //ALGORITHM_TEAM_6_DEPARTURE_SORT_H
