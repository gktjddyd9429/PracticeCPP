#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int population[11];
vector<int> graph[11];
bool selected[11];   // true = A 선거구, false = B 선거구
int answer = 1e9;


// 특정 선거구가 연결되어 있는지 확인
bool isConnected(bool type) {

    bool visited[11] = {false};
    queue<int> q;

    int start = -1;
    int totalCount = 0;

    // 해당 선거구에 속한 구역 개수 확인
    for (int i = 1; i <= N; i++) {
        if (selected[i] == type) {
            totalCount++;
            if (start == -1) {
                start = i;
            }
        }
    }

    // 선거구가 비어있는 경우
    if (start == -1) {
        return false;
    }

    // BFS 시작
    q.push(start);
    visited[start] = true;

    int connectedCount = 1;

    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {

            // 같은 선거구가 아니라면 이동 불가능
            if (selected[next] != type) {
                continue;
            }
            if (visited[next]) {
                continue;
            }
            visited[next] = true;
            q.push(next);

            connectedCount++;
        }
    }

    // 해당 선거구의 모든 구역을 방문했는지 확인
    return connectedCount == totalCount;
}


// 현재 만들어진 A/B 선거구 검사
void check() {

    // A 선거구 연결 확인
    if (!isConnected(true)) {
        return;
    }
    // B 선거구 연결 확인
    if (!isConnected(false)) {
        return;
    }


    int sumA = 0;
    int sumB = 0;

    for (int i = 1; i <= N; i++) {

        if (selected[i]) {
            sumA += population[i];
        }
        else {
            sumB += population[i];
        }
    }


    int diff = abs(sumA - sumB);

    answer = min(answer, diff);
}


// 부분집합 만들기
void backtrack(int idx) {

    // 모든 구역을 A/B로 나눴다면
    if (idx == N + 1) {
        check();
        return;
    }

    // idx번 구역을 A에 넣기
    selected[idx] = true;
    backtrack(idx + 1);


    // idx번 구역을 B에 넣기
    selected[idx] = false;
    backtrack(idx + 1);
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    // 인구수 입력
    for (int i = 1; i <= N; i++) {
        cin >> population[i];
    }

    // 인접 구역 입력
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


    if (answer == 1e9) cout << -1;
    else cout << answer;
    


    return 0;
}