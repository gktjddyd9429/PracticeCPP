#include<iostream>
#include<string>
#include<stack>

using namespace std;

int getPriority(char op){
  if (op == '*') return 2;
  if (op == '+') return 1;
  return 0;
}

int main(int argc, char** argv)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
	int test_case;
	int T;
	
	T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    int N;
    cin >> N;

    string s; 
    cin >> s;

    string postFix;
    stack<char> st;


    for (int i=0 ; i< N; i++){
      if (s[i] >= '0' && s[i] <= '9') postFix.push_back(s[i]);
      else if (s[i] == '(') st.push(s[i]);
      else if (s[i] == ')'){
        while (!st.empty() && st.top() != '('){
          postFix.push_back(st.top());
          st.pop();
        }

        if (!st.empty()) st.pop();
      }
      else {
        while (!st.empty() && getPriority(st.top()) >= getPriority(s[i])){
          postFix.push_back(st.top());
          st.pop();
        }
        st.push(s[i]);
      } 
    }

    while(!st.empty()){
      postFix.push_back(st.top());
      st.pop();
    }

    stack<int> num_st;
    for (char ch : postFix) {
      if (ch >= '0' && ch <= '9'){
        num_st.push(ch-'0');
      }
      else{
        int op2 = num_st.top(); num_st.pop();
        int op1 = num_st.top(); num_st.pop();

        if (ch == '+') num_st.push(op1 + op2);
        if (ch == '*') num_st.push(op1 * op2);

      }
    }
    cout << "#" << test_case << " " << num_st.top() << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}