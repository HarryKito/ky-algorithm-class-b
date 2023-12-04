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

    return years;
}

void sorting_radix(sorting_criterion criterion,object obj[], int count)
{
    // 최종 결과값 담을 것.
    object result[count];

    switch (criterion)
    {
        // day 일의자리
        case d1:
        {
            element I_Result[10];
            int day_1;
            int i,j,cnt = 0;

            for (i = 0; i < 10; ++i)    I_Result[i].pointer = 0;

            for (i = 0; i < count; ++i)
            {
                day_1 = ( ( (int) obj[i].date%10000 ) % 10 );
                I_Result[day_1].data[I_Result[day_1].pointer] = (int) obj[i].data_num;
                I_Result[day_1].pointer++;
            }

            for( i = 0; i < 10; i ++)
                for (j = 0; j < I_Result[i].pointer; ++j)
                {
                    result[cnt] = copy(obj[I_Result[i].data[j]],cnt);
                    cnt++;
                }
            break;
        }

        // day 십의자리
        case d10:
        {
            element I_Result[4];
            int day_10;
            int i,j,cnt = 0;

            for (i = 0; i < 4; ++i)    I_Result[i].pointer = 0;

            for (i = 0; i < count; ++i)
            {
                day_10 = ( (int) (obj[i].date%10000) / 10 ) % 10;
                I_Result[day_10].data[I_Result[day_10].pointer] = (int) obj[i].data_num;
                I_Result[day_10].pointer++;
            }

            for( i = 0; i < 4; i ++)
                for (j = 0; j < I_Result[i].pointer; ++j)
                {
                    result[cnt] = copy(obj[I_Result[i].data[j]],cnt);
                    cnt++;
                }
            break;
        }

        // Month
        case m:
        {
            element I_Result[12];
            int month;
            int i,j,cnt = 0;
            for (i = 0; i < 12; ++i)    I_Result[i].pointer = 0;

            for (i = 0; i < count; ++i)
            {
                month = ( (int) (obj[i].date%10000) / 100 );
                I_Result[month-1].data[I_Result[month-1].pointer] = (int) obj[i].data_num;
                I_Result[month-1].pointer++;
            }

            for( i = 0; i < 12; i ++)
                for (j = 0; j < I_Result[i].pointer; j++)
                {
                    result[cnt] = copy(obj[I_Result[i].data[j]],cnt);
                    cnt++;
                }
            break;
        }
        // Year
        case y:
        {
            int year_min;   // Minimum value according to years
            int i,j,cnt = 0;// 반복문에서 사용.. USE AFTER INIT!!
            int index;      // Year Index [현재 연도 - 최소 연도 = 0 ~ n 번 ]
            int years = getYearMin_Max(obj,count,&year_min);

            // Allocate for Indexing by years
            element *I_Result = malloc(sizeof(element)*years);

            for (i = 0; i < years; ++i)
                I_Result[i].pointer = 0;

            for (i = 0; i < count; ++i)
            {
                index = (int) ((obj[i].date / 10000) - year_min) ;
                I_Result[index].data[I_Result[index].pointer] = (int) obj[i].data_num;
                I_Result[index].pointer++;
            }

            for( i = 0; i < years; i ++)
                for (j = 0; j < I_Result[i].pointer; ++j)
                {
                    result[cnt] = copy(obj[I_Result[i].data[j]],cnt);
                    cnt++;
                }
            free(I_Result);
            break;
        }
        default: { fprintf(stderr,"sorting_criterion selection ERROR\n"); exit(2); }
    }
    int i;
    for (i = 0; i < count; i++)
        obj[i] = copy(result[i],i);
    printf("sorted:%d\n",criterion);
}
// 예상 호출 구조
// _main(args) -> date_sort(obj,cnt) -> sorting_radix()
void date_sort(object obj[],int count)
{
    int i;
    sorting_radix(d1,obj,count);
    sorting_radix(d10,obj,count);
    sorting_radix(m,obj,count);
    sorting_radix(y,obj,count);
//    for (i = 0; i < count; i++)
//        printf("year_sorted%u{%d / %d / %d / %s }\n",obj[i].data_num+1,obj[i].date,obj[i].Ideparture,obj[i].Iarrival,obj[i].info);
}
#endif //ALGORITHM_TEAM_6_DATE_SORT_H