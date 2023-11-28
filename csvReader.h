#ifndef READER_CSV
#define READER_CSV

//  csvReader.h
//  get_date(string, int)
//
//  Created by JeonHyeonBae on 2023/11/15.
//  CSV 앍고 데이터 리셋
#include "sort_algorithms/sort.h"

object reset_data(char *data,int data_num)
{
    object obj;
    char str[8];

    //csv기준 데이터 넘버
    obj.data_num = data_num;

    //날짜 파싱
    int i = 0;
    for (; i < 8; i++)
        str[i] = data[i];

    obj.date = atoi(str);

    //출발지 파싱
    char loc[4];
    loc[0] = data[8];
    loc[1] = data[9];
    loc[2] = data[10];
    loc[3] = '\0'; // escape 문자 문제해결
    obj.Ideparture = atoi(loc);

    //도착지 파싱
    loc[0] = data[11];
    loc[1] = data[12];
    loc[2] = data[13];
    loc[3] = '\0'; // escape 문자 문제해결
    obj.Iarrival = atoi(loc);

    //현재 택배 정보 파싱
    obj.info[0] = data[14];
    obj.info[1] = data[15];
    obj.info[2] = '\0'; // escape 문자 문제해결

    return obj;
}
#endif
