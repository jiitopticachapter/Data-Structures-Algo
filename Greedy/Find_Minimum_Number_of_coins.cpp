#include<bits/stdc++.h>
using namespace std;

// approach : 
// here we will subtract the big numbers which we can subtract from given 
// number to find minimum number of coins we need to 
// traverse the coins array from last. 
int main() {
  int V = 49;
  vector < int > ans;
  int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int n = 9;
  for (int i = n - 1; i >= 0; i--) {
    while (V >= coins[i]) {
      V -= coins[i];
      ans.push_back(coins[i]);
    }
  }
  cout<<"The minimum number of coins is "<<ans.size()<<endl;
  cout<<"The coins are "<<endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
// Output:

// The minimum number of coins is 5
// The coins are
// 20 20 5 2 2

// Time Complexity:O(V)

// Space Complexity:O(1)