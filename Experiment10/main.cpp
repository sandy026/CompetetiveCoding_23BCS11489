#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int a[MAXN];
int prev_k[MAXN];
vector<int> pos[MAXN];
vector<int> tree[4 * MAXN];

// Build the Merge Sort Tree
void build(int node, int start, int end) {
    if (start == end) {
        tree[node].push_back(prev_k[start]);
        return;
    }
    
    int mid = start + (end - start) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    
    // Merge the two sorted child vectors into the parent vector
    merge(tree[2 * node].begin(), tree[2 * node].end(),
          tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
          back_inserter(tree[node]));
}

// Query the tree to count elements strictly less than 'val' in range [l, r]
int query(int node, int start, int end, int l, int r, int val) {
    if (r < start || end < l) {
        return 0; // Out of bounds
    }
    
    // Completely inside the range
    if (l <= start && end <= r) {
        // Find the number of elements strictly less than 'val'
        auto it = lower_bound(tree[node].begin(), tree[node].end(), val);
        return distance(tree[node].begin(), it);
    }
    
    int mid = start + (end - start) / 2;
    return query(2 * node, start, mid, l, r, val) +
           query(2 * node + 1, mid + 1, end, l, r, val);
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
        
        // Find the k-th previous occurrence of the same element
        if (pos[a[i]].size() > k) {
            prev_k[i] = pos[a[i]][pos[a[i]].size() - 1 - k];
        } else {
            prev_k[i] = 0;
        }
    }

    build(1, 1, n);

    int q;
    cin >> q;

    int last = 0;
    while (q--) {
        int x, y;
        cin >> x >> y;

        // Decrypt the query parameters
        int l = ((x + last) % n) + 1;
        int r = ((y + last) % n) + 1;

        if (l > r) {
            swap(l, r);
        }

        // We want to count indices in [l, r] where prev_k[i] < l
        last = query(1, 1, n, l, r, l);
        cout << last << "\n";
    }

    return 0;
}