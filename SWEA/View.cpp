#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

	int test_case;

	
	for(test_case = 1; test_case <= 10; ++test_case)
	{
    vector<int> v;

    int N;
    cin >> N;

    for (int i=0; i<N; i++){
      int input;
      cin >> input;
      v.push_back(input);
    }

    int total_cnt = 0;

    for (int i=2; i < N-2; i++){
      int t= 0;
      for (int j= -2 ; j <= 2; j++){
        if (j==0) continue;
        t = max(t,v[i+j]);
      }
      total_cnt += max(0, v[i]- t);
    }

    cout << "#" << test_case << " " << total_cnt << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}