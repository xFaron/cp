#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        unordered_map<int, int> frequency;
        vector<int> possible_legs;

        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;

            frequency[k]++;
            if (frequency[k] == 2 && k) {
                possible_legs.push_back(k);
            }
        }

        if (possible_legs.size() > 1) {
            // Output the first two pairs of possible legs
            cout << possible_legs[0] << " " << possible_legs[0] << " " << possible_legs[1] << " " << possible_legs[1] << endl;
            continue;
        } else if (possible_legs.empty()) {
            // No valid possible legs
            cout << -1 << endl;
            continue;
        } else {
            // Only one valid pair of possible legs
            int special_leg = possible_legs[0];
            frequency[special_leg] -= 2;

            // Prepare sorted sides excluding the special leg if frequency drops below 2
            vector<int> valid_sides;
            for (pair<int, int> side : frequency) {
                if (side.second > 0) {
                    valid_sides.push_back(side.first);
                }
            }

            sort(valid_sides.begin(), valid_sides.end());

            bool found = false;
            for (size_t i = 0; i < valid_sides.size() - 1; i++) {
                if (valid_sides[i + 1] - valid_sides[i] < 2 * special_leg) {
                    cout << valid_sides[i] << " " << valid_sides[i + 1] << " " << special_leg << " " << special_leg << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}
