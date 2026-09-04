#include <iostream>
#include <vector>

using namespace std;

vector<int> a = { 1, 2, 3, 4, 5 };
vector<int> sub; // 선택된 원소들만 동적으로 담을 벡터
int N = 5;

void subset(int idx) {
	// 종료 조건: 배열의 끝까지 탐색을 마쳤을 때
	if (idx == N) {
		cout << "{ ";
		for (int val : sub) {
			cout << val << " ";
		}
		cout << "}\n";
		return;
	}

	// 1. 현재 원소(a[idx])를 부분집합에 포함하는 경우
	sub.push_back(a[idx]); // 상태 변화: 넣는다
	subset(idx + 1);       // 다음 원소 탐색

	// 2. 현재 원소(a[idx])를 부분집합에 포함하지 않는 경우
	sub.pop_back();        // 백트래킹(원상복구): 방금 넣었던 걸 다시 뺀다
	subset(idx + 1);       // 다음 원소 탐색
}

int main() {
	cout << "=== 5. 부분집합 (push/pop 방식) ===\n";
	subset(0);
	return 0;
}