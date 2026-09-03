#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	T= 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    int n; cin >> n;

    string s; cin >> s;
    stack<int> st;
    vector<int> v;
    int temp;

    for (int i=0; i < n; i++){
      int current = s[i]-'0';
      if (!st.empty() && current == st.top()) st.pop();
      else st.push(current);
    }

    while(!st.empty()){
      v.push_back(st.top());
      st.pop();
    }
    cout <<"#" << test_case << " ";
    for (int i=v.size()-1; i>=0; i--){
      cout << v[i];
    }
    cout << "\n";



	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}