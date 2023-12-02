//
// Created by Jeon Hyeonbae on 2023/11/22.
#ifndef ALGORITHM_TEAM_6_DATE_SORT_H
#define ALGORITHM_TEAM_6_DATE_SORT_H

#include "sort.h"
#include <stdio.h>

//
// 연도 갯수 반환
// obj      :   읽을 오브젝트 파일
// count    :   오브젝트 파일 갯수
// size     :   return 배열 갯수
// Yearmin  :   연도 최소정보 저장
int getYearMin_Max(object *obj,uint count,int *Yearmin)
{
    int min = INT32_MAX, max = 0;
    int years;

    int i;
    for(i = 0; i < count; ++i)
    {
        int num = (int)obj[i].date/10000;

        if(min > num)
            min = num;

        else if (max < num)
            max = num;
    }
    *Yearmin = min;
    years = max-min+1; // 배열 사이즈

//    if((years = (int *) calloc((*size),sizeof(int))) == NULL)
//    {fprintf(stderr,"연도 데이터 정렬 중 메모리 할당 오류"); exit(1);}

//    for (i = 0; i < count; ++i)
//    {
//        int num = (int)obj[i].date/10000;
//        years[num-min] += 1;
//    }
    return years;
}

void sort_MonthDay(object obj[],uint count)
{
    int data_num;
    int date_value;

    int month,day_10,day_1; // 날짜정보들

    int i;
    for (i = 0; i < count; ++i)
    {
        data_num = (int)obj[i].data_num;
        date_value = (int)obj[i].date%10000;
        month = date_value / 100;
        day_10 = ( date_value / 10 ) % 10;
        day_1 = ( date_value % 10 );

//        printf("[%d]date value = %d월 %d%d일 \n",data_num+1,month,day_10,day_1);
    }
}

void sorting_radix(sorting_criterion criterion,object obj[], int count)
{
    if (criterion == y)
    {
        int year_min;
        object result[count];
        int i,j;
        int years = getYearMin_Max(obj,count,&year_min);

        // 필요한 배열 필요한 갯수만큼 할당.
        element *I_Resit = malloc(sizeof(element)*years);

        for (i = 0; i < years; ++i)
            I_Resit[i].pointer = 0;

        for (i = 0; i < count; ++i)
        {
            int index = (int) ((obj[i].date / 10000) - year_min) ;
            I_Resit[index].data[I_Resit[index].pointer] = (int) obj[i].data_num;
            I_Resit[index].pointer++;
        }

        int count = 0;
        for( i = 0; i < years; i ++)
            for (j = 0; j < I_Resit[i].pointer; ++j)
            {
                result[count] = obj[I_Resit[i].data[j]];
                count++;
//                printf("obj%u{%d / %d / %d / %s }\n",result[j].data_num+1,result[j].date,result[j].Ideparture,result[j].Iarrival,result[j].info);
//                printf("Result[%d] is %d | count %d\n",year_min+i,I_Resit[i].data[j]+1,count);
            }

        memcpy(obj,result, sizeof(result));
        for (i = 0; i < count; i++)
            printf("Year -> obj%u{%d / %d / %d / %s }\n",obj[j].data_num+1,obj[j].date,obj[j].Ideparture,obj[j].Iarrival,obj[j].info);

        free(I_Resit);
    }
}
// 예상 호출 구조
// _main(args) -> date_sort(obj,cnt) -> sorting_radix()
void date_sort(object obj[],int count)
{
    sorting_radix(y,obj,count);
    //TODO: sort sequence
    //       MARK:: 일수 -> 월수 -> 년 (기수형태 형식으로 하되, 년도는 경우의 수가 많지 않다는 점을 고려하여 기수정렬과 유사하나 변형한 형태로 사용.)
    //          FIXED:: L 년도는 위의 함수로 해결-!
//    sort_MonthDay(obj, count);
}
#endif //ALGORITHM_TEAM_6_DATE_SORT_H