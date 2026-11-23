#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<int> inDegree;

int N;
int ans = -1;

void topology() {
	queue<int> q;
	vector<int> sem(N + 1);
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			sem[i] = 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (q.empty()) {
			ans = -1;
			return;
		}

		int x = q.front();
		q.pop();
		ans = sem[x];

		for (int j = 0; j < adj[x].size(); j++) {
			int y = adj[x][j];
			if (--inDegree[y] == 0) {
				sem[y] = sem[x] + 1;
				q.push(y);
			}
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
		
		cin >> N;
		
		adj.assign(N + 1, vector<int>());
		inDegree.assign(N + 1, 0);
		for (int i = 1; i <= N; i++) {
			int input;
			cin >> input;
			for (int j = 0; j < input; j++) {
				int num;
				cin >> num;
				adj[num].push_back(i);
				inDegree[i]++;
			}
		}
		ans = -1;
		/*for (int i = 1; i <= N; i++) {
			cout << inDegree[i] << " ";
		}
		cout << "\n";*/
	
		topology();

		cout << "#" << test_case << " " << ans << "\n";
	}

	return 0; // 정상종료시 반드시 0을 리턴해야 합니다.
}
