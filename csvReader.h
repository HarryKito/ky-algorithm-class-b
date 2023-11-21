#ifndef READER_CSV
#define READER_CSV

//  csvReader.h
//  get_date(string, int)
//
//  Created by JeonHyeonBae on 2023/11/15.
//
#include "sort.h"

struct tm get_date(char* data,int i)
{
    struct tm time;
    char str[9];
    int s;

    for(s = 0;s<8;s++)
        str[s] = data[s];

    if(strftime(str,sizeof(str),"%Y%m%d",&time) == NULL)
    {
        fprintf(stderr,"%d번째, 날짜 데이터 오류\n",i);
        exit(2);
    }
    return time;
}

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
    obj.departure[0] = data[8];
    obj.departure[1] = data[9];
    obj.departure[2] = data[10];
    obj.departure[3] = '\0'; // escape 문자 문제해결

    //도착지 파싱
    obj.arrival[0] = data[11];
    obj.arrival[1] = data[12];
    obj.arrival[2] = data[13];
    obj.arrival[3] = '\0'; // escape 문자 문제해결

    //현재 택배 정보 파싱
    obj.info[0] = data[14];
    obj.info[1] = data[15];
    obj.info[2] = '\0'; // escape 문자 문제해결

    return obj;
}
#endif
