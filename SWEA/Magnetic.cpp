#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    int t;
    cin >> t;
    vector<vector<int>> v;

    v.assign(100,vector<int>(100,0));
    for (int i=0; i<100; i++){
      for (int j=0; j<100; j++){
        cin >> v[i][j];
      }
    } 
    int total_cnt = 0;

    for (int i=0; i<100; i++){
      bool red= false;
      for (int j=0; j<100; j++){
        if(v[j][i] == 1){
          red = true;
        } 
        if(red && v[j][i] == 2){
          red = false;
          total_cnt++;
        }
      }
    }
    cout << "#" << test_case << " " << total_cnt << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}