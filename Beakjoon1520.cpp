#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
#include<utility>
typedef long long ll;
using namespace std;

int v[501][501];
int DP[501][501];
int n, m;
int answer = 0;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int solve(int x, int y) {
	if (DP[x][y] != -1) return DP[x][y];
	//if (x <1 || y <1 || x >n || y > m) return 0;
	if (x == 1 && y == 1) return 1;
	DP[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx <1 || ny <1 || nx >n || ny > m) continue;
		if (v[x][y] < v[nx][ny])
			DP[x][y] += solve(nx, ny);
	}

	return DP[x][y];

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> v[i][j];
			DP[i][j] = -1;
		}
		

	
	cout << solve(n,m) << endl;

}