#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
vector<int> pop;             // 구역별 인구수
vector<vector<int>> adj;     // 인접 리스트
vector<int> a;               // 1번부터 N번까지의 구역 번호
vector<int> t;               // 선거구 A에 포함된 구역
int min_diff = 1e9;          // 인구 차이 최솟값 (초기값은 무한대로 설정)

// 특정 선거구 내의 구역들이 모두 연결되어 있는지 BFS로 확인하는 함수
bool check_connected(const vector<int>& subset) {
    if (subset.empty()) return false;

    // 현재 탐색 중인 선거구에 속한 노드 표시
    vector<bool> in_subset(N + 1, false);
    for (int node : subset) {
        in_subset[node] = true;
    }

    queue<int> q;
    vector<bool> visited(N + 1, false);

    // 선거구의 첫 번째 구역을 시작점으로 설정
    int start_node = subset[0];
    q.push(start_node);
    visited[start_node] = true;

    int count = 1;

    // BFS 탐색
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : adj[curr]) {
            // 인접한 구역이 같은 선거구에 속해있고, 아직 방문하지 않았다면 큐에 삽입
            if (in_subset[next] && !visited[next]) {
                visited[next] = true;
                q.push(next);
                count++;
            }
        }
    }

    // BFS로 방문한 구역의 수와 선거구의 총 구역 수가 같다면 모두 연결된 것
    return count == subset.size();
}

// 작성해주신 형태의 부분집합 로직
void subset_func(int idx) {
    if (idx == N) {
        // 어느 한 선거구에 몰빵된 경우(공집합 혹은 전체집합)는 유효하지 않으므로 제외
        if (t.empty() || t.size() == N) return;

        vector<int> b; // 선거구 B
        vector<bool> is_a(N + 1, false);
        
        // t 배열에 들어있는 구역은 선거구 A
        for (int i = 0; i < t.size(); i++) {
            is_a[t[i]] = true;
        }
        
        // t 배열에 없는 구역은 자동으로 선거구 B로 분류
        for (int i = 1; i <= N; i++) {
            if (!is_a[i]) {
                b.push_back(i);
            }
        }

        // 두 선거구 모두 내부적으로 연결되어 있는지 BFS로 검사
        if (check_connected(t) && check_connected(b)) {
            int sum_a = 0, sum_b = 0;
            for (int node : t) sum_a += pop[node];
            for (int node : b) sum_b += pop[node];

            int diff = abs(sum_a - sum_b);
            min_diff = min(min_diff, diff);
        }
        return;
    }

    // 1. 현재 구역을 선거구 A(t)에 포함시키는 경우
    t.push_back(a[idx]);
    subset_func(idx + 1);
    t.pop_back();

    // 2. 현재 구역을 선거구 A에 포함시키지 않는 경우 (선거구 B로 감)
    subset_func(idx + 1);
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    pop.resize(N + 1);
    adj.resize(N + 1);
    
    // 인구수 입력 및 a 배열 초기화
    for (int i = 1; i <= N; i++) {
        cin >> pop[i];
        a.push_back(i); 
    }

    // 인접 구역 정보 입력
    for (int i = 1; i <= N; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int neighbor;
            cin >> neighbor;
            adj[i].push_back(neighbor);
        }
    }

    // 인덱스 0부터 부분집합 탐색 시작
    subset_func(0);

    // 가능한 방법이 없는 경우 -1 출력
    if (min_diff == 1e9) {
        cout << -1 << "\n";
    } else {
        cout << min_diff << "\n";
    }

    return 0;
}