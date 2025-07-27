#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    multiset<long long> tails;

    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        auto it = tails.lower_bound(x);   
        if (it == tails.begin()) {
            tails.insert(x);
        } else {
            --it;          
            tails.erase(it);    
            tails.insert(x);
        }
    }
    cout << tails.size() << '\n';
    return 0;
}
