//
// Created by Jeon Hyeonbae on 2023/11/22.
//

#ifndef ALGORITHM_TEAM_6_DELIVERY_INFO_SORT_H
#define ALGORITHM_TEAM_6_DELIVERY_INFO_SORT_H

#include "sort.h"
#include <string.h>

// A, B, C, D를 1, 2, 3, 4로 변환하는 함수
int convert_to_numeric(char c) {
    return c - 'A' + 1;
}

// 1, 2, 3, 4를 A, B, C, D로 변환하는 함수
char convert_to_char(int num) {
    return num + 'A' - 1;
}

// 특별한 퀵정렬을 위한 파티션 함수
int del_partition(object arr[], int low, int high) {
    // A, B, C, D를 1, 2, 3, 4로 매핑
    char pivot = arr[high].info[0];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].info[0] < pivot) {
            i++;
            // 구조체 필드만 변경
            arr[i].info[0] = convert_to_char(convert_to_numeric(arr[i].info[0]));
            arr[j].info[0] = convert_to_char(convert_to_numeric(arr[j].info[0]));
            // 나머지 필드도 동일하게 처리 가능
        }
    }

    // 구조체 필드만 변경
    arr[i + 1].info[0] = convert_to_char(convert_to_numeric(arr[i + 1].info[0]));
    arr[high].info[0] = convert_to_char(convert_to_numeric(arr[high].info[0]));

    return i + 1;
}

// 특별한 퀵 정렬 함수
void del_quickSort(object arr[], int low, int high) {
    if (low < high) {
        int pi = del_partition(arr, low, high);
        del_quickSort(arr, low, pi - 1);
        del_quickSort(arr, pi + 1, high);
    }
}

#endif //ALGORITHM_TEAM_6_DELIVERY_INFO_SORT_H
