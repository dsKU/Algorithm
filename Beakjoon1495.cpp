#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
#include<utility>
typedef long long ll;
using namespace std;

int v[101];
int DP[101][1001];
int n,s,m;
int answer = 0;

int solve(int volume, int index) {
	if (volume < 0 || volume > m) return -1;
	if (index == n) return volume;
	if (DP[index][volume] != 0) return DP[index][volume];

	return DP[index][volume] = max(solve(volume + v[index + 1], index + 1),
		solve(volume - v[index + 1], index + 1));

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	
	answer = solve(s, 0) ;
	answer = answer == -2 ? -1 : answer;
	cout << answer << endl;

}