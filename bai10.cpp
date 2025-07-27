#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

struct Seg { int64 l, r; };              

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;               
    if (!(cin >> n)) return 0;

    vector<Seg> seg(n);
    int64 sumP = 0;
    for (int i = 0; i < n; ++i) {
        int64 h, p;      
        cin >> h >> p;
        seg[i] = {h, h + p};
        sumP  += p;
    }

    sort(seg.begin(), seg.end(),
         [](const Seg& a, const Seg& b) { return a.l < b.l; });

    int64 extra = 0;
    int64 curR  = seg[0].r;
    for (int i = 1; i < n; ++i) {
        if (seg[i].l > curR) {           
            extra += seg[i].l - curR;
            curR   = seg[i].r;           
        } else {
            curR = max(curR, seg[i].r);  
        }
    }

    cout << sumP + extra << '\n';
    return 0;
}
