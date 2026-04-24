#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int t;
    if (!(cin >> t)) return;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        vector<int> count(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            // Only count elements that are <= n
            if (a[i] <= n) {
                count[a[i]]++;
            }
        }
        
        int ans = 0;
        
        // Iterate through all possible subarrays
        for (int l = 0; l < n; l++) {
            int current_sum = a[l];
            for (int r = l + 1; r < n; r++) {
                current_sum += a[r];
                
                // If sum exceeds n, it can't match any valid element
                if (current_sum > n) {
                    break;
                }
                
                // If this sum corresponds to elements in our array
                if (count[current_sum] > 0) {
                    ans += count[current_sum];
                    count[current_sum] = 0; // Mark as counted
                }
            }
        }
        
        cout << ans << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}