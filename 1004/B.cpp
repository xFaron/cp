#include <bits/stdc++.h>

using namespace std;

int bag1[1001], bag2[1001];

void solve() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    bag1[i] = bag2[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;

    bag1[temp] += 1;
  }

  for (int i = n; i > 0; i--) {
    if (bag1[i] != bag2[i]) {
      if (bag1[i] > bag2[i] && (bag1[i] - bag2[i]) % 2 == 0) {
        continue;
      }

      int requirement = 1;
      int j = i;
      while (--j) {
        requirement += 1 - bag2[j];
        //requirement -= 1 - static_cast<int>(bag1[j]);

        bag2[j] += 1 - bag2[j];
        if (bag1[j] >= requirement) {
          bag1[j] -= requirement;
          break;
        }

        if (j == 1) {
          cout << "NO\n";
          return;
        }
      }
    }
  }

  cout << "YES\n";

}

int main() {

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}