#ifndef READER_CSV
#define READER_CSV

#include "sort_algorithms/sort.h"
enum location {
    SEOUL = 2,
    GUEONGGI = 31,
    INCHEON = 32,
    GANGWON = 33,
    CHUNGNAM = 41,
    DAEJEON = 42,
    CHUNGBUK = 43,
    SAEJONG = 44,
    BUSAN = 51,
    ULSAN = 52,
    DAEGU = 53,
    GYUNGBOOK = 54,
    GYUNGNAM = 55,
    JEONNAM = 61,
    GWANGJU = 62,
    JEONBUK = 63,
    JEJU = 64
};

//  csvReader.h
//  reset_data(char* ,unsigned long ,int) --> object
//  CSV 앍고 데이터 리셋 (오브젝트로)
object reset_data(char *data,unsigned long len_data,int data_num)
{
    object obj;
    char str[8]; // 날짜정보
    char loc[4]; // 지역정보

    //csv기준 데이터 넘버
    obj.data_num = data_num;

    //날짜 파싱
    int i = 0;
    for (; i < 8; i++)
        str[i] = data[i];

    obj.date = (int)strtol(str, (char **)NULL, 10);

//출발지 파싱
    if (len_data == 16)
    { obj.Ideparture = 2; }

    else
    {
        loc[0] = data[8];
        loc[1] = data[9];
        loc[2] = data[10];
        loc[3] = '\0'; // escape 문자 문제해결

        obj.Ideparture = atoi(loc) == 20 ? 2 : atoi(loc);
    }

//도착지 파싱
    if(len_data == 16)
    { obj.Iarrival = 2; }
    else
    {
        loc[0] = data[11];
        loc[1] = data[12];
        loc[2] = data[13];
        loc[3] = '\0'; // escape 문자 문제해결

        obj.Iarrival = atoi(loc);
    }

    //현재 택배 정보 파싱
    obj.info[0] = data[len_data - 4];
    obj.info[1] = data[len_data - 3];
    obj.info[2] = '\0'; // escape 문자 문제해결

    return obj;
}
#endif