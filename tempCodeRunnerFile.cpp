#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int j = i + 1;
        while (j < n && a[j] <= a[i]) {
            j++;
        }
        ans += j - i - 1;
    }

    cout << ans << endl;


    return 0;

}
