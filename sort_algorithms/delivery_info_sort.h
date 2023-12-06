//
// Created by Jeon Hyeonbae on 2023/11/22.
//

#ifndef ALGORITHM_TEAM_6_DELIVERY_INFO_SORT_H
#define ALGORITHM_TEAM_6_DELIVERY_INFO_SORT_H

#include "sort.h"
#include <string.h>

// 퀵정렬을 위한 파티션 함수
int del_partition(object arr[], int low, int high) {
    char pivot[3];
    strncpy(pivot, arr[high].info, 3);
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (strncmp(arr[j].info, pivot, 3) < 0) {
            i++;
            // 구조체 교환
            object temp = arr[i];
//            arr[i] = arr[j];
//            arr[j] = temp;
            SWAP(&arr[i + 1],&arr[high],&temp);
        }
    }

    // 구조체 교환
    object temp = arr[i + 1];
//    arr[i + 1] = arr[high];
//    arr[high] = temp;
    SWAP(&arr[i + 1],&arr[high],&temp);

    return i + 1;
}

// 퀵 정렬 함수
void del_quickSort(object arr[], int low, int high) {
    if (low < high) {
        int pi = del_partition(arr, low, high);
        del_quickSort(arr, low, pi - 1);
        del_quickSort(arr, pi + 1, high);
    }
}

void delivery_info(object obj[],int count)
{ del_quickSort(obj, 0, count - 1); }

#endif //ALGORITHM_TEAM_6_DELIVERY_INFO_SORT_H
