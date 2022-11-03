#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
int a[N];
map<int , int> mp;

int main(){

    cin.tie(0) -> sync_with_stdio(0);

    int n,z,pos,cnt= 0 , ch = 0;
    long long ans = 0;
    
    cin >> n >> z;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        if(a[i] == z){
            ch = 1;
            pos = i;
        }
        if(ch != 0){
            if(a[i] > z){
                cnt++;
            }
            if(a[i] < z){
                cnt--;
            }
            mp[cnt]++;
        }
    }
    cnt = 0;
    for(int i = pos ; i >= 1 ; i--){
        if(a[i] >z){
            cnt--;
        }
        if(a[i] <z){
            cnt++;
        }
        ans += mp[cnt];
    }
    cout << ans;
    
    return 0;
}

/*
7 4
5 7 2 4 3 1 6
*/