#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;



	std::ios::sync_with_stdio(false);


	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		int N;
		cin >> N;

		vector<int> v;
		vector<int> diff;

		v.assign(N + 1, 0);
		diff.assign(N + 1, 0);

		int ans_cnt = 0;
		int total_num = 0;

		for (int i = 1; i <= N; i++) {
			cin >> v[i];
			total_num += v[i];
		}

		for (int i = 1; i <= N; i++) {
			diff[i] = abs(max(v[i] + i, i) - v[i]);
		}

		/*for (int i = 1; i <= N; i++) {
			cout << diff[i] << " ";
		}
		cout << "\n";*/

		while (total_num < N * 2) {
			int temp_idx = -1;
			int temp_num = 0;

			for (int i = 1; i <= N; i++) {
				if (temp_num < diff[i]) {
					temp_idx = i;
					temp_num = diff[i];
				}
			}
			v[temp_idx] = max(temp_idx, v[temp_idx] + temp_idx);
			diff[temp_idx] = -1;
			ans_cnt++;
			total_num = 0;

			for (int i = 1; i <= N; i++) {
				total_num += v[i];
			}

			//cout << "확인" <<total_num << "\n";
		}

		cout << "#" << test_case << " " << ans_cnt << "\n";


	}

	return 0; // 정상종료시 반드시 0을 리턴해야 합니다.
}
