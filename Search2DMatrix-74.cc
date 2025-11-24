class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    for (int i = 0; i < matrix.size(); i++) {
      const vector<int> &nums = matrix[i];
      int n = nums.size();
      int left = 0, right = n - 1;
      while (left <= right) { // need check even = operation because need
                              // to cover 1 element array
        int mid = left + (right - left) / 2;

        if (nums[mid] < target) {
          left = mid + 1;
        } else if (nums[mid] > target) {
          right = mid - 1;
        } else {
          return true;
        }
      };
    }
    return false;
  }
};
