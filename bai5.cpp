#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 n;
    if (!(cin >> n)) return 0;

    vector<int64> fib = {1, 2};
    while (true) {
        int64 nxt = fib.back() + fib[fib.size() - 2];
        if (nxt > (int64)1e15) break;
        fib.push_back(nxt);
    }

    int64 ans = n;             
    int64 rem = n;
    for (int i = (int)fib.size() - 1; i >= 0 && rem; --i) {
        if (fib[i] <= rem) {
            ans = fib[i];           
            rem -= fib[i];
        }
    }

    cout << ans << '\n';
    return 0;
}
