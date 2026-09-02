#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	T= 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;


    vector<vector<int>> v;
    v.assign(100,vector<int>(100,0));

    for (int i=0; i<100; i++){
      for (int j=0; j<100; j++){
        cin >> v[i][j];
      }
    }

    int total_max=0;

    for (int i=0; i < 100; i++){
      int temp=0;
      for (int j=0; j < 100; j++){
        temp += v[i][j];
      }
      total_max = max(temp,total_max);

      temp=0;
      for (int j=0; j < 100; j++){
        temp += v[j][i];
      }
      total_max = max(temp,total_max);
    }
    int temp =0;
    for (int i=0; i < 100; i++){
      temp += v[i][i]; 
      total_max = max(temp,total_max);
    }

    temp =0;
    for (int i=0; i < 100; i++){
      temp += v[i][100-i]; 
      total_max = max(temp,total_max);
    }

    cout << "#" <<test_case << " " << total_max << "\n";


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}