//
// Created by Jeon Hyeonbae on 2023/12/09.
//

#include "timer.h"

inline clock_t timer()
{
    static clock_t start = 0;

    if(!start)
        start = clock();

    else if(start)
        return clock() - start;

    return 0;
}