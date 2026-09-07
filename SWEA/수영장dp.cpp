#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> op;

int day, month, threeMonth, year;

vector<int> plan;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    cin >> day >> month >> threeMonth >> year;
    
    plan.assign(13,0);
    for (int i=1; i<=12; i++){
      cin >> plan[i];
    }

    int ans;

    vector<int> dp(13);

    dp[0] = 0;
    dp[1] = min(dp[0] + plan[1]*day, dp[0] + month);
    dp[2] = min(dp[1] + plan[2]*day, dp[1] + month);
    for (int i=3; i<13; i++){
      dp[i] = min({ dp[i-1] + (plan[i]*day), dp[i-1]+ month, dp[i-3] + threeMonth});
    }
    dp[12] = min(dp[12], year);

    cout << "#" << test_case << " " << dp[12] << "\n";
    
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}