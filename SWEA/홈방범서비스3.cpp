#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;

vector<vector<int>> arr;

int total_max = 0; 

void debug(int i, int j, int k, int cnt, int cost) {
    cout << "중심: (" << i << ", " << j << ")\n";
    cout << "반경: " << k << "\n";
    cout << "집 개수: " << cnt << "\n";
    cout << "운영 비용: " << cost << "\n";
    cout << "수익: " << cnt * M << "\n";
    cout << "이익: " << cnt * M - cost << "\n";
    cout << "-----------------\n";
}

void manhattan(){
    for (int i =0 ; i < N ;i++){
        for (int j = 0 ; j < N; j++){
            for (int k =1; k < 2*N-1; k++){
                int cnt =0;
                int cost = k*k + (k-1)*(k-1);
                for (int i2 =0; i2 < N; i2++){
                    for (int j2=0; j2<N; j2++){
                        if (abs(i-i2) + abs(j-j2) < k && arr[i2][j2] == 1){
                            cnt++;
                        }
                    }
                }

                if (cnt*M - cost >= 0){
                    total_max = max(total_max, cnt);
                    debug(i,j,k,cnt,cost);
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> M;

        arr.assign(N,vector<int>(N,0));

        for (int i =0; i<N; i++){
            for (int j = 0; j<N; j++){
                cin >> arr[i][j];
            }
        }

        total_max = 0; 
        manhattan();
        cout << "#" << test_case << " " << total_max << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}