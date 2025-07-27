#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int N, M;
vector<int> A;

bool ok(int X) {
    int prev = 0;                        
    for (int a : A) {
        int high = a + X;
        if (high < M) {                 
            if (prev < a) prev = a;     
            else if (prev > high) return false;
        } else {                         
            int wrap = high - M;         
            if (prev > wrap && prev < a) prev = a;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> N >> M)) return 0;
    A.resize(N);
    for (int &x : A) cin >> x;

    int l = 0, r = M - 1, ans = M - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << ans << '\n';
    return 0;
}
