//
// Created by Jeon Hyeonbae on 2023/11/22.
//

#ifndef ALGORITHM_TEAM_6_DATE_SORT_H
#define ALGORITHM_TEAM_6_DATE_SORT_H

#include "sort.h"
#include <stdio.h>

/*
 * //TODO: 날짜정렬 알고리즘 설정
 *      1. 연도별 정렬, 해당하는 갯수만큼 할당.
 *      2. 각 연도별 내에서 기수정렬 형태를 사용.
 *      12개월 [2][10] 31일[4][10]
 *      메모리 활용방법 vs 전체 기수정렬
 *      단순 big-O 표기
 */
//int find(int i)
//{ printf("found! %d\n",i); return i;}
int min_year(int year,int *arr)
{
    realloc(arr, sizeof(int));
    printf("realloc on %d",year);
    return year;
}
int max_year(int year,int *arr,int size)
{
    if (NULL == (arr = realloc(arr,sizeof(int))))
    {}
    arr[size]=1;
}

void date_sort(object obj[],unsigned int count)
{
    unsigned int Yearmin = ~(0x00), Yearmax = 0;
    int *year_arguments = (int *)calloc(0,sizeof(int));
    for (int i = 0; i < count; ++i)
    {
        int num = (int)obj[i].date/10000;

        if(Yearmin > num)
            Yearmin = min_year(num,year_arguments);
        else if (Yearmax < num)
            Yearmax = num;
//        else
    }
//    int *dates =(int *)malloc(sizeof(int)*(Yearmax-Yearmin));
    printf("Year min : %d\nYear max : %d\n Years[%d]\n",Yearmin,Yearmax,(Yearmax-Yearmin+1));
    free(year_arguments);
}

#endif //ALGORITHM_TEAM_6_DATE_SORT_H
