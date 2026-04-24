#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate minimum days for a specific target height
long long get_days(long long T, const vector<long long>& h) {
    long long cnt1 = 0;
    long long S = 0;
    
    for (long long val : h) {
        long long d = T - val;
        cnt1 += d % 2;
        S += d;
    }

    // Binary search for the minimum days
    long long low = 0, high = 1e16, res = 1e16;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long O = (mid + 1) / 2; // Number of available odd days
        long long E = mid / 2;       // Number of available even days
        
        // Check if we can satisfy parity and total sum requirements
        if (O >= cnt1 && O + 2 * E >= S) {
            res = mid;
            high = mid - 1; // Try to find a smaller valid D
        } else {
            low = mid + 1;
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> h(n);
    long long M = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        if (h[i] > M) {
            M = h[i];
        }
    }

    // The optimal target is always either the max element or max element + 1
    long long ans1 = get_days(M, h);
    long long ans2 = get_days(M + 1, h);
    
    cout << min(ans1, ans2) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}