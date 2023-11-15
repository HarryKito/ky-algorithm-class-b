#ifndef READER_CSV
#define READER_CSV

//  csvReader.h
//  get_date(string, int)
//
//  Created by JeonHyeonBae on 2023/11/15.
//
struct tm get_date(char* data,int i)
{
    struct tm time;
    char str[9];
    int s;

    for(s = 0;s<8;s++)
        str[s] = data[s];

    if(strptime(str,"%Y%m%d",&time) == NULL)
    {
        fprintf(stderr,"%d번째, 날짜 데이터 오류\n",i);
        exit(2);
    }

    return time;
}

#endif
