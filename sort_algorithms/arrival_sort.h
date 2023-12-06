//
// Created by Jeon Hyeonbae on 2023/11/22.
//

#ifndef ALGORITHM_TEAM_6_ARRIVAL_SORT_H
#define ALGORITHM_TEAM_6_ARRIVAL_SORT_H

#include "sort.h"
// 파티션 함수
int ari_partition(object arr[], int left, int right )
{
    int pivot;
    object temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = arr[left].Iarrival;
    do {
        do
            low++;
        while (arr[low].Iarrival<pivot);
        do
            high--;
        while (arr[high].Iarrival>pivot);
        if (low<high) SWAP(&arr[low], &arr[high], &temp);
    } while (low<high);

    SWAP(&arr[left], &arr[high], &temp);
    return high;
}

// 퀵정렬 함수
void ari_quicksort(object arr[], int left, int right)
{
    if (left<right){
        int pi = ari_partition(arr, left, right);
        ari_quicksort(arr, left, pi - 1);
        ari_quicksort(arr, pi + 1, right);
    }
}

// 도착정보
void arrival_sort(object obj[],int count)
{ ari_quicksort(obj,0,count); }
#endif //ALGORITHM_TEAM_6_ARRIVAL_SORT_H
