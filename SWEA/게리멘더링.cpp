#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<int> population;
vector<vector<int>> graph;
vector<bool> selected;
int answer = 1e9; 

bool isConnected(bool type) {
    vector<bool> visited(N + 1, false);
    queue<int> q;
    int start = -1;
    int totalCount = 0;

    for (int i = 1; i <= N; i++) {
        if (selected[i] == type) {
            totalCount++;
            if (start == -1) start = i;
        }
    }

    if (start == -1) return false;

    q.push(start);
    visited[start] = true;
    int connectedCount = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (selected[next] != type || visited[next]) continue;
            visited[next] = true;
            q.push(next);
            connectedCount++;
        }
    }

    return connectedCount == totalCount;
}

void check() {
    if (!isConnected(true) || !isConnected(false)) return;

    int sumA = 0, sumB = 0;
    for (int i = 1; i <= N; i++) {
        if (selected[i]) sumA += population[i];
        else sumB += population[i];
    }

    answer = min(answer, abs(sumA - sumB));
}

void backtrack(int idx) {
    if (idx == N + 1) {
        check();
        return;
    }

    selected[idx] = true;
    backtrack(idx + 1);

    selected[idx] = false;
    backtrack(idx + 1);
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    population.assign(N + 1, 0);
    graph.assign(N + 1, vector<int>());
    selected.assign(N + 1, false);

    for (int i = 1; i <= N; i++) {
        cin >> population[i];
    }

    for (int i = 1; i <= N; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int next;
            cin >> next;
            graph[i].push_back(next);
        }
    }

    backtrack(1);

    if (answer == 1e9) cout << -1 << "\n";
    else cout << answer << "\n";

    return 0;
}