class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int n = numbers.size();

    // Outer loop iterates through each element (O(N))
    for (int i = 0; i < n; ++i) {
      // Calculate the required complement value
      int complement = target - numbers[i];

      // Binary Search Setup:
      // We search for the complement in the sub-array *after* the current index
      // i. Start the search range at i + 1 to ensure index1 < index2 and avoid
      // using the same element twice.

      int low = i + 1;
      int high = n - 1;

      // Binary search in the remaining sub-array (O(log N))
      while (low <= high) {
        int mid = low + (high - low) / 2; // Avoids overflow

        if (numbers[mid] == complement) {
          // Found the match!
          // Return 1-based indices (i + 1 and mid + 1)
          return {i + 1, mid + 1};
        } else if (numbers[mid] < complement) {
          // Complement is larger, move low pointer to the right
          low = mid + 1;
        } else {
          // Complement is smaller, move high pointer to the left
          high = mid - 1;
        }
      }
    }

    // According to the problem statement, a solution is guaranteed.
    // If a return is necessary for compile safety, return an empty vector.
    return {};
  }
};
