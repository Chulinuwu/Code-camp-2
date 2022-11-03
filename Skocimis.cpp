#include <bits/stdc++.h>

using namespace std;

int a[2];

int main(){
	
	int ans;

    ans =0;
	
	scanf("%d %d %d", &a[0],&a[1],&a[2]);
	
    sort(a,a+3);

    ans = a[2]-a[1] - 1;

    printf("%d",ans);
	
return 0;

}