//
//  test.c
//  230406 exam Euclid
//
//  Created by 한설 on 2023/04/06.
//

#include "euclid.h"

#define MAX 1000

// TC_Euclid
// 임의의 술단지의 수를 함수로 보내 최소 필요한 사람의 수를 반환받아 출력한다.
void TC_euclid(void)
{
    int a[MAX], b[MAX], arrayl[MAX], arrayj[MAX], i;
    int n = 0;
    srand((unsigned int)time(NULL));
    for(i = 0; i < MAX; i++) { //변수 초기화
        a[i] = rand() % 1000;    //a에 1000보다 작은 수 대입
        b[i] = rand() % 1000;   //b에 1000보다 작은 수 대입
        arrayl[i] = 0;  //결과저장소 초기화
        arrayj[i] = 0;  //결과저장소 초기화
    }
    printf("반복을 이용한 최대공약수 계산에 걸리는 시간은 ");
    checktime(euclidloop, a, b, arrayl);
    printf("재귀를 이용한 최대공약수 계산에 걸리는 시간은 ");
    checktime(euclidjaegui, a, b, arrayj);
    printf("계산 결과를 서로 비교했을 때 틀린 횟수는 ");
    for(i = 0; i < MAX; i++) {  //각각의 배열에 결과값이 저장되어 있으므로
        if(arrayl[i] != arrayj[i])  //서로 다르면
            n += 1; //다른 횟수 추가
    }
    printf("%d회입니다.\n", n);
}

//시간 체크 함수
void checktime(int (*func)(int, int), int *a, int *b, int *res)   //인자로 받은 함수가 실행되는 시간을 출력해주는 함수
{
    clock_t start, finish; //clock_t : clock t의 자료를 담고 있는 자료형. clock()의 반환(return)형
    double duration;
    start = clock(); //clock() : 프로그램에 의해 프로세서가 소비된 시간 반환
    for(int i = 0; i < MAX; i++) {
        *(res + i) = (*func)(*(a + i), *(b + i));   //외부에서 받은 함수 실행
    }
    finish = clock();
    //시작시간과 끝시간을 clock()을 통해 도출하고, 차를 계산해 걸린 시간을 계산
    duration = (double)(finish - start) / CLOCKS_PER_SEC;   //CLOCKS_PER_SEC : 초당 clock ticks의 수를 나타내는 매크로. 이걸로 나눠줘야 초단위로 나옴.
    printf("%lf 초입니다. \n", duration);
}

