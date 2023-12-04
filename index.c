/*
 * 2023/11/15 ikw.univ Algorithm
 * 택배 리스트 정리
 * 접수일자, 출발지, 도착지, 택배현황 4가지항목을 기반하여 택배현황을 정렬 및 조회.
 * TODO: 임무
 *  오늘 택배 가야할 곳들을 각 목적지별 정리
 */
#include "includes.h"

int main(int argc,char** argv)
{
    object obj[ROWS];

    FILE *fp = openFile(0); //파일 객체를 담을 변수
    char *cell;		            //전체 데이터 정보
    char row[MAXCHAR];          //열 데이터

    // 파일에서 정보수집
    int i;
    for(i = 0; feof(fp) == 0; i++)
    {
        fgets(row, MAXCHAR, fp);
        cell = strtok(row, "\n");
        obj[i] = reset_data(cell,strlen(cell),i);
    }
    // 프로그램 입력에 따른 정렬 기준 선택
    sortCommand(argc,argv);

    // 날짜정렬
//    date_sort(obj,ROWS);
    //출착지 정렬    //도착지 정렬
//    departure_sort(obj,ROWS);

    arrival_sort(obj,ROWS);
     // 퀵 정렬 수행 (info 기준으로)
//    quickSort(obj, 0, ROWS - 1);
//    puts("인포메이션 끝");
    for (int j = 0; j < ROWS; ++j)
        printf("obj%u{%d / %d / %d / %s }\n",obj[j].data_num+1,obj[j].date,obj[j].Ideparture,obj[j].Iarrival,obj[j].info);

    return 0;
}

