/*
BOJ 2661번: 좋은수열

시간 제한: 1초
메모리 제한: 128 MB

문제
숫자 1, 2, 3으로만 이루어지는 수열이 있다. 임의의 길이의 인접한 두 개의 부분 수열이 동일한 것이 있으면, 그 수열을 나쁜 수열이라고 부른다. 그렇지 않은 수열은 좋은 수열이다.
다음은 나쁜 수열의 예이다.

33
32121323
123123213
다음은 좋은 수열의 예이다.

2
32
32123
1232123
길이가 N인 좋은 수열들을 N자리의 정수로 보아 그중 가장 작은 수를 나타내는 수열을 구하는 프로그램을 작성하라. 예를 들면, 1213121과 2123212는 모두 좋은 수열이지만 그 중에서 작은 수를 나타내는 수열은 1213121이다.

입력
입력은 숫자 N하나로 이루어진다. N은 1 이상 80 이하이다.

출력
첫 번째 줄에 1, 2, 3으로만 이루어져 있는 길이가 N인 좋은 수열들 중에서 가장 작은 수를 나타내는 수열만 출력한다. 수열을 이루는 1, 2, 3들 사이에는 빈칸을 두지 않는다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
int n;
bool flag;

bool promising(int num)
{
	ans.push_back(num);
	int len = ans.size();

	for (int i = 1; i <= len/2; i++)
	{
		string s1 = "";
		string s2 = "";

		for (int j = 0; j < i; j++)
		{
			s1 += to_string(ans[len - (2 * i) + j]);
			s2 += to_string(ans[len - i + j]);
		}

		if (s1 == s2)
		{
			ans.pop_back();
			return false;
		}
	}

	ans.pop_back();
	return true;
}

void dfs(int cnt)
{
	if (flag)
		return;

	if (cnt == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << ans[i];
		}
		flag = true;
		return;
	}

	for (int i = 1; i <= 3; i++)
	{
		if (ans.empty() || promising(i))
		{
			ans.push_back(i);
			dfs(++cnt);
			ans.pop_back();
			cnt--;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	dfs(0);
}

/*
완전탐색, 백트래킹

vector<int> ans //n자리 가장 작은 좋은 수열
int arr[3] = {1,2,3}

bool promising(int num) //num까지 추가했을 때 좋은 수열이 되는지 확인
	비교 횟수와 기준은 길이의 절반
	ex) 길이가 6이면 for 3번, 인접한 길이 i의 substr 2개 검사

	int len = ans.size()
	
	for i 1 to len/2 //길이의 절반만큼 검사
		string s1 = "";
		string s2 = "";

		for j 0 to j<i //길이 i만큼 ans 벡터에서 인접한 string s1,s2을 각각 substr 한 후
			s1 += to_string(ans[len - (2 * i) + j]);
			s2 += to_string(ans[len - i + j]);
		
		if(s1 == s2) //둘이 같으면 나쁜 수열
			return false
	
	return true
			

void dfs(int cnt) //n자리 가장 작은 좋은 수열, cnt은 지금까지의 자릿수(길이)
	if(flag)
		return

	if(cnt == n)
		//가장 첫번째로 찾는 좋은 수열이 답
		for n
			cout vector ans
			flag = true
		return
	
	for(int i=0; i<3; i++) //다음 자리 결정: 1,2,3 중
		if(ans.empty || promising(arr[i])) //가능하면
			vector pushback arr[i]
			dfs(++cnt) //dfs
			vector popback
			cnt--

cin >> n
dfs(0)
cout << ans
*/
