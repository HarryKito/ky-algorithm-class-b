#ifndef CLASS_B
#define CLASS_B

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#include "sort_algorithms/delivery_info_sort.h"
#include "sort_algorithms/departure_sort.h"
#include "sort_algorithms/arrival_sort.h"
#include "sort_algorithms/date_sort.h"
#include "sort_algorithms/delivery_info_sort.h"
#include "csvReader.h"

//          0 : data/del.csv 파일
//  file name : 데이터 파일 지정 (필요시)
FILE *openFile(char* file)
{
    FILE *fp;			    //파일 객체를 담을 변수
    file = !file ? "./data/del.csv" : file;

    //파일 읽기, 만약 파일을 읽을 수 없다면 종료.
    if(!(fp = fopen(file,"r")))
    {
        fputs("데이터셋 파일을 읽을 수 없음.",stderr);
        exit(1);
    }
    else
        return fp;
}

/*
 * TODO: 목표
 *  program {분류형식}에 따라서 나열.
 */

/* 프로그램 실행 시 입력된 인자, 분류형식에 따라 분류하는 부가적 부분 */
void sortCommand(int argc,char** argv,object obj[])
{
    char get;
    if (argc >= 2)
    {
        for (int i = 0; i < argc; ++i)
        {
            printf("argv%d : {%s}\n", i, argv[i]);
        }
        if(argv[1] == "date") //  날짜정렬
        {
            date_sort(obj, ROWS);
        }
        if(argv[1] == "departure") //  출착지 정렬
        {
            departure_sort(obj, ROWS);
        }
        if(argv[1] == "arrival") //  도착지 정렬
        {
            arrival_sort(obj, ROWS);
        }
        if(argv[1] == "information") //  배송정보 정렬
        {
//            delivery_info(obj, ROWS);
        }
    }
    else
    {
        fprintf(stderr, "Arguments not detected.\n Usage : %s [-]\n", argv[0]);
    }
}

void saveCSV(object obj[], char *file)
{
    FILE *fp;
    file = !file ? "./data/output.csv" : file;
    if(!(fp = fopen(file,"w")))
    {
        fputs("Cannot write file.",stderr);
        exit(1);
    }
    else
    {
        int i;
        for (i = 0; i < ROWS; ++i)
        {
            fprintf(fp, "%04d-%02d-%02d,%d,%d,%s\n",
                    ((int)(obj[i].date/10000)),
                    ((int)(obj[i].date %10000) / 100),
                    ((int)(obj[i].date % 100)),
                    obj[i].Iarrival,
                    obj[i].Ideparture,
                    obj[i].info
                    );
        }
    }
    fclose(fp);
}
#endif
