#include <iostream>
#include <vector>
#include <algorithm>

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

		vector<int> A(N);
		vector<int> B(N);

		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

		for (int i = 0; i < N; i++) {
			cin >> B[i];
		}

		int ans = 0;

		for (int i = 0; i < N; i++) {
			bool visited[201] = { false, };
			int sum = 0;

			for (int j = i; j < N; j++) {
				if (visited[B[j]]) break;
				visited[B[j]] = true;
				sum += A[j];
				ans = max(ans, sum);

			}
		}
		cout << "#" << test_case << " " << ans << "\n";

	}

	return 0; // 정상종료시 반드시 0을 리턴해야 합니다.
}
