#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
vector<int> plan;
vector<int> dp;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

        v.assign(13,0);
        plan.assign(13,0);
        dp.assign(13,1e9);

        for (int i=0; i<4; i++){
            cin >> plan[i];
        }

        for (int i=1; i <= 12; i++){
            cin >> v[i];
        }

        dp[0] = 0;
        dp[1] = min(dp[0]+plan[1], dp[0]+(plan[0] * v[1]));
        
        for (int i=2; i<=12; i++){
            if(i >= 3) { dp[i] =  min ({ dp[i-1]+plan[1], dp[i-1]+(plan[0] * v[i]), dp[i-3]+plan[2]}); continue; }
            dp[i] = min(dp[i-1]+plan[1], dp[i-1]+(plan[0] * v[i]));
        }
        dp[12] = min(dp[12], plan[3]);

        cout << "#" << test_case << " " << dp[12] << "\n";

	}
	return 0;
}