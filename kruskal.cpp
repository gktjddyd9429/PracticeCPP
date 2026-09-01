#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int N;
vector<int> parent;
vector<int> ranked;

class Edge {
public:
	int Node[2];
	double distance;

	Edge(int start, int end, double distance) {
		this->Node[0] = start;
		this->Node[1] = end;
		this->distance = distance;
	}

	bool operator < (const Edge& e) {
		return this->distance < e.distance;
	}
};

int find(int v) {
	if (parent[v] != v) parent[v] = find(parent[v]);
	return parent[v];
}

void union_sets( int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		if (ranked[a] < ranked[b]) swap(a, b);
		parent[b] = a;
		if (ranked[a] == ranked[b]) ranked[a]++;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{

		cin >> N;
		vector<Edge> v;
		vector<int> islandX;
		vector<int> islandY;


		for (int i = 0; i < N; i++) {
			int x;
			cin >> x ;
			islandX.push_back(x);
		}
		for (int i = 0; i < N; i++) {
			int y;
			cin >> y;
			islandY.push_back(y);
		}
		double E = 0;
		cin >> E;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;

				int x1 = islandX[i];
				int y1 = islandY[i];
				int x2 = islandX[j];
				int y2 = islandY[j];

				long long dx = x2 - x1;
				long long dy = y2 - y1;
				double distance = (double)(dx * dx + dy * dy);

				v.push_back(Edge(i, j, (distance * E)));
			}
		}

		parent.assign(N + 1, 0);
		ranked.assign(N + 1, 0);

		for (int i = 0; i < N; i++) {
			parent[i] = i;
			ranked[i] = 0;
		}
		sort(v.begin(), v.end());

		double cost = 0;

		for (Edge edges : v) {
			if (find(edges.Node[0]) != find(edges.Node[1])) {
				cost += edges.distance;
				union_sets(edges.Node[0],edges.Node[1]);
			}
		}

		cout << "#" << test_case << " " << (long long)round(cost) << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}