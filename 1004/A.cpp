#include <bits/stdc++.h>

using namespace std;


void solve() {
  int x, y;
  cin >> x >> y;

  if (x + 1 == y) {
    cout << "YES\n";
    return;
  }

  if (x - y + 1 > 0 && (x - y + 1) % 9 == 0) {
    cout << "YES\n";
    return;
  }

  cout << "NO\n";
}

int main() {

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}