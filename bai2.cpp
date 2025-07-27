#include <bits/stdc++.h>
using namespace std;
const int MOD = 1'000'000'007;

struct Node {
    int child[26];
    bool word;
    Node() { memset(child, -1, sizeof child); word = false; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    if (!(cin >> S)) return 0;
    int N = S.size(), K;  cin >> K;

    vector<Node> trie(1);           
    auto add = [&](const string& w) {
        int v = 0;
        for (char ch : w) {
            int c = ch - 'a';
            if (trie[v].child[c] == -1) {
                trie[v].child[c] = trie.size();
                trie.emplace_back();
            }
            v = trie[v].child[c];
        }
        trie[v].word = true;
    };

    string w;
    for (int i = 0; i < K; ++i) {
        cin >> w;
        if ((int)w.size() <= N) add(w);  
    }

    vector<int> dp(N + 1, 0);
    dp[N] = 1;

    for (int i = N - 1; i >= 0; --i) {
        int v = 0;
        for (int j = i; j < N; ++j) {
            int c = S[j] - 'a';
            v = trie[v].child[c];
            if (v == -1) break;
            if (trie[v].word) {
                dp[i] += dp[j + 1];
                if (dp[i] >= MOD) dp[i] -= MOD;
            }
        }
    }
    cout << dp[0] << '\n';
    return 0;
}
