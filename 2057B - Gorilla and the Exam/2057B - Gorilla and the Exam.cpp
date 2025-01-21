#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }

        std::sort(arr.begin(), arr.end());
        std::vector<int> frequencies = {1};

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] != arr[i+1]) {
                frequencies.emplace_back(1);
            } else {
                frequencies.back()++;
            }
        }

        std::sort(frequencies.begin(), frequencies.end()); // Ascending
        int distinctCount = frequencies.size();

        for (int f : frequencies) {
            if (f <= k) {
                k -= f;
                distinctCount--;
            } else {
                break;
            }
        }

        std::cout << (distinctCount ? distinctCount : 1) << "\n";
    }

}