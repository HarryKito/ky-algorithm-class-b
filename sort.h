//
// Created by Jeon Hyeonbae on 2023/11/16.
//

#ifndef ALGORITHM_TEAM_6_SORT_H
#define ALGORITHM_TEAM_6_SORT_H

#include <stdlib.h>
//  sort.h
//  sort_date()
//  TODO: 기수정렬 사용예정
//  Created by JeonHyeonBae on 2023/11/15.
//  날짜 분류함수
void* sort_date(char* date)
{
    static int max_year = 0;
    int _year = atoi(date);

    if(_year > max_year)
        max_year = _year; //최대연도 구하기
}

// 64bit기준 2word
typedef struct object{
    unsigned int data_num;
    unsigned int date;
    char departure[4];
    char arrival[4];
    char info[3];
}object;

#endif //ALGORITHM_TEAM_6_SORT_H
