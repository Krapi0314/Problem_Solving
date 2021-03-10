/*
BOJ 1181번: 단어 정렬

시간 제한: 2초
메모리 제한: 256 MB

문제
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.
길이가 짧은 것부터
길이가 같으면 사전 순으로

입력
첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.

출력
조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다. 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX	50

int N;
vector<char*> v;
int cnt; //몇번 중복됬는지 셈

bool pred(char*& a, char*& b)
{
	if (strlen(a) != strlen(b))
	{
		return strlen(a) < strlen(b);
	}
	else
	{
		if (strcmp(a, b) < 0) //b가 더 크면
			return true;
		else
			return false;
	}
}

bool unique_pred(char*& a, char*& b)
{
	if (strcmp(a, b) == 0)
	{
		cnt++;
		return true;
	}
	else
		return false;
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		char* str = new char[MAX + 1];
		scanf("%s", str);
		v.push_back(str);
	}

	sort(v.begin(), v.end(), pred);
	unique(v.begin(), v.end(),unique_pred);
	
	for (int i = 0; i < v.size()-cnt; i++)
	{
		printf("%s\n", v[i]);
	}
}

/*
* 단어 정렬: sort 함수, 조건자 pred: 길이 짧은 단어 먼저, 길이가 같으면 사전 순으로
* 알파벳 소문자로 이루어짐
* 문자열의 길이는 51 (널문자 포함)
* 같은 단어가 여러변 입력됬으면 한번만 출력 = unique 함수
* 
* 1. 입력: vector에 저장
* 2. 정렬: sort 함수, 조건자 pred 사용
* 3. 제거: unique 함수 사용
* 4. 출력: vector 저장된 순으로 출력
*/
