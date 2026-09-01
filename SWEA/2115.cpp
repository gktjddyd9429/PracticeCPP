#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> v;
vector<vector<int>> profit;
int max_profit_in_window;


int N, M, C;


void backtrack(int r, int c, int depth, int sum, int prof) {
	if (sum > C) return;

	if (depth == M) {
		max_profit_in_window = max(max_profit_in_window, prof);
		return;
	}
	else {
		int current_honey = v[r][c + depth];
		backtrack(r, c, depth + 1, sum + current_honey, prof + (current_honey * current_honey));
		backtrack(r, c, depth + 1, sum, prof);
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case;
	int T;

	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M >> C;
		v.assign(N, vector<int>(N, 0));
		profit.assign(N, vector<int>(N, 0));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> v[i][j];
			}
		}


		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= N - M; j++) {
				max_profit_in_window = 0;
				backtrack(i,j,0,0,0);
				profit[i][j] = max_profit_in_window;
			}
		}

		int ans = 0;

		for (int i1 = 0; i1 < N; i1++) {
			for (int j1 = 0; j1 <= N - M; j1++) {
			
				for (int i2 = i1; i2 < N; i2++) {
					int start_j2 = (i1 == i2) ? (j1 + M) : 0;

					for (int j2 = start_j2; j2 <= N - M; j2++) {
						int  total_profit = profit[i1][j1] + profit[i2][j2];
						ans = max(ans, total_profit);
					}
				}
			}
		}

		
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}