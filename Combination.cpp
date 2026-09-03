#include <iostream>
#include <vector>

using namespace std;

vector<int> a = {1, 2, 3, 4, 5};
vector<int> t;
vector<bool> visited; // 순열에서 사용될 방문 체크 배열

int N = 5;
int R = 3;

void print_arr() {
    for (int i = 0; i < R; i++) {
        cout << t[i] << " ";
    }
    cout << "\n";
}

// --------------------------------------------------------
// 1. 순열 (Permutation) : 순서 O, 중복 X
// --------------------------------------------------------
void perm(int idx) {
    if (idx == R) {
        print_arr();
    } else {
        // 순서가 중요하므로 항상 처음(0)부터 끝까지 탐색
        for (int i = 0; i < N; i++) {
            // 아직 뽑지 않은 숫자만 선택 (중복 방지)
            if (!visited[i]) {
                visited[i] = true; // 뽑았다고 표시
                t[idx] = a[i];
                perm(idx + 1);     // 다음 빈칸 채우러 이동
                visited[i] = false; // 백트래킹: 원상복구하여 다음 경우의 수 탐색
            }
        }
    }
}

// --------------------------------------------------------
// 2. 중복순열 (Permutation with Repetition) : 순서 O, 중복 O
// --------------------------------------------------------
void pi(int idx) {
    if (idx == R) {
        print_arr();
    } else {
        // 순서도 중요하고, 중복도 허용됨
        // 따라서 고민할 것 없이 매번 처음(0)부터 끝까지 다 넣어봄
        for (int i = 0; i < N; i++) {
            t[idx] = a[i];
            pi(idx + 1); // 다음 빈칸 채우러 이동 (조건 없음)
        }
    }
}

// --------------------------------------------------------
// 3. 중복조합 (Combination with Repetition) : 순서 X, 중복 O
// --------------------------------------------------------
void comb_rep(int idx, int s) { // s: 시작 인덱스
    if (idx == R) {
        print_arr();
    } else {
        // 순서가 없으므로 내가 지금 뽑은 것보다 앞의 것은 보지 않음 (시작점 s부터 탐색)
        for (int i = s; i < N; i++) {
            t[idx] = a[i];
            // 중요: 중복이 허용되므로, 다음 빈칸을 채울 때 '나 자신(i)'부터 다시 뽑을 수 있음
            // 따라서 i + 1이 아니라 i를 그대로 넘겨줌
            comb_rep(idx + 1, i); 
        }
    }
}

// --------------------------------------------------------
// (참고용) 기존 조합 (Combination) : 순서 X, 중복 X
// --------------------------------------------------------
void comb(int idx, int s) {
    if (idx == R) {
        print_arr();
    } else {
        // 가지치기(최적화) 적용: i <= N - R + idx
        for (int i = s; i <= N - R + idx; i++) {
            t[idx] = a[i];
            // 중복이 안되므로, 무조건 내 다음 칸(i + 1)부터 뽑게 함
            comb(idx + 1, i + 1);
        }
    }
}

int main() {
    t.resize(R);
    visited.resize(N, false); // N개만큼 방문 배열 초기화

    cout << "=== 1. 순열 ===" << "\n";
    perm(0); // 인덱스 추적만 필요함

    cout << "\n=== 2. 중복순열 ===" << "\n";
    pi(0); // 인덱스 추적만 필요함

    cout << "\n=== 3. 중복조합 ===" << "\n";
    comb_rep(0, 0); // 인덱스와 시작 위치 필요함

    cout << "\n=== 4. 조합 (기존) ===" << "\n";
    comb(0, 0);

    return 0;
}