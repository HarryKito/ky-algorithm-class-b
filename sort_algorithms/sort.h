//
// Created by Jeon Hyeonbae on 2023/11/16.
//

#ifndef ALGORITHM_TEAM_6_SORT_H
#define ALGORITHM_TEAM_6_SORT_H

#define MAXCHAR 20
#define ROWS 30000

#include <stdlib.h>
//  sort.h
//  sort_date()
//  TODO: 기수정렬 사용예정
//  Created by JeonHyeonBae on 2023/11/15.
//  날짜 분류함수

// 64bit기준 2word

#ifndef uint16_t
typedef unsigned short uint16_t;
#endif

#ifndef INT32_MAX
#define INT32_MAX 2147483647
#endif

#define uint unsigned int

typedef enum {
    d1 = 0,
    d10,
    m,
    y
}sorting_criterion;

typedef struct object{
    unsigned int    data_num;   // 데이터 인덱스 넘버
    unsigned int    date;       // 데이터 날짜 정보
    uint16_t        Ideparture; // 도착지 정보
    uint16_t        Iarrival;   // 출발지 정보
    char            info[3];    // 택배 배송 정보
}object;

typedef struct {
    int data[ROWS];
    int pointer;
}element;

object copy(object in)
{
    object obj;
    obj.data_num = in.data_num;
    obj.date = in.date;
    obj.Ideparture = in.Ideparture;
    obj.Iarrival = in.Iarrival;
    obj.info[0] = in.info[0];
    obj.info[1] = in.info[1];
    obj.info[2] = in.info[2];
    return obj;
}

#endif //ALGORITHM_TEAM_6_SORT_H
