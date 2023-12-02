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
#define uint unsigned int

void SortData(object obj)
{
    int sorts[10][ROWS];

}

void getYearMin_Max(object *obj,uint count,uint *min,uint *max)
{
    for (int i = 0; i < count; ++i)
    {
        int num = (int)obj[i].date/10000;

        if(*min > num)
            *min = num;
        else if (*max < num)
            *max = num;
    }
}

void date_sort(object obj[],uint count)
{
    unsigned int Yearmin = ~(0x00), Yearmax = 0;

    object *result;
    getYearMin_Max(obj,count,&Yearmin,&Yearmax);

    //TODO: sort sequence
    //       MARK:: 일수 -> 월수 -> 년(이건 굳이 기수정렬을 써야할까? 다른 형태로 가능할거같음.)
    //          FIXED:: L 년도는 위의 함수로 해결-!
    //
    for(int i = 0; i < count; ++i)
    {
        SortData(obj[i]);
    }
    printf("Year min : %d\nYear max : %d\n Years[%d]\n",Yearmin,Yearmax,(Yearmax-Yearmin+1));
}
#endif //ALGORITHM_TEAM_6_DATE_SORT_H
