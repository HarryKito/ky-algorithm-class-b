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
 */
//int find(int i)
//{ printf("found! %d\n",i); return i;}

object* date_sort(object obj[],unsigned int count)
{
    object result[count];
    int Yearmin = (int)obj->date/10000, Yearmax = 0;
    int Year_size = 0;
    for (int i = 0; i < count; ++i)
    {
        int num = (int)obj[i].date/10000;

        if(Yearmin > num)
            Yearmin = num;
        else if (Yearmax < num)
            Yearmax = num;
    }
    int *dates =(int *)malloc(sizeof(int)*(Yearmax-Yearmin));
    printf("Year min : %d\nYear max : %d\n Years[%d]\n",Yearmin,Yearmax,Yearmax-Yearmin);
    return result;
}

#endif //ALGORITHM_TEAM_6_DATE_SORT_H
