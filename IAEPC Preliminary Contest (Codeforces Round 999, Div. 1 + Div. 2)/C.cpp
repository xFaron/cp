#include <bits/stdc++.h>

using namespace std;

int isLiar[static_cast<int>(2e5 + 1)];
int sum_[static_cast<int>(2e5 + 1)] = {0};
int data_[static_cast<int>(2e5 + 1)];

void solve() {
    int n;
    cin >> n;

    int count = 0;
    for (int i = 1; i <= n; i++) {
        cin >> data_[i];
        isLiar[i] = 0;
    }
    data_[n+1] = -1;

    int currIndex = 1;
    bool backing = false;
    while (currIndex) {
        // cout << "CurrIndex : " << currIndex << endl;
        // for (int i = 0; i <= n + 1; i++) {
        //     cout << i << " : " << isLiar[i] << " | " << sum_[i] << " | " << data_[i] << endl;
        // }
        // cout << endl;


        if (data_[currIndex] == -1) {
            count++;
            backing = true;
            currIndex--;
        }

        if (backing) {
            if (isLiar[currIndex] || !isLiar[currIndex] && isLiar[currIndex - 1]) {
                isLiar[currIndex] = 0;
                currIndex--;
            } else {
                isLiar[currIndex] = !isLiar[currIndex];
                sum_[currIndex] = sum_[currIndex - 1] + isLiar[currIndex];
                currIndex++;
                backing = false;
            }
            continue;
        } else {
            if (sum_[currIndex - 1] == data_[currIndex]) {
                sum_[currIndex] = sum_[currIndex - 1] + isLiar[currIndex];
                currIndex++;
                continue;
            } else {
                if (isLiar[currIndex - 1]) {
                    currIndex--;
                    backing = true;
                } else {
                    isLiar[currIndex] = 1;
                    sum_[currIndex] = sum_[currIndex - 1] + isLiar[currIndex];
                    currIndex++;
                }
                continue;
            }
        }
    }

    cout << count << endl;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}