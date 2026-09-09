
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> v;
    v.assign(N, vector<int>(N));



    for (int i=0; i< N; i++){
      for (int j =0; j < N; j++){
        cin >> v[i][j];
      }
    }

    int total_len = 0;
    for (int i =0; i<N; i++){
      for (int j=0; j<N; j++){
        for (int k=1; k<2*N; k++){
          int gold = 0;
          for (int t =0; t<N; t++){
            for (int w=0; w<N; w++){
              if(abs(t-i) + abs(w-j) < k && v[t][w] == 1) gold++;
            }
          }

          int cost = k*k + (k-1) * (k-1);
          int temp = gold*M - cost;

          if (temp >= 0){
            total_len= max(total_len, gold);
          }
        }
      }
    }

    cout << "#" << test_case << " " << total_len << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}