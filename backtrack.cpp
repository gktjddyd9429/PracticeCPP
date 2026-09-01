#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, W;
vector<int> v;
int ans = 1e9;

void backtrack(int idx, int num) {
	if (num >= W) {
		ans = min(ans, num);
		return;
	}
	else {
		if (idx >= N) return;
		backtrack(idx+1, num);
		backtrack(idx+1, num + v[idx]);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> W;
		v.assign(N+1, 0);

		ans = 1e9;

		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}

		backtrack(0, 0);
		
		cout << "#" << test_case << " " << ans - W << "\n";

	}
	return 0;
}