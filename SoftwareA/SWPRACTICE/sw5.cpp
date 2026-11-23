#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> v;
vector<int> sum;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	std::ios::sync_with_stdio(false);

	
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		int N, K;
		cin >> N >> K;
		
		v.assign(N, 0);
		sum.assign(N-K+1, 0);

		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}

		for (int i = 0; i <= N-K; i++) {
			for (int j = 0; j < K; j++) {
				sum[i] += v[i + j];
			}
		}

		/*for (int i = 0; i < N - 1; i++) {
			cout << sum[i] << " ";
		}
		cout << "\n";*/
		int ans =-1e9;
		for (int i = 0; i <= N - K; i++) {
			for (int j = i + K; j <= N - K; j++) {
				ans = max(ans, sum[i] + sum[j]);
			}
		}

		cout << "#" << test_case << " " << ans << "\n";
	}

	return 0; // 정상종료시 반드시 0을 리턴해야 합니다.
}
