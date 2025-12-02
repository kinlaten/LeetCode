// Sliding window with 2 pointers
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int windowS = 0;
    int left = 0;
    unordered_set<char> charSet;

    for (int right = 0; right < n; right++) {
      // if char at right is same as at left, remove the left one out of window
      while (charSet.count(s[right])) {
        charSet.erase(s[left]);
        left++;
      }

      charSet.insert(s[right]);
      windowS = max(windowS, right - left + 1);
    }
    return windowS;
  }
};
