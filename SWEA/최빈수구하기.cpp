#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

int main(int argc, char** argv)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    int n;
    cin >> n;

    vector<int> cnt(101);

    for (int i=1; i<1001; i++){
      int input;
      cin >> input;
      cnt[input]++;
    }

    int max_num=0;
    int max_idx=0;

    for (int i=0; i<101; i++){
      if (max_num <= cnt[i]){
        max_num = cnt[i];
        max_idx = i;
      }
    }
    cout << "#" << test_case << " " << max_idx << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}