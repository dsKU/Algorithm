#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
#include<utility>
typedef long long ll;
using namespace std;

int map[501][501];
int DP[501][501];
int n;
int answer = 0;
int dx[] = { -1,0,1, 0 };
int dy[] = { 0,1, 0,-1 };
int solve(int x , int y) {
	if (DP[x][y])
		return DP[x][y];
	DP[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
		if (map[x][y] >= map[nx][ny]) continue;
		DP[x][y] = max(DP[x][y], solve(nx, ny) + 1);
	}

	return DP[x][y];
	
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			answer = max(answer, solve(i, j));
		}
	}

	cout << answer << endl;

}