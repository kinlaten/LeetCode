class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    // Sort array
    sort(nums.begin(), nums.end());

    int size = nums.size();
    vector<vector<int>> res;

    for (int i = 0; i < size - 2; i++) {
      // pass the duplicate, except if it is first element
      if (i > 0 &&
          nums[i] == nums[i - 1]) { // avoid do nums[i]== nums[i+1] bc it not
                                    // cover if i is currently at size-3
        continue;
      }

      // indexer
      int left = i + 1, right = size - 1;

      //
      int target = -nums[i];

      while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum < target) {
          left++;
        } else if (sum > target) {
          right--;
        } else {
          res.push_back({nums[i], nums[left], nums[right]});
          left++;
          // right--;

          while (left < right && nums[left] == nums[left - 1])
            left++;
          // while (left < right && nums[right] == nums[right + 1])
          // right--;
        }
      }
    }
    return res;
  }
};
