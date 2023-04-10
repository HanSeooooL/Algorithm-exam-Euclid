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
