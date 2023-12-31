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

// element 자료구조
// 데이터 값
// 데이터를 가리키는 포인터
typedef struct {
    int data[ROWS];
    int pointer;
}element;

object copy(object in,int number)
{
    object obj;
    obj.data_num = number;
    obj.date = in.date;
    obj.Ideparture = in.Ideparture;
    obj.Iarrival = in.Iarrival;
    obj.info[0] = in.info[0];
    obj.info[1] = in.info[1];
    obj.info[2] = in.info[2];
    return obj;
}

void swap(object *to,object *from)
{
    to->data_num = from->data_num;
    to->date = from->date;
    to->Ideparture = from->Ideparture;
    to->Iarrival = from->Iarrival;
    to->info[0] = from->info[0];
    to->info[1] = from->info[1];
    to->info[2] = from->info[2];
}

#define SWAP(x,y,t) (swap(t,x),swap(x,y),swap(y,t))

#endif //ALGORITHM_TEAM_6_SORT_H
