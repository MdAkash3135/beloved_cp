#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPaintAllCells(const vector<long long>& a, long long k) {
    long long last_painted = a[0];
    int painted_count = 1;  // We've painted the first cell in `a`

    for (int i = 1; i < a.size(); i++) {
        if (a[i] - last_painted > 2 * k) {
            // We need a new start of a pair if the distance is more than 2 * k
            last_painted = a[i];
            painted_count++;
            if (painted_count > 2) {  // We can paint at most two different ranges
                return false;
            }
        }
    }
    return true;
}

long long minKToPaintAllCells(const vector<long long>& a) {
    long long left = 1, right = a.back() - a[0];
    long long result = right;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (canPaintAllCells(a, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    vector<long long> results;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        results.push_back(minKToPaintAllCells(a));
    }

    for (const auto& result : results) {
        cout << result << "\n";
    }

    return 0;
}
