#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 방향: 0(상), 1(우), 2(하), 3(좌)
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

// look[d][t] : 현재 로봇의 방향이 d일 때, t번째(우, 앞, 좌, 뒤)로 탐색할 실제 방향
int look[4][4] = {
	{1, 0, 3, 2}, // 현재 '상(0)' 방향: 우(1), 상(0), 좌(3), 하(2) 순서로 탐색
	{2, 1, 0, 3}, // 현재 '우(1)' 방향: 하(2), 우(1), 상(0), 좌(3) 순서로 탐색
	{3, 2, 1, 0}, // 현재 '하(2)' 방향: 좌(3), 하(2), 우(1), 상(0) 순서로 탐색
	{0, 3, 2, 1}  // 현재 '좌(3)' 방향: 상(0), 좌(3), 하(2), 우(1) 순서로 탐색
};

void solve() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int N, M;
		cin >> N >> M;

		vector<vector<int>> grid(N, vector<int>(N));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> grid[i][j];
			}
		}

		int max_harvests = 0;

		for (int sr = 0; sr < N; ++sr) {
			for (int sc = 0; sc < N; ++sc) {
				if (grid[sr][sc] == 1) continue;

				for (int sd = 0; sd < 4; ++sd) {
					vector<vector<int>> sprout_count(N, vector<int>(N, 0));
					vector<vector<int>> ready_day(N, vector<int>(N, 0));

					int harvests = 0;
					int r = sr, c = sc, d = sd;

					for (int day = 1; day <= M; ++day) {

						// [1] 오전 작업
						if (ready_day[r][c] > 0 && day >= ready_day[r][c]) {
							harvests++;
							ready_day[r][c] = 0;
						}
						else if (ready_day[r][c] == 0) {

							bool can_move = false;
							// 현재 방향 d에 맞춰 look[d] 행의 순서대로 탐색
							for (int t = 0; t < 4; ++t) {
								int nd = look[d][t]; // 모듈러 연산 없이 2차원 배열에서 바로 방향 획득
								int nr = r + dr[nd];
								int nc = c + dc[nd];

								if (nr >= 0 && nr < N && nc >= 0 && nc < N && grid[nr][nc] != 1) {
									if (ready_day[nr][nc] == 0 || day >= ready_day[nr][nc]) {
										can_move = true;
										break;
									}
								}
							}

							if (can_move) {
								sprout_count[r][c]++;
								ready_day[r][c] = day + sprout_count[r][c] + 4;
							}
						}

						// [2] 오후 작업 (이동)
						for (int t = 0; t < 4; ++t) {
							int nd = look[d][t]; // 이동 시에도 동일하게 look 2차원 배열 사용
							int nr = r + dr[nd];
							int nc = c + dc[nd];

							if (nr >= 0 && nr < N && nc >= 0 && nc < N && grid[nr][nc] != 1) {
								if (ready_day[nr][nc] == 0 || day >= ready_day[nr][nc]) {
									r = nr;
									c = nc;
									d = nd;
									break;
								}
							}
						}
					}

					if (harvests > max_harvests) {
						max_harvests = harvests;
					}
				}
			}
		}
		cout << "#" << tc << " " << max_harvests << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}