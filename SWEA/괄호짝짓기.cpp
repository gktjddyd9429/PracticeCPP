#include<iostream>
#include<stack>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
  T= 10;


	for(test_case = 1; test_case <= T; ++test_case)
	{
    stack<char> s;
    int n;
    cin >> n;

    bool success = true;

    for (int i=0; i<n; i++){
      char c;
      cin >> c;

      if (c == '<' || c == '(' || c == '[' || c == '{') s.push(c);
      else{
        if(s.empty()) {success= false; continue;}
        char temp = s.top();
        s.pop();
        if (temp == '<' && c != '>') success = false;
        if (temp == '[' && c != ']') success = false;
        if (temp == '{' && c != '}') success = false;
        if (temp == '(' && c != ')') success = false;
      }
    }
    if (!s.empty()) success = false;

    if (success) cout << "#" << test_case << " " << 1 << "\n";
    else cout << "#" << test_case << " " << 0 << "\n";
  }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}