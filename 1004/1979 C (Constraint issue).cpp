#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int arr[50];

void solve() {
  int n;
  cin >> n;

  double is_valid = 0;
  lli pdt = 1;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;

    arr[i] = k;
    pdt *= (pdt % k == 0) ? 1 : k;
    is_valid += (1.0/k);
  }

  if (is_valid >= 1) {
    cout << "-1\n";
    return;
  }

  lli c = static_cast<int>(n/(pdt * (1 - is_valid))) + 1;
  long double T = c * pdt;

  for (int i = 0; i < n; i++) {
    cout << static_cast<int>(T/arr[i]) + 1 << " ";
  }
  cout << endl;
}

int main() {
  cin.sync_with_stdio(true);
  cout.sync_with_stdio(true);

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}