/*
BOJ 3029번: 경고

시간 제한: 1초
메모리 제한: 128 MB

문제
창영마을에서 정인이의 반란은 실패로 끝났다. (3028번)
테러리스트로 변신한 정인이는 창영마을에 경고를 하려고 한다.
사실 정인이는 창영마을에서 제일 착한사람이다. 따라서, 사람들을 다치지 않게하려고 한다.
유튜브에서 폭발에 대한 동영상을 찾아보다가, 그는 나트륨을 물에 던지면 폭발한다는 사실을 알게 되었다.
정인이는 창영마을의 중심을 지나는 "강산강" 근처에 숨어있다가, 나트륨을 위의 동영상처럼 물에 던질 것이다.
현재 시간과 정인이가 나트륨을 던질 시간이 주어졌을 때, 정인이가 얼마나 숨어있어야 하는지 구하는 프로그램을 작성하시오. (정인이는 적어도 1초를 기다리며, 많아야 24시간을 기다린다.)

입력
첫째 줄에 현재 시간이 hh:mm:ss 형식으로 주어진다. (시, 분, 초) hh는 0보다 크거나 같고, 23보다 작거나 같으며, 분과 초는 0보다 크거나 같고, 59보다 작거나 같다.
둘째 줄에는 나트륨을 던질 시간이 위와 같은 형식으로 주어진다.

출력
첫째 줄에 정인이가 기다려야 하는 시간을 입력과 같은 형식으로 출력한다. 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

string start_string, end_string;
int result_sec, start_sec, end_sec;
int hour, minu, sec;
int num;

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	
	vector<int> startv(3), endv(3);
	scanf("%d:%d:%d", &startv[0], &startv[1], &startv[2]);
	scanf("%d:%d:%d", &endv[0], &endv[1], &endv[2]);

	start_sec = startv[0] * 3600 + startv[1] * 60 + startv[2];
	end_sec = endv[0] * 3600 + endv[1] * 60 + endv[2];

	if (start_sec < end_sec)
	{
		result_sec = end_sec - start_sec;
	}
	else if(start_sec == end_sec || start_sec > end_sec)
	{
		result_sec = 24 * 3600 + end_sec - start_sec;
	}

	hour = result_sec / 3600; result_sec -= hour * 3600;
	minu = result_sec / 60; result_sec -= minu * 60;

	printf("%02d:%02d:%02d", hour, minu, result_sec);
}

/*
시간 차이

모두 sec으로 바꾸어 계산 후 변환

!!정민이는 적어도 1초를 기다리므로,
00:00:00
00:00:00와 같은 경우
24시간을 기다린 것이 됨
*/
