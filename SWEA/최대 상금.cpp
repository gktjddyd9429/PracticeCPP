#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

string s;
int target_cnt, ans;

set<pair<string,int>> visited;

void backtrack(int current_cnt){
	if (current_cnt == target_cnt) {
      ans = max(ans, stoi(s));
      return;
    }
    
    if (visited.count({s, current_cnt})) return; 
    visited.insert({s, current_cnt});
        
        for (int i=0; i< s.size() -1; i++){
        	for (int j= i+1; j < s.size(); j++){
            	swap(s[i],s[j]);
              backtrack(current_cnt+1);
              swap(s[i], s[j]);
            }
            
            
        }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> s >> target_cnt;
        ans = 0;
        visited.clear();
        backtrack(0);
        
        cout << "#" << test_case << " " << ans << "\n";
     

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}