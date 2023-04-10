//
//  test.c
//  230406 exam Euclid
//
//  Created by 한설 on 2023/04/06.
//

#include "euclid.h"

#define MAX 1000

int (*fpl)(int, int);

fpl = euclidloop;


void checktime(int (*func)(int*, int*), int *a, int *b, int *res)   //인자로 받은 함수가 실행되는 시간을 출력해주는 함수
{
    clock_t start, finish; //clock_t : clock t의 자료를 담고 있는 자료형. clock()의 반환(return)형
    double duration;
    start = clock(); //clock() : 프로그램에 의해 프로세서가 소비된 시간 반환
    for(int i = 0; i < 1000; i++) {
        res[i] = (*func)(a + i, b + i);   //외부에서 받은 함수 실행
    }
    finish = clock();
    //시작시간과 끝시간을 clock()을 통해 도출하고, 차를 계산해 걸린 시간을 계산
    duration = (double)(finish - start) / CLOCKS_PER_SEC;   //CLOCKS_PER_SEC : 초당 clock ticks의 수를 나타내는 매크로. 이걸로 나눠줘야 초단위로 나옴.
    printf("%.1f 초입니다. \n", duration);
}

void TC_euclid(void)
{
    int a[MAX], b[MAX], arrayl[MAX], arrayj[MAX], i;
    srand((unsigned int)time(NULL));
    for(i = 0; i < MAX; i++) { //변수 초기화
        a[i] = rand() % 20;    //a에 1000보다 작은 수 대입
        b[i] = rand() % 20;   //b에 1000보다 작은 수 대입
        arrayl[i] = 0;  //결과저장소 초기화
        arrayj[i] = 0;  //결과저장소 초기화
    }
    checktime(euclidloop(a, b), a, b, arrayl);
    printf("%d %d %d", a[20], b[20], arrayl[20]);
    
}



