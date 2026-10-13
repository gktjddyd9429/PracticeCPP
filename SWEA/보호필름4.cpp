#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int D, W, K;

int total_min = 1e9;

vector<vector<int>> v;

void debug(int cnt) {
	cout << "디버깅\n";
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "약투여 :" << cnt << "\n";
	cout << " \n";
}

bool check_col(int w) {
	if (K == 1) return true;
	int total_num = 1;
	for (int i = 1; i < D; i++) {
		if (v[i - 1][w] != v[i][w]) {
			total_num = 1;
		}
		else {
			total_num++;
			if (total_num >= K) {
				return true;
			}
		}
	}
	return false;
}

void changeRow(int r, int num) {
	for (int i = 0; i < W; i++) {
		v[r][i] = num;
	}
}

void backtrack(int idx, int insertMedCnt) {
	if (insertMedCnt >= total_min) return;
	if (idx == D) {
		bool temp = false;
		for (int i = 0; i < W; i++) {
			if (!check_col(i)) {
				return;
			}
		}

		//debug(insertMedCnt);
		total_min = min(total_min, insertMedCnt);

		return;
	}
	else {
		backtrack(idx + 1, insertMedCnt);

		vector<int> temp = v[idx];
		
		changeRow(idx, 0);
		backtrack(idx + 1, insertMedCnt + 1);
		//debug(insertMedCnt);
		v[idx] = temp;
	

		changeRow(idx, 1);
		backtrack(idx + 1, insertMedCnt + 1);
		//debug(insertMedCnt);
		v[idx] = temp;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> D >> W >> K;

		v.assign(D, vector<int>(W, 0));

		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> v[i][j];

			}
		}

		total_min = 1e9;

		backtrack(0, 0);

		cout << "#" << test_case << " " << total_min << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}