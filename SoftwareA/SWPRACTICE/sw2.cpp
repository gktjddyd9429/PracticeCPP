#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
vector<int> b;

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

		a.assign(N, 0);
		b.assign(N, 0);
		
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < N; i++) {
			cin >> b[i];
		}

		int r =0, l =0;
		int sum = 0;
		int ans = 0;
		bool t[501] = { false, };

		for (r =0 ; r < N; r++) {
			while (t[b[r]]) {
				t[b[l]] = false;
				sum -= a[l];
				l++;
			}
			sum += a[r];
			t[b[r]] = true;
			ans = max(ans, sum);
		}

		cout << "#" << test_case << " " << ans << "\n";
	}

	return 0; // 정상종료시 반드시 0을 리턴해야 합니다.
}
