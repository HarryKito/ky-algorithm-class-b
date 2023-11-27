#ifndef CLASS_B
#define CLASS_B

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "sort_algorithms/sort.h"
#include "csvReader.h"
#include "sort_algorithms/date_sort.h"

//          0 : data/del.csv 파일
//  file name : 데이터 파일 지정 (필요시)
FILE *openFile(char* file)
{
    FILE *fp;			    //파일 객체를 담을 변수
    file = !file ? "./data/del.csv" : file;

    //파일 읽기, 만약 파일을 읽을 수 없다면 종료.
    if(!(fp = fopen(file,"r")))
    {
        fputs("데이터셋을 읽을 수 없음.",stderr);
        exit(1);
    }
    else
    {
        puts("Read file success");
        return fp;
    }
}

/*
 * TODO: 목표
 *  program {분류형식}에 따라서 나열해줌.
 */
/* 프로그램 실행 시 입력된 인자, 분류형식에 따라 분류하는 부가적 부분 */
int sort_by_args(int argc,char** argv)
{
    if (argc > 2)
        for (int i = 0; i < argc; ++i)
            printf("argv : {%s}",argv[i]);
    else
        puts("입력된 인자 없음.");
}

// 구조체 정의
typedef struct {
    long data_num;
    int date;
    char departure[4];
    char arrival[4];
    char info[3];
} obj;

// 퀵정렬을 위한 파티션 함수
int partition(object arr[], int low, int high) {
    char pivot[3];
    strncpy(pivot, arr[high].info, 3);
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (strncmp(arr[j].info, pivot, 3) < 0) {
            i++;
            // 구조체 교환
            object temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // 구조체 교환
    object temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// 퀵 정렬 함수
void quickSort(object arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

#endif
