#include <bits/stdc++.h>
using namespace std;
using u64 = uint64_t;

vector<int> primes;                

int vpf(int n, int p) {
    int s = 0;
    for (int t = n; t; t /= p) s += t / p;
    return s;
}

int main() {
    vector<bool> isPrime(500, true);
    for (int i = 2; i * i < 500; ++i)
        if (isPrime[i])
            for (int j = i * i; j < 500; j += i) isPrime[j] = false;
    for (int i = 2; i < 500; ++i) if (isPrime[i]) primes.push_back(i);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    while (cin >> N >> K) {
        if (K > N) swap(K, N);            
        K = min(K, N - K);                

        if (K == 0) {
            cout << 1 << '\n';
            continue;
        }

        u64 ans = 1;
        for (int p : primes) {
            if (p > N) break;
            int e = vpf(N, p) - vpf(K, p) - vpf(N - K, p);
            if (e) ans *= (e + 1);        
        }
        cout << ans << '\n';
    }
    return 0;
}
