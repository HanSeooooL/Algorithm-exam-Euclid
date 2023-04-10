# Algorithm-exam-Euclid

알고리즘 설계 구현 결과 : <유클리드함수>
 
<문제 정의>
문제이름: 2개의 수에서의 최대공약수
문제설명: 숫자 2개가 주어졌을 때에 최대공약수를 찾는다.
문제예시: 12와 16의 최대공약수는 4이다.
 
<해결 아이디어>
(해결아이디어 1) 한설 : 2개의 수에서 (큰수 - 작은수)를 반복하여 작은 수가 0이 될때까지 반복했을때, 남아있는 0이 아닌 다른 수가 최대공약수이다.
 
아이디어 채택: 아이디어 1을 채택
 
<알고리즘>
명칭: 재귀호출을 이용한 유클리드함수(euclidjaegui)
입력: 임의의 숫자 2개
출력: 숫자 2개에 대한 최대공약수
처리순서:
재귀
1. 큰수와 작은 수의 위치에 맞게 각 수를 배치한다.
2. 작은 수가 0일 경우 큰 수를 반환한다.
3. 큰 수 자리에 변수 중 작은 수를 기입하고, 작은 수 자리에 변수 중 큰 수에 작은 수를 나눈 후의 나머지값을 기입한다.
4. 3의 과정을 반복하고, 2의 조건이 맞았을 때 큰 수를 반환한다.
반복
1. 큰수와 작은 수의 위치에 맞게 각 수를 배치한다.
2. 작은 수가 0일 경우 큰 수를 반환한다.
3. 큰 수에 작은 수를 나눈 후의 나머지 값과 작은 수를 기억한다.
4. 3의 과정을 반복하고, 2의 조건이 맞았을 때 큰 수를 반환한다.
 
<코드 설계1>
1. 자료 구조 정의
- 큰 수 : a
- 작은 수 : b
- 임시저장 : sav
-
2. 함수 정의
- 기능 : 2개의 숫자를 받아 2개의 수에서의 최대공약수를 구한다.
- 프로토타입: int euclidjaegui(int a, int b), int euclidloop(int a, int b)
-
3. 테스트 케이스 설계
TC_euclid. 재귀적 방법과 반복적 방법을 각각 활용해서 1000번의 표본으로 각 방법의 실행시간을 계산하고, 각각의 방법으로 계산했을 때에 결과값이 서로 같은지 비교해본다.
 
 
<C코드 구현 결과>
//재귀함수를 이용한 최대공약수
int euclidjaegui(int a, int b)
{
    int sav;
    if (b > a)  //1. b가 a보다 작을 경우 자리변환
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
    if (b > a)  //b가 a보다 클 경우 a와 b 자리변환
    {
        sav = b;
        b = a;
        a = sav;
    }
   
    while (b != 0) //2. b(작은 수)가 0일 경우 a(0이 아닌 다른 수) 반환
    { //3. 큰 수에 작은 수를 나눈 후의 나머지 값과 작은 수를 기억한다.
        sav = b;
        b = a % b;
        a = sav;
      //4. 3의 과정을 반복하고, 2의 조건이 맞았을 때 큰 수를 반환한다.
    }
    return a;
}
 
 
 
// TC_Euclid
// 임의의 술단지의 수를 함수로 보내 최소 필요한 사람의 수를 반환받아 출력한다.
#define MAX 1000
void TC_euclid(void)
{
    int a[MAX], b[MAX], arrayl[MAX], arrayj[MAX], i;
    int n = 0;
    srand((unsigned int)time(NULL));
    for(i = 0; i < MAX; i++) { //변수 초기화
        a[i] = rand() % 1000;    //a에 1000보다 작은 수 대입
        b[i] = rand() % 1000;   //b에 1000보다 작은 수 대입
        arrayl[i] = 0;  //결과저장소 초기화
        arrayj[i] = 0;  //결과저장소 초기화
    }
    printf("반복을 이용한 최대공약수 계산에 걸리는 시간은 ");
    checktime(euclidloop, a, b, arrayl);
    printf("재귀를 이용한 최대공약수 계산에 걸리는 시간은 ");
    checktime(euclidjaegui, a, b, arrayj);
    printf("계산 결과를 서로 비교했을 때 틀린 횟수는 ");
    for(i = 0; i < MAX; i++) {  //각각의 배열에 결과값이 저장되어 있으므로
        if(arrayl[i] != arrayj[i])  //서로 다르면
            n += 1; //다른 횟수 추가
    }
    printf("%d회입니다.\n", n);
}
 
//시간 체크 함수
void checktime(int (*func)(int, int), int *a, int *b, int *res)   //인자로 받은 함수가 실행되는 시간을 출력해주는 함수
{
    clock_t start, finish; //clock_t : clock t의 자료를 담고 있는 자료형. clock()의 반환(return)형
    double duration;
    start = clock(); //clock() : 프로그램에 의해 프로세서가 소비된 시간 반환
    for(int i = 0; i < MAX; i++) {
        *(res + i) = (*func)(*(a + i), *(b + i));   //외부에서 받은 함수 실행
    }
    finish = clock();
    //시작시간과 끝시간을 clock()을 통해 도출하고, 차를 계산해 걸린 시간을 계산
    duration = (double)(finish - start) / CLOCKS_PER_SEC;   //CLOCKS_PER_SEC : 초당 clock ticks의 수를 나타내는 매크로. 이걸로 나눠줘야 초단위로 나옴.
    printf("%lf 초입니다. \n", duration);
}
 
 
 
 
<코드 저장소 링크>
https://github.com/HanSeooooL/Algorithm-exam-Euclid/tree/main/230406%20exam%20Euclid
