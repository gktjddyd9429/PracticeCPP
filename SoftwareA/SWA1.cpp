#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node {
	int r;
	int c;
	int dist;
};

int main() {
	// 입출력 속도 향상을 위한 설정 (백준 필수)
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	if (!(cin >> T)) return 0;

	for (int test_case = 1; test_case <= T; test_case++) {
		int N;
		cin >> N;

		vector<Node> house(N);
		// 집의 위치를 빠르게 확인하기 위한 2차원 배열 (31x31)
		vector<vector<bool>> is_house(31, vector<bool>(31, false));

		for (int i = 0; i < N; i++) {
			int x, y, d;
			cin >> x >> y >> d;

			// 좌표 평행이동 (-15~15 -> 0~30)
			int c = x + 15;
			int r = y + 15;

			house[i] = { r, c, d };
			is_house[r][c] = true; // 해당 좌표에 집이 있음을 표시
		}

		int ans = 1e9;

		// [1] 충전소 1개 짓는 경우 탐색
		for (int r = 0; r <= 30; r++) {
			for (int c = 0; c <= 30; c++) {
				if (is_house[r][c]) continue; // 집에 충전소를 지을 수 없음

				bool possible = true;
				int sum_dist = 0;

				for (int k = 0; k < N; k++) {
					int dist = abs(house[k].r - r) + abs(house[k].c - c);
					if (dist > house[k].dist) {
						possible = false;
						break; // 허용 거리를 초과하면 탐색 중단
					}
					sum_dist += dist;
				}

				if (possible) {
					ans = min(ans, sum_dist);
				}
			}
		}

		// 1개로 커버가 가능하면 바로 정답 출력 후 다음 테스트 케이스로 넘어감 (조건 ①)
		if (ans != 1e9) {
			cout << "#" << test_case << " " << ans << "\n";
			continue;
		}

		// [2] 충전소 2개 짓는 경우 탐색
		for (int r1 = 0; r1 <= 30; r1++) {
			for (int c1 = 0; c1 <= 30; c1++) {
				if (is_house[r1][c1]) continue;

				// 중복 조합 방지를 위해 두 번째 충전소는 첫 번째 충전소 이후의 좌표만 탐색
				for (int r2 = r1; r2 <= 30; r2++) {
					int start_c = (r1 == r2) ? c1 + 1 : 0;
					for (int c2 = start_c; c2 <= 30; c2++) {
						if (is_house[r2][c2]) continue;

						bool possible = true;
						int sum_dist = 0;

						for (int k = 0; k < N; k++) {
							int dist1 = abs(house[k].r - r1) + abs(house[k].c - c1);
							int dist2 = abs(house[k].r - r2) + abs(house[k].c - c2);

							// 각 집마다 두 충전소 중 더 가까운 거리를 선택
							int min_dist = min(dist1, dist2);

							if (min_dist > house[k].dist) {
								possible = false;
								break;
							}
							sum_dist += min_dist;
						}

						if (possible) {
							ans = min(ans, sum_dist);
						}
					}
				}
			}
		}

		// [3] 결과 출력
		if (ans == 1e9) {
			cout << "#" << test_case << " -1\n"; // 2개로도 불가능한 경우
		}
		else {
			cout << "#" << test_case << " " << ans << "\n";
		}
	}

	return 0;
}