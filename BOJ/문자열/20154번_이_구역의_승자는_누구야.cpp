/*
BOJ 20154번: 이 구역의 승자는 누구야?!

시간 제한: 1 초
메모리 제한: 1024 MB

문제
가톨릭대학교에 다니는 컴퓨터정보공학부 황톨릭은 코로나 때문에 슬퍼하는 친구들을 위해 게임을 하나 만들었다.
게임이 시작되면 알파벳 대문자로만 이루어진 문자열이 주어진다. 문자열이 주어지면 각 문자의 획수로 문자를 변환한다. 획수들을 갖고 앞에서부터 두 개씩 더해가는데 만약 짝이 지어지지 않는다면 그대로 다음 단계로 내려간다. 다음 단계부터는 이전 단계에서 두 개씩 더해가며 생성된 숫자들을 가지고 같은 과정을 반복한다. 과정을 반복하다가 결국 마지막 한 개의 수가 남았을 때 그 수가 홀수라면 이기는 것이고 짝수라면 지는 게임이다!!
예를 들어 "ABCDE"라는 문자열이 주어지면 ‘A’, ‘B’, ‘C’, ‘D’, ‘E’ 각 문자의 획수인 3, 2, 1, 2, 3으로 바꾸어 아래의 그림처럼 과정을 진행한다. 단, 계산할 때, 더한 값이 10을 넘는다면 10으로 나눈 나머지로 바꿔준다.
‘E’의 경우는 짝을 지을 수 없으므로 3이 바로 내려오게 된다. 결국, 마지막 남은 수가 1인 홀수이므로 이 게임은 이기게 되는 것이다.
게임의 심판역할인 톨릭이는 매번 계산하는 게 귀찮아 코드를 짜놓고 싶어한다. 톨릭이를 도와 코드를 짜주자!!
알파벳 대문자의 획수는 아래 표와 같다.

A	B	C	D	E	F	G	H	I	J	K	L	M	N	O	P	Q	R	S	T	U	V	W	X	Y	Z
3	2	1	2	3	3	3	3	1	1	3	1	3	3	1	2	2	2	1	2	1	1	2	2	2	1

입력
첫째 줄에 알파벳 대문자로만 이루어진 길이 K(1 ≤ K ≤ 1,000,000)인 문자열 S가 주어진다.

출력
첫째 줄에 정답을 출력한다.
마지막으로 남은 수가 홀수라면 "I'm a winner!"를 출력하고 0이거나 짝수라면 "You're the winner?"를 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int strokes[26] = { 3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1 };
string str;
string temp;
int len;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> str;
	len = (int)str.size();
	
	for(int i=0; i<len; i++) {
		str[i] = strokes[(int)(str[i]-'A')];
	}

	while((len = (int)str.size()) != 1) {
		temp.clear();
		
		for(int i=0; i < len; i+=2) {
			if(i == len-1) {
				temp += str[i];
			}
			else {
				temp += ((int)str[i] + (int)str[i+1]) % 10;
			}
		}
		
		str = temp;
	}
	
	if((int)str[0] % 2 == 0) {
		cout << "You're the winner?";
	}
	else {
		cout << "I'm a winner!";
	}
	
	return 0;
}

/*
문자열 
*/
