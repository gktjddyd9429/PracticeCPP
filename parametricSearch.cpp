#include<iostream>
#include<vector>
using namespace std;

int N, M; 
vector<int> v;
bool ok(int t){
    int sum = 0;

    vector<int> v(N);
    for (int i = 0 ;i <N; i++){
        sum += (v[i] / t);
    }
    if (sum >= M) return true;
    else return false;
}

int main(){
    cin >> N >> M;
    v.assign(N,0);
    int mx=0;

    for (int i =0; i<N; i++){
        int x; cin >> x;
        v[i] = x;
        mx = max(mx,x);
    }

    int ans=0;
    int L = 1;
    int R = mx;

    while (L <= R){
        int mid = (L+R)/2;

        if (ok(mid)){
            ans = mid;
            L = mid+1;
        }
        else{
            R=mid-1;
        }
    }
    cout << ans << "\n";
}