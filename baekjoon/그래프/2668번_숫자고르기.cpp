/*
baekjoon 2668��: ���ڰ���

�ð� ����: 1��
�޸� ����: 128 MB

����
���� �� ��, ���η� N���� ĭ���� �̷���� ǥ�� �ִ�. ù° ���� �� ĭ���� ���� 1, 2, ��, N�� ���ʴ�� ��� �ְ� ��° ���� �� ĭ���� 1�̻� N������ ������ ��� �ִ�. ù° �ٿ��� ���ڸ� ������ ������, �� ���� �������� �̷�� ���հ�, ���� �������� �ٷ� ���� ��° �ٿ� ����ִ� �������� �̷�� ������ ��ġ�Ѵ�. �̷��� ������ ������Ű���� �������� �̵�, �ִ�� ���� �̴� ����� ã�� ���α׷��� �ۼ��Ͻÿ�. ���� ���, N=7�� ��� �Ʒ��� ���� ǥ�� �־����ٰ� ����.
�� ��쿡�� ù° �ٿ��� 1, 3, 5�� �̴� ���� ���̴�. ù° ���� 1, 3, 5�ؿ��� ���� 3, 1, 5�� ������ �� ������ ��ġ�Ѵ�. �̶� ������ ũ��� 3�̴�. ���� ù° �ٿ��� 1�� 3�� ������, �̵� �ٷ� �ؿ��� ���� 3�� 1�� �����Ƿ� �� ������ ��ġ�Ѵ�. �׷���, �� ��쿡 ���� ������ ������ �ִ밡 �ƴϹǷ� ���� �� �� ����.

�Է�
ù° �ٿ��� N(1��N��100)�� ��Ÿ���� ���� �ϳ��� �־�����. �� ���� �ٺ��ʹ� ǥ�� ��° �ٿ� ���� �������� ������� �� �ٿ� �ϳ��� �Էµȴ�.

���
ù° �ٿ� ���� �������� ������ ����ϰ�, �� ���� �ٺ��ʹ� ���� �������� ���� ������ ū ���� ������ �� �ٿ� �ϳ��� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int arr[101];
bool visited[101];
vector<int> cycle;
vector<int> ans;
vector<int> ans_plus;
int cnt;
int first;

void dfs(int vertex) {

	// �̹� �湮�ߴ� ù��° �������� ���ƿԴٸ� -> ����Ŭ �ϼ��� 
	if(vertex == first && visited[vertex]) {
		// !! ����Ŭ�� ���� �� ������ �ش� ����Ŭ���� ��� ���� ������ ���� �� !!
		ans.insert(ans.begin(), cycle.begin(), cycle.end());
	}
	// �湮���� �ʾҴٸ� 
	else if(!visited[vertex]) {
		visited[vertex] = true;
		cycle.push_back(vertex);
		dfs(arr[vertex]);
	}
	// �̿��� ���: �湮������ ����Ŭ�� �ƴ� ��� 
	else {
		return;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	// ����Ŭ�� �̷�� ������ ã��
	
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
	}

	// ��� ������ ���� dfs
	for(int i=1; i<=n; i++) {
		// �湮 ��� �ʱ�ȭ
		// �ڱ����� �����̸� -> ans_plus�� ����
		if(arr[i] == i) {
			ans_plus.push_back(i);
		}
		else {
			memset(visited, false, sizeof(visited));
			cycle.clear();
			first = i;
			dfs(i);
		}
	}
		
	// ans + ans_plus ���� ��ģ�� sort
	ans.insert(ans.end(), ans_plus.begin(), ans_plus.end());
	sort(ans.begin(),ans.end());
	
	// �����̹Ƿ� ���� ���� ����
	ans.erase(unique(ans.begin(), ans.end()),ans.end());
	cnt = ans.size();
	
	// ���
	cout << cnt << "\n";
	for(int i=0; i<cnt; i++) {
		cout << ans[i] << "\n";
	}  
}

/*
dfs - cycle
*/
