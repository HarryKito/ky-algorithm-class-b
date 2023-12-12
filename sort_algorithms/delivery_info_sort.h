//
// Created by Jeon Hyeonbae on 2023/11/22.
//

#ifndef ALGORITHM_TEAM_6_DELIVERY_INFO_SORT_H
#define ALGORITHM_TEAM_6_DELIVERY_INFO_SORT_H

#include "sort.h"
#include <string.h>

// 두 객체의 위치를 교환하는 함수
void info_swap(object* a, object* b) {
    object temp = *a;
    *a = *b;
    *b = temp;
}

// 무작위로 피벗을 선택하는 함수
int info_Random_Pivot(int low, int high) {
    srand(time(NULL));
    return low + rand() % (high - low + 1);
}

// 퀵정렬을 위한 파티션 함수
int info_partition(object arr[], int low, int high) {
    // 피벗을 중간값으로 선택
    int pivotIndex = info_Random_Pivot(low, high);
    info_swap(&arr[pivotIndex], &arr[high]);

    char* pivot = arr[high].info;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        // 비교 시에 아스키 코드를 직접 사용
        if (arr[j].info[0] < pivot[0] || (arr[j].info[0] == pivot[0] && atoi(arr[j].info + 1) < atoi(pivot + 1))) {
            i++;
            info_swap(&arr[i], &arr[j]);
        }
    }

    info_swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// info를 기준으로 퀵정렬을 수행하는 함수
void delivery_info(object arr[], int low, int high) {
    if (low < high) {
        int pi = info_partition(arr, low, high);

        delivery_info(arr, low, pi - 1);
        delivery_info(arr, pi + 1, high);
    }
}

#endif //ALGORITHM_TEAM_6_DELIVERY_INFO_SORT_H
