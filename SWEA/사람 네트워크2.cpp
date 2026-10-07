#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        int N;
        cin >> N;

        vector<vector<int>> adj(N);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int value;
                cin >> value;

                if (value == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        int answer = 1'000'000'000;
        vector<int> dist(N);
        vector<int> q(N);

        for (int start = 0; start < N; ++start) {
            fill(dist.begin(), dist.end(), -1);

            int head = 0;
            int tail = 0;
            q[tail++] = start;
            dist[start] = 0;

            int sum = 0;
            int visitedCount = 1;

            while (head < tail &&
                   visitedCount < N &&
                   sum < answer) {
                int cur = q[head++];

                for (int next : adj[cur]) {
                    if (dist[next] != -1) continue;

                    dist[next] = dist[cur] + 1;
                    sum += dist[next];
                    q[tail++] = next;
                    ++visitedCount;

                    if (visitedCount == N || sum >= answer) {
                        break;
                    }
                }
            }

            if (visitedCount == N) {
                answer = min(answer, sum);
            }

      
            if (answer == N - 1) break;
        }

        cout << "#" << tc << " " << answer << '\n';
    }

    return 0;
}