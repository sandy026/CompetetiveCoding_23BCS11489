#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Store events as {coordinate, coverage_change}
    vector<pair<long long, int>> events;
    events.reserve(2 * n); // Preallocate memory for speed
    
    for (int i = 0; i < n; ++i) {
        long long l, r;
        cin >> l >> r;
        events.push_back({l, 1});
        events.push_back({r + 1, -1});
    }

    // Sort events by coordinate
    sort(events.begin(), events.end());

    vector<long long> ans(n + 1, 0);
    long long current_coverage = 0;
    long long prev_x = events[0].first;

    // Process all events
    for (size_t i = 0; i < events.size(); ) {
        long long curr_x = events[i].first;
        
        // Add the number of points with the previous coverage
        ans[current_coverage] += (curr_x - prev_x);
        
        // Process all events happening at this exact coordinate simultaneously
        while (i < events.size() && events[i].first == curr_x) {
            current_coverage += events[i].second;
            i++;
        }
        
        prev_x = curr_x;
    }

    // Output results
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}