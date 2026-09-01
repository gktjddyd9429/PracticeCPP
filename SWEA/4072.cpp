#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<string> dp;

string addBigNum(string num1, string num2){
        string result ="";
        int sum = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;

        while (i>=0 || j >= 0 || sum ){
            if (i >= 0){
                sum += num1[i] - '0';
                i--;
            }
            if (j >= 0){
                sum += num2[j] - '0';
                j--;
            }

            result += to_string(sum % 10);
            sum /= 10;
        }

        reverse(result.begin(), result.end());
        return result;
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
        int N; cin >> N;
        dp.assign(251, "");

        dp[0] = "0";
        dp[1] = "1";
        dp[2] = "3";
        for (int i=3; i<251; i++){
            string powNum = addBigNum(dp[i-2], dp[i-2]);
            dp[i] = addBigNum(dp[i-1] , powNum);
        }
        cout << "#" << test_case << " " << dp[N] << "\n"; 

	}
	return 0;
}