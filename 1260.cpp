#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

int N, M, V;
using namespace std;

int checkedbfs[1001];
int checkeddfs[1001];
vector <int> v[1001];

void dfs(int t) {

	if (checkeddfs[t]) {
		return;
	}

	cout << t << " ";
	checkeddfs[t] = 1;


	sort(v[t].begin(), v[t].end());

	for (int i = 0; i < v[t].size(); i++) {
		int x = v[t][i];
		dfs(x);
	}
}

void bfs(int st) {
	queue<int> q;

	q.push(st);
	checkedbfs[st] = 1;
	int x, y;

	while (!q.empty()) {
		x = q.front();
		cout << x << " ";
		q.pop();

		sort(v[x].begin(), v[x].end());
		for (int i = 0; i < v[x].size(); i++) {
			y = v[x][i];
			if (!checkedbfs[y]) {
				q.push(v[x][i]);
				checkedbfs[y] = 1;

			}
		}
	}

}

int main() {
	int a, b;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(V);
	cout << endl;
	bfs(V);

}
