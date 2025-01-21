#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int count = 0;
        int evenPresent = 0;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;

            if (num % 2) {
                count++;
            } else {
                evenPresent = 1;
            }
        }

        cout << count + (evenPresent ? 1 : -1) << endl;
    }

    return 0;
}