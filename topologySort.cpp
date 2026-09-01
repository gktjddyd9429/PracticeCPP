#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, E;

vector<int> inDegree;
vector<int> result;
vector<vector<int>> adj;

void topology()
{
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}

	for (int i = 1; i <= N; i++)
	{
		if (q.empty())
			result;

		int x = q.front();
		q.pop();
		result[i] = x;

		for (int j = 0; j < adj[x].size(); j++)
		{
			int y = adj[x][j];
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}
}

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int test_case;
	int T;
	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> E;

		adj.assign(N + 1, vector<int>());
		result.assign(N + 1, 0);
		inDegree.assign(N + 1, 0);

		for (int i = 1; i <= E; i++)
		{
			int start, end;
			cin >> start >> end;
			adj[start].push_back(end);
			inDegree[end]++;
		}
		topology();

		cout << "#" << test_case << " ";
		for (int i = 1; i <= N; i++)
		{
			cout <<result[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}