/*
 * 2023/11/15 ikw.university Algorithm
 * 택배 리스트 정리
 * 접수일자, 출발지, 도착지, 택배현황 4가지항목을 기반하여 택배현황을 정렬 및 조회.
 * TODO: 임무
 *  오늘 택배 가야할 곳들을 각 목적지별 정리
 */
#include "includes.h"

int main(int argc,char** argv)
{
    FILE *fp = openFile(0); //파일 객체를 담을 변수
    char *cell;		            //전체 데이터 정보
    char row[MAXCHAR];          //열 데이터
    object obj[30000];

    // 파일에서 정보수집
    for(int i = 0; feof(fp) == 0; i++)
    {
        fgets(row, MAXCHAR, fp);
        cell = strtok(row, "\n");
        obj[i] = reset_data(cell,i);
    }
    // 날짜정렬
    object *object_date = date_sort(obj,ROWS);
  
     // 퀵 정렬 수행 (info 기준으로)
    quickSort(obj, 0, ROWS - 1);

    for (int j = 0; j < ROWS; ++j)
        printf("obj%ld{%d / %s / %s / %s }\n",obj[j].data_num+1,obj[j].date,obj[j].departure,obj[j].arrival,obj[j].info);
    puts("데이터셋 읽기 종료");

    return 0;
}

