/*
BOJ 1913번: 달팽이

시간 제한: 2초
메모리 제한: 128 MB

문제
홀수인 자연수 N이 주어지면, 다음과 같이 1부터 N2까지의 자연수를 달팽이 모양으로 N×N의 표에 채울 수 있다.
9	2	3
8	1	4
7	6	5

25	10	11	12	13
24	9	2	3	14
23	8	1	4	15
22	7	6	5	16
21	20	19	18	17
N이 주어졌을 때, 이러한 표를 출력하는 프로그램을 작성하시오. 또한 N2 이하의 자연수가 하나 주어졌을 때, 그 좌표도 함께 출력하시오. 예를 들어 N=5인 경우 6의 좌표는 (4,3)이다.

입력
첫째 줄에 홀수인 자연수 N(3 ≤ N ≤ 999)이 주어진다. 둘째 줄에는 위치를 찾고자 하는 N2 이하의 자연수가 하나 주어진다.

출력
N개의 줄에 걸쳐 표를 출력한다. 각 줄에 N개의 자연수를 한 칸씩 띄어서 출력하면 되며, 자릿수를 맞출 필요가 없다. N+1번째 줄에는 입력받은 자연수의 좌표를 나타내는 두 정수를 한 칸 띄어서 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int num;
int sign;
int x,y;
int arr[1000][1000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	num = n * n;
	x = 0; y = 0;
	sign = 1; // 이동하는 방향 
	
	// 전체 배열 완성 후 출력 
	// 별도의 for문으로 첫번째 run 구현 
	for(int i=0; i<n; i++) {
		arr[y][x] = num--; // 배열에 num 삽입 
		y += sign; // 이동하는 방향만큼 좌표 이동 
	}
	
	y--;
	// 이중 for문으로 달팽이 배열의 규칙 구현 
	for(int i = n-1; i>=0; i--) {
		for(int j=0; j<i; j++) {
			x += sign;	
			arr[y][x] = num--;
		}
		sign *= -1; // 이동방향 reverse 
		for(int j=0; j<i; j++) {
			y += sign;	
			arr[y][x] = num--;
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	
	cin >> num;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(arr[i][j] == num) {
				cout << i+1 << " " << j+1;
				return 0;
			}
		}
	}
}

/*
구현
규칙성: n = 5인 경우, 반시계 방향으로 규칙적으로 5,4,4,3,3,2,2,1,1 씩 이동함
해당 규칙을 활용하여 이중 for문 구현 (첫번째 run, 5는 따로 따로 for문 구현) 
*/
