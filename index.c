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
    object obj[ROWS]; // 오브젝트 각종 CSV 정보 객체

    FILE *fp = openFile(0); //파일 객체를 담을 변수
    char *cell;		            //전체 데이터 정보
    char row[MAXCHAR];          //열 데이터
    int i;

    // 파일 정보수집
    while (fgets(row, MAXCHAR, fp) != NULL && i < ROWS)
    {
        cell = strtok(row, "\n");
        if(cell != NULL)
        {
            obj[i] = reset_data(cell,strlen(cell),i);
            i++;
        }
    }

    sortCommand(argc,argv,obj);

//    for(i = 0; i < ROWS; i++)
//        printf("%d obj {%u / %d / %d / %d / %s}\n",
//               i+1
//               ,obj[i].data_num
//               ,obj[i].date
//               ,obj[i].Ideparture
//               ,obj[i].Iarrival
//               ,obj[i].info
//               );

    fclose(fp);
    return EXIT_SUCCESS;
}