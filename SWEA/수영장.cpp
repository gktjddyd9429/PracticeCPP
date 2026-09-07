#include<iostream>
#include<vector>
#include<algorithm>
int day, month, threeMonth, year;

using namespace std;
int total_min = 1e9;

vector<int> plan(13);


void backtrack(int idx, int num){
  if (idx > 12) total_min = min(total_min, num);
  else{

    // s 필요없을것 같은데? -> 조합이 아닌 것 같다. 그냥 해당 내용 다구하는 것 같음.
    // 최소값을 계산한 것을 넘기게.

    // 1일
    backtrack(idx+1, num + plan[idx]*day);
    // 1달
    backtrack(idx+1, num + month);
    // 3달
    backtrack(idx+3, num + threeMonth);
    // 1년
    backtrack(idx+13, year);
  }
}

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
    
    total_min = 1e9;

    backtrack(0,0);
    cout << "#" << test_case <<" " << total_min << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}