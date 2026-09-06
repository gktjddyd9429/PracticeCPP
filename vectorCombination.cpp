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
        for (int i = 0; i < N; i++){
            if (visited[i]) continue;

            visited[i] = true;
            t.push_back(a[i]);
            perm(idx+1);
            t.pop_back();
            visited[i] = false;
        }
    }
}

// --------------------------------------------------------
// 2. 중복순열 (Permutation with Repetition) : 순서 O, 중복 O
// --------------------------------------------------------
void pi(int idx) {
    if (idx == R) {
        print_arr();
    }
    else {
        for (int i = 0; i < a.size(); i++){
            t.push_back(a[i]);
            pi(idx+1);
            t.pop_back();
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
        for (int i = s; i < a.size(); i++) {
            t.push_back(a[i]);
            comb_rep(idx + 1, i);
            t.pop_back();
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
        for (int i = s; i< a.size(); i++) {
            t.push_back(a[i]);
            comb(idx+1, i+1);
            t.pop_back();
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