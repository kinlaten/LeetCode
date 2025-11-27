class Solution {
public:
  bool canFinish(const vector<int> &piles, int h, int k) {
    long hours = 0;
    for (int pile : piles) {
      hours += pile / k;
      if (pile % k != 0)
        hours++;
      if (hours > h)
        return false;
    }
    return hours <= h;
  }
  int minEatingSpeed(vector<int> &piles, int h) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    int res = right; // init iterator as max speed monkey can eat

    // binary search
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (canFinish(piles, h, mid)) {
        res = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return res;
  }
};
