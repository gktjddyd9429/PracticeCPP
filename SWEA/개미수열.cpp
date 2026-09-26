#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if(n<=2){
        cout << 1 << "\n";
    }
    else if (n <= 5){
        cout << 2 << "\n";
    }
    else{
        cout << 3 << "\n";
    }

    return 0;
    
}