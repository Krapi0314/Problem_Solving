/*
BOJ 2869번

시간 제한: 0.15초
메모리 제한: 128 MB

문제
땅 위에 달팽이가 있다. 이 달팽이는 높이가 V미터인 나무 막대를 올라갈 것이다.
달팽이는 낮에 A미터 올라갈 수 있다. 하지만, 밤에 잠을 자는 동안 B미터 미끄러진다. 또, 정상에 올라간 후에는 미끄러지지 않는다.
달팽이가 나무 막대를 모두 올라가려면, 며칠이 걸리는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 세 정수 A, B, V가 공백으로 구분되어서 주어진다. (1 ≤ B < A ≤ V ≤ 1,000,000,000)

출력
첫째 줄에 달팽이가 나무 막대를 모두 올라가는데 며칠이 걸리는지 출력한다. 
*/

#include <iostream>

using namespace std;

int main(void)
{

	int V, A, B;
	cin >> A >> B >> V;

	int cnt = 0;

	//V-A 까지 오면 무조건 정상에 도착
	if ((V - A) % (A - B) == 0) //도착 전날까지 딱 맞게 도착한다면
		cnt = (V - A) / (A - B);
	else //도착 전날까지 조금 남기고 도착한다면 (하루 더 가면 마지막 이동하면 도착할 정도)
		cnt = (V - A) / (A - B) + 1;
		

	cnt++; //마지막 이동
	
	cout << cnt << endl;
}
