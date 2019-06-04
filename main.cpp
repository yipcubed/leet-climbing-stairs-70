#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
      static map<int, int> known;
      if (known.count(n))
        return known[n];
      if (n == 0)
        return 0;
      else if (n == 1)
        return 1;
      else if (n == 2)
        return 2;
      else {
        // n > 2
        int steps1 = climbStairs(n - 1);
        known[n - 1] = steps1;
        int steps2 = climbStairs(n - 2);
        known[n - 2] = steps2;
        return steps1 + steps2;
      }  
    }
};


int main() {
  Solution S;

  // 1. 1 step + 1 step + 1 step
  // 2. 1 step + 2 steps
  // 3. 2 steps + 1 step
  cout << "3? " << S.climbStairs(3) << endl;

  // 1. 1 + 1 + 1 + 1
  // 2. 1 + 1 + 2
  // 3. 1 + 2 + 1
  // 4. 2 + 1 + 1
  // 5 2 + 2
  cout << "5? " << S.climbStairs(4) << endl;

  // 1. 1 + 1 + 1 + 1 + 1
  // 2. 1 + 1 + 1 + 2
  // 3. 1 + 1 + 2 + 1
  // 4. 1 + 2 + 1 + 1
  // 5. 2 + 1 + 1 + 1
  // 6. 1 + 2 + 2
  // 7. 2 + 1 + 2
  // 8. 2 + 2 + 1
  cout << "8? " << S.climbStairs(5) << endl;

  cout << "1134903170? " << S.climbStairs(44) << endl;
  cout << "Done" << endl;

  return 0;
}