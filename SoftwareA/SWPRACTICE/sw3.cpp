#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> adj;
bool visited[10];

int ans = 0;

void backtrack(int idx, int sum) {

	if (idx == n) {
		ans = max(ans, sum);
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (visited[i]) continue;
			
			int left = -1;
			int right = -1;

			for (int l = i - 1; l >= 0; l--) {
				if (!visited[l]) {
					left = l;
					break;
				}
			}

			for (int r = i + 1; r < n; r++) {
				if (!visited[r]) {
					right = r;
					break;
				}
			}

			int score = 0;
			if (left != -1 && right != -1) score = adj[left] * adj[right];
			else if (left != -1) score = adj[left];
			else if (right != -1) score = adj[right];
			else score = adj[i];

			visited[i] = true;
			backtrack(idx + 1, sum + score);
			visited[i] = false;

		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	std::ios::sync_with_stdio(false);

	
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		cin >> n;

		adj.assign(n, 0);
		

		for (int i = 0; i < n; i++) {
			cin >> adj[i];
			visited[i] = 0;
		}

		ans = 0;

		backtrack(0, 0);

		cout << "#" << test_case << " " << ans << "\n";

	}

	return 0; // 정상종료시 반드시 0을 리턴해야 합니다.
}
