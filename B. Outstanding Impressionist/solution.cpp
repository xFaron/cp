#include <iostream>

using namespace std;

// int binSearch(int val, vector<int>& arr) {
//     int l = 0, r = arr.size() - 1;
//     while (l <= r) {
//         int mid = (l+r) / 2;
//         if (arr[mid] > val) {
//             r = mid - 1;
//         } else if (arr[mid] < val) {
//             l = mid + 1;
//         } else {
//             return mid;
//         }
//     }

//     return -1;
// }

const int MAX = 400001;
int l[MAX], r[MAX], cnt[2*MAX] = {0}, sum[2*MAX] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    // The below is fine logic, but is not fast enough and uses lib. The CF logic is faster and no lib -_-
    // while (t--) {
    //     int n;
    //     cin >> n;

    //     vector<int> l(n), r(n);
    //     vector<int> notPossible;
    //     for (int i = 0; i < n; i++) {
    //         cin >> l[i] >> r[i];
    //         if (l[i] == r[i]) {
    //             notPossible.push_back(l[i]);
    //         }
    //     }

    //     sort(notPossible.begin(), notPossible.end());

    //     for (int i = 0; i < n; i++) {
    //         bool valid = false;
    //         for (int val = l[i]; val <= r[i]; val++) {
    //             int index = binSearch(val, notPossible);
    //             if (l[i] == r[i]) {
    //                 if ((index - 1 < 0 || notPossible[index - 1] != val) && (index + 1 >= notPossible.size() || notPossible[index + 1] != val)) {
    //                     valid = true;
    //                     break;
    //                 }
    //             } else if (index == -1) {
    //                 valid = true;
    //                 break;
    //             }
    //         }

    //         cout << valid ? 1 : 0 ;
    //     }

    //     cout << endl;
    // }

    while (t--) {
        int n;
        cin >> n;

        
        for (int i = 1; i <= 2*n; i++) {
            cnt[i] = 0;
            sum[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            cin >> l[i] >> r[i];
            if (l[i] == r[i]) {
                cnt[l[i]]++;
                sum[l[i]] = 1;
            };
        }

        for (int i = 2; i <= 2*n; i++) {
            sum[i] += sum[i-1];
        }

        for (int i = 1; i <= n; i++) {
            cout << (l[i] == r[i] ? cnt[l[i]] <= 1 : ((sum[r[i]] - sum[l[i] - 1] < r[i] - l[i] + 1) ? 1 : 0)); 
        }

        cout << endl;
    }

    return 0;
}
