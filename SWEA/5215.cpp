#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv){

  int test_case;
  int T;
  
  cin >> T;

  for (test_case = 1; test_case <= T; ++test_case){

    int N,L;
    cin >> N >> L;

    vector<vector<int>> dp;
    dp.assign(N+1, vector<int>(L+1,0));

    vector<int> T(N+1);
    vector<int> K(N+1);

    for (int i=1; i<=N; i++){
      cin >> T[i] >> K[i];
    }

    for (int i = 1; i<=N; i++){
      for (int w = 0; w<=L; w++){
        if (w <K[i]){
          dp[i][w] = dp[i-1][w];
        }
        else{
          dp[i][w] = max(dp[i-1][w], dp[i-1][w - K[i]]+T[i]);
        }
      }
    }
  }
}