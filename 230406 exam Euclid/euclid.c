//
//  euclid.c
//  230406 exam Euclid
//
//  Created by 한설 on 2023/04/06.
//

#include "euclid.h"

int euclidjaegui(int a, int b)  //재귀함수를 이용한 최대공약수
{
    int sav;
    if (b > a)
    {
        sav = b;
        b = a;
        a = sav;
    }
    if (b == 0) return a;
    return euclidjaegui(b, a % b);
}

int euclidloop(int a, int b)    //loop를 이용한 최대공약수
{
    int sav;
    if (b > a)  //b가 a보다 클 경우 a와 b 자리변환
    {
        sav = b;
        b = a;
        a = sav;
    }
    
    while (b != 0)
    {
        sav = b;
        b = a % b;
        a = sav;
    }
    return a;
}
