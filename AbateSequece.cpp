#include <bits/stdc++.h>

using namespace std;

int a[100100], lis[100100];

vector <int> ans,v[100100];

int main(){

    int n, maxx = 0 , ind;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]),a[i] *= -1;
    }

    for(int i = 1 ; i <= n ; i++){
        ind = lower_bound(lis,lis+maxx,a[i]) - lis;
        if(maxx == ind){
            maxx++;
        }
        lis[ind] = a[i];
        v[ind].push_back(a[i]);
    }

    int last = v[maxx-1][0];

    ans.push_back(last);

    for(int i = maxx-2 ; i >= 0 ; i--){
        for(int j = 0 ; j < v[i].size() ; j++){
            if(v[i][j] < last){
                ans.push_back(v[i][j]);
                last = v[i][j];
                break;
            }
        }
    }
    printf("%d\n",maxx);

    for(int i= ans.size()-1 ; i>= 0 ; i--){
        printf("%d " , ans[i] *= -1);
    }


    return 0;

}
