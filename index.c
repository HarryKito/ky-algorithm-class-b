/*
 * 2023/11/15 ikw.university Algorithm
 * 택배 리스트 정리
 * 접수일자, 출발지, 도착지, 택배현황 4가지항목을 기반하여 택배현황을 정렬 및 조회.
 * TODO: 임무
 *  오늘 택배 가야할 곳들을 각 목적지별 정리
 */
#include "includes.h"

#define MAXCHAR 50

int main(int argc,char** argv)
{
    FILE *fp;			//파일 객체를 담을 변수
    char row[MAXCHAR];	//열 데이터
    char *cell;		    //하나의 데이터 정보(하나의 셀)

    //파일 읽기, 만약 파일을 읽을 수 없다면 종료.
    if(!(fp = fopen("./data/del.csv","r")))
    {fputs("데이터셋을 읽을 수 없음.",stderr);    exit(1);}
    //파일이 잘 읽어진다면 다음으로 수행

    int i = 0;              // 다음의 반복문에 데이터 넘버링으로 사용될 변수
    struct tm time;         // 시간변수

    while (feof(fp) == 0)   // 파일에서 정보수집 시작 <<반복문>>
    {
        fgets(row, MAXCHAR, fp);
        cell = strtok(row, "\n");
        printf("%d번 데이터 : %s\n",++i, cell);
        //날짜정보
		time = get_date(cell,i); //데이터로부터 날짜정보 얻어오기
		printf("\t%d년%d월%d일 데이터\n",time.tm_year+1900,time.tm_mon+1,time.tm_mday);
        //도착지정보
        // TODO: 일단은 도착지 정보 파싱까지만 구현하고서 어떻게 자료를 구현할지 생각해보자!

        //배송현황
        // TODO: 일단 배송현황 정보 파싱까지만!

    }
    puts("데이터셋 읽기 종료");

    return 0;
}

