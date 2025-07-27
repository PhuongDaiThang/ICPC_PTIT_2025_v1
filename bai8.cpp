#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int64 A, B; 
        cin >> A >> B;
        int64 d = llabs(A - B);
        if (d == 0) {                 
            cout << 0 << '\n';
            continue;
        }

        int64 k = ceil((sqrtl(1 + 8.0L * d) - 1) / 2);
        int64 S = k * (k + 1) / 2;

        while ((S - d) & 1) {
            ++k;
            S += k;                 
        }
        cout << k << '\n';
    }
    return 0;
}
