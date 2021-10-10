#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll s;
ll n;

bool valid(ll n) {
	if(s - (n*(n-1))/2 >= n)
		return true;
	else
		return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	
	ll l = 0;
	ll r = s;
	ll m = 0;
	while(l <= r) {
		m = (l+r) / 2;
		
		if(valid(m) && !valid(m+1)) {
			break;
		}
		else if(valid(m+1)) {
			l = m + 1;
		}
		else if(!valid(m)){
			r = m - 1;
		}
	}
	
	cout << m;
}

/*
파라메트릭 서치
!! 범위가 1~4,294,967,295 이므로 계산하는 모든 변수/매개변수들의 자료형은 ll 이상이어야 함. 
*/
