#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<vector<bool>> visited;
vector<vector<int>> result;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int N;

struct Node
{
	int x;
	int y;
	int cost;

	bool operator<(const Node &other) const
	{
		return this->cost > other.cost;
	}
};

int dikjstra(int x, int y)
{
	priority_queue<Node> pq;
	pq.push({x, y, 0});
	result[y][x] = 0;

	while (!pq.empty())
	{
		int dx = pq.top().x;
		int dy = pq.top().y;
		int dcost = pq.top().cost;

		pq.pop();

		if (result[dy][dx] < dcost) continue;

		for (int i = 0; i < 4; i++)
		{
			int nx = dx + dc[i];
			int ny = dy + dr[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;

			if (adj[ny][nx] + dcost < result[ny][nx])
			{
				result[ny][nx] = adj[ny][nx] + result[dy][dx];
				pq.push({nx, ny, dcost + adj[ny][nx]});
			}
		}
	}
	return result[N - 1][N - 1];
}

int main(int argc, char **argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		adj.assign(N, vector<int>(N,0));
		result.assign(N, vector<int>(N, 1e9));

		for (int i = 0; i < N; i++)
		{
			string s;
			cin >> s;
			for (int j = 0; j < N; j++)
			{
				adj[i][j] = (s[j] - '0');
			}
		}

		int ans = dikjstra(0, 0);

		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}