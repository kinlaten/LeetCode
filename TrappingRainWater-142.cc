class Solution {
public:
  // water trapped by left and right. Which side bound is lower will be
  // processed until it is higher than other side bound.
  int trap(vector<int> &h) {
    int low = 0;
    int totalWater = 0;
    int n = h.size();
    int left = 0, right = n - 1;
    int maxLeft = 0, maxRight = 0;

    while (left < right) {
      // process shorter pile first because it limits the water level
      if (h[left] < h[right]) {
        if (h[left] >= maxLeft) {
          maxLeft = h[left];
        } else {
          totalWater += maxLeft - h[left];
        }
        left++;
      } else {
        if (h[right] >= maxRight) {
          maxRight = h[right];
        } else {
          totalWater += maxRight - h[right];
        }
        right--;
      }
    }
    return totalWater;
  }
};
