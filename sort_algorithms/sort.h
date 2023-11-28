//
// Created by Jeon Hyeonbae on 2023/11/16.
//

#ifndef ALGORITHM_TEAM_6_SORT_H
#define ALGORITHM_TEAM_6_SORT_H

#define MAXCHAR 40
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

typedef struct object{
    unsigned int data_num;
    unsigned int date;
    uint16_t Ideparture;
    uint16_t Iarrival;
    char info[3];
}object;

#endif //ALGORITHM_TEAM_6_SORT_H
