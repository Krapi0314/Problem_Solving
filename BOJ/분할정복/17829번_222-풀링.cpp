/*
BOJ 17829번: 222-풀링

시간 제한: 1초
메모리 제한: 256 MB

문제
조기 졸업을 꿈꾸는 종욱이는 요즘 핫한 딥러닝을 공부하던 중, 이미지 처리에 흔히 쓰이는 합성곱 신경망(Convolutional Neural Network, CNN)의 풀링 연산에 영감을 받아 자신만의 풀링을 만들고 이를 222-풀링이라 부르기로 했다.
다음은 8×8 행렬이 주어졌다고 가정했을 때 222-풀링을 1회 적용하는 과정을 설명한 것이다

1. 행렬을 2×2 정사각형으로 나눈다.
2. 각 정사각형에서 2번째로 큰 수만 남긴다. 여기서 2번째로 큰 수란, 정사각형의 네 원소를 크기순으로 a4 ≤ a3 ≤ a2 ≤ a1 라 했을 때, 원소 a2를 뜻한다.
3. 2번 과정에 의해 행렬의 크기가 줄어들게 된다.

종욱이는 N×N 행렬에 222-풀링을 반복해서 적용하여 크기를 1×1로 만들었을 때 어떤 값이 남아있을지 궁금해한다.
랩실 활동에 치여 삶이 사라진 종욱이를 애도하며 종욱이의 궁금증을 대신 해결해주자.

입력
첫째 줄에 N(2 ≤ N ≤ 1024)이 주어진다. N은 항상 2의 거듭제곱 꼴이다. (N=2K, 1 ≤ K ≤ 10)
다음 N개의 줄마다 각 행의 원소 N개가 차례대로 주어진다. 행렬의 모든 성분은 -10,000 이상 10,000 이하의 정수이다. 

출력
마지막에 남은 수를 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int arr[1025][1025];

int two3pulling(int x, int y, int len) {
	if(len == 1) {
		return arr[x][y];
	}
	
	vector<int> v(4);
	
	v[0] = two3pulling(x,y,len/2);
	v[1] = two3pulling(x, y-len/2,len/2);
	v[2] = two3pulling(x-len/2, y,len/2);
	v[3] = two3pulling(x-len/2, y-len/2,len/2);
	
	sort(v.begin(), v.end());
	
	return v[2]; 
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> arr[i][j];
		}
	}
	
	cout << two3pulling(n, n, n);
}

/*
분할정복 
*/
