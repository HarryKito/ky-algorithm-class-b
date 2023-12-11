#ifndef CLASS_B
#define CLASS_B

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
//#include "timer/timer.h"
#include <unistd.h>

#include "sort_algorithms/delivery_info_sort.h"
#include "sort_algorithms/departure_sort.h"
#include "sort_algorithms/arrival_sort.h"
#include "sort_algorithms/date_sort.h"
#include "sort_algorithms/delivery_info_sort.h"
#include "csvReader.h"

//          0 : data/del.csv 파일
//  file name : 데이터 파일 지정 (필요시)
FILE *openFile(char* file);

// 오브젝트 파일 CSV 파일로 저장
// file 경로를 지정하여 저장 가능
// file 파라미터 값 0 일 경우 data/result로 저장
void saveCSV(object obj[], char *file);

// 정렬방식 지정 명령
// 사용자 입력 파라미터로 지정
void sortCommand(int argc,char** argv,object obj[]);

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

/* 프로그램 실행 시 입력된 인자, 분류형식에 따라 분류하는 부가적 부분 */
void sortCommand(int argc,char** argv,object obj[])
{
    int i;
    char result_file[35];

    // 今日 information
    time_t curr_time = time(NULL);
    struct tm *curr = localtime(&curr_time);
    strftime(result_file, sizeof(result_file)-1, "%Y-%m-%d-%H_%M_sort_result.csv", curr);

    if (argc >= 2)
    {
        if(strcmp(argv[1],"date") == 0) //  date 정렬
        {
            puts("date sort execute");
//            timer();
            date_sort(obj, ROWS);
//            printf("done in %lu clk\n",timer());
            saveCSV(obj,"./data/date_info.csv");
        }

        else if(strcmp(argv[1],"departure") == 0) //  departure 정렬
        {
            puts("departure sort execute");
//            timer();
            departure_sort(obj, ROWS);
//            printf("done in %lu clk\n",timer());
            saveCSV(obj,"./data/departure_info.csv");
        }

        else if(strcmp(argv[1],"arrival") == 0) //  arrival 정렬
        {
            puts("arrival sort execute");
//            timer();
            arrival_sort(obj, ROWS);
//            printf("done in %lu clk\n",timer());
            saveCSV(obj,"./data/arrival_info.csv");
        }

        else if(strcmp(argv[1],"information") == 0) //  delivery information 정렬
        {
            puts("information sort execute");
//            timer();
            delivery_info(obj,0, ROWS - 1);
//            printf("done in %lu clk\n",timer());
            saveCSV(obj,"./data/delivery_info.csv");
        }
        else
        {
            fprintf(stderr," 잘못된 인자 값\n");
            for (int i = 0; i < argc; ++i)
            { fprintf(stderr,"argv%d : {%s}\n", i, argv[i]); }
            exit(1);
        }
        saveCSV(obj,result_file);
        puts("\t date \t| departure | arrival | info ");
        for(i=0;i<10;i++)
            printf("Result { %d \t|%d \t|%d \t|%s}\n"
                   ,obj[i].date
                   ,obj[i].Ideparture
                   ,obj[i].Iarrival
                   ,obj[i].info
                   );
    }
    else
    { fprintf(stderr, "Arguments not detected.\n Usage : %s\t[sort target]\n\t\t\t\t  date\n\t\t\t\t  departure\n\t\t\t\t  arrival\n\t\t\t\t  information\n\n  for example >> %s date\n", argv[0],argv[0]); }
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
        for (i = 0; i < ROWS; ++i)  // object to csv
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
