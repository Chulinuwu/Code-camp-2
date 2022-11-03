#include <bits/stdc++.h>

using namespace std;

long long a[2001000];
stack <long long> st;

int main(){

long long n , i , j , l ,r ,mid , ch , now;

scanf("%lld" , &n);

for(i = 1 ; i <= n ; i ++){
    scanf("%lld", &a[i]);
}

l = 0 , r = 1e18;

while(l < r){

    mid = ( l + r) / 2 ;
    ch = 0;

    for( i = 1 ; i <= n ; i++){
        if(a[i] <= mid){
            continue;
        }
        st.push(a[i]);
    }
    while(!st.empty()){
        now = st.top();
        st.pop();
        if( now != st.top()){
            ch = 1;
            break;
        }
        else{
            st.pop();
        }
    }
    while(!st.empty()){
        st.pop();
    }
    if(ch){
        l = mid +1;
    }
    else{
        r = mid;
    }

}

  printf("%lld" , l);

return 0;

}

/*
6
3
3
2
5
5
2

6
3
3
2
2
5
5


6
3
5
2
2
5
3
*/
