#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin >> N;
        vector<vector<int>> v;
        v.assign(N, vector<int>(N,1e9));

        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (i==j) continue;
                cin >> v[i][j];
            }
        }


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}