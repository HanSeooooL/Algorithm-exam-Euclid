//
//  euclid.c
//  230406 exam Euclid
//
//  Created by 한설 on 2023/04/06.
//

#include "euclid.h"

//재귀함수를 이용한 최대공약수
int euclidjaegui(int a, int b)
{
    int sav;
    if (b > a)  //1. b가 a보다 작을 경우 자리변환
    {
        sav = b;
        b = a;
        a = sav;
    }
    //2. b(작은 수)가 0일 경우 a(0이 아닌 다른 수) 반환
    if (b == 0) return a;
    //3. 큰 수의 자리에 b를 기입하고 작은 수 자리에 a에 b를 나눈 후에 나머지 값을 기입
    return euclidjaegui(b, a % b);
    //4. 3의 과정을 반복하고, 2의 조건이 맞았을 때 큰 수를 반환한다.
}

//반복문을 이용한 최대공약수
int euclidloop(int a, int b)
{
    int sav;
    if (b > a)  //b가 a보다 클 경우 a와 b 자리변환
    {
        sav = b;
        b = a;
        a = sav;
    }
    
    while (b != 0) //2. b(작은 수)가 0일 경우 a(0이 아닌 다른 수) 반환
    { //3. 큰 수의 자리에 b를 기입하고 작은 수 자리에 a에 b를 나눈 후에 나머지 값을 기입
        sav = b;
        b = a % b;
        a = sav;
      //4. 3의 과정을 반복하고, 2의 조건이 맞았을 때 큰 수를 반환한다.
    }
    return a;
}
