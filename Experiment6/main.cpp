#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Maximum total characters across all strings is 6 * 10^5
const int MAXN = 600005;

int trie[MAXN][3];
bool is_end[MAXN];
int node_cnt = 0;

// Insert a string into the Trie
void insert(const string& s) {
    int u = 0;
    for (char c : s) {
        int idx = c - 'a';
        if (!trie[u][idx]) {
            trie[u][idx] = ++node_cnt;
        }
        u = trie[u][idx];
    }
    is_end[u] = true; // Mark the end of a valid initial string
}

// DFS to find if there is a string with exactly 1 difference
bool dfs(int u, const string& s, int pos, bool changed) {
    // Base case: Reached the end of the query string
    if (pos == s.length()) {
        // Must end at a valid string and have exactly 1 change
        return changed && is_end[u]; 
    }
    
    int char_idx = s[pos] - 'a';
    
    // 1. Try an exact match (no character changed here)
    if (trie[u][char_idx]) {
        if (dfs(trie[u][char_idx], s, pos + 1, changed)) {
            return true;
        }
    }
    
    // 2. Try changing the character (only if we haven't changed one yet)
    if (!changed) {
        for (int i = 0; i < 3; ++i) {
            // Pick a different character path that actually exists
            if (i != char_idx && trie[u][i]) {
                if (dfs(trie[u][i], s, pos + 1, true)) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        insert(s);
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> s;
        if (dfs(0, s, 0, false)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}