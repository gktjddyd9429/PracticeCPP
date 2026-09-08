#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
// 가로줄 정보를 담을 벡터: pair<높이 b, 세로줄 위치 a>
vector<pair<int, int>> lines; 
vector<int> target_result; // 모든 선을 그었을 때의 결과
int min_lines = INT_MAX;   // 최소 가로줄 개수 (초기값은 무한대)

// 주어진 가로줄들로 사다리 타기 결과를 반환하는 함수
vector<int> simulate(const vector<pair<int, int>>& selected_lines) {
    vector<int> current_result(N + 1);
    
    // 1. 초기 배열 세팅 (1번 자리에 1, 2번 자리에 2...)
    for (int i = 1; i <= N; i++) {
        current_result[i] = i;
    }

    // 2. 가로줄을 위에서부터 차례대로 만나면서 자리(swap) 바꾸기
    for (int i = 0; i < selected_lines.size(); i++) {
        int a = selected_lines[i].second;
        swap(current_result[a], current_result[a + 1]);
    }

    return current_result;
}

// 백트래킹(완전 탐색)으로 가로줄을 선택하는 함수
void find_min_lines(int idx, int count, vector<pair<int, int>>& selected_lines) {
    // [가지치기] 이미 찾은 최소 개수보다 현재 선택한 개수가 많거나 같으면 더 볼 필요 없음
    if (count >= min_lines) return;

    // 마지막 가로줄까지 선택 여부를 다 결정했을 때
    if (idx == M) {
        // 현재 선택한 가로줄들로 사다리를 탔을 때, 타겟 결과와 똑같다면
        if (simulate(selected_lines) == target_result) {
            min_lines = min(min_lines, count); // 최솟값 갱신
        }
        return;
    }

    // 경우의 수 1: 현재(idx번째) 가로줄을 선택하는 경우
    selected_lines.push_back(lines[idx]); 
    find_min_lines(idx + 1, count + 1, selected_lines);
    selected_lines.pop_back(); // 원상복구

    // 경우의 수 2: 현재(idx번째) 가로줄을 선택하지 않는 경우
    find_min_lines(idx + 1, count, selected_lines);
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        // 높이(b) 기준으로 먼저 정렬하기 위해 b를 first에, a를 second에 넣습니다.
        lines.push_back({b, a}); 
    }

    // 가로줄을 위에서부터 아래로(높이 오름차순) 정렬
    sort(lines.begin(), lines.end());

    // 1. 모든 가로줄을 사용했을 때 우리가 만들어야 하는 '목표 결과'를 구합니다.
    target_result = simulate(lines);

    // 2. 백트래킹 시작
    vector<pair<int, int>> selected;
    find_min_lines(0, 0, selected);

    // 3. 결과 출력
    cout << min_lines << "\n";

    return 0;
}