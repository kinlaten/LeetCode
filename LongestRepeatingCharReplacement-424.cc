// check possible freq for every char manually
class Solution {
public:
  int characterReplacement(string s, int k) {
    int ans = 0;
    int n = s.length();

    for (char c = 'A'; c <= 'Z'; c++) {
      int left = 0, right = 0, replaced = 0;
      while (right < n) {
        if (s[right] == c) {
          right++;
        } else if (replaced < k) {
          right++;
          replaced++;
        } else if (s[left] == c) {
          left++;
        } else {
          left++, replaced--;
        }
        ans = max(ans, right - left);
      }
    }
    return ans;
  }
};

// Use use hashmap
class Solution {
public:
  int characterReplacement(string s, int k) {
    int n = s.length();

    int left = 0, maxFreq = 0, ans = 0;
    unordered_map<char, int> freq;

    // count freq of each alphabet and find most freq char
    for (int right = 0; right < n; right++) {
      freq[s[right]]++;
      maxFreq = max(maxFreq, freq[s[right]]);

      // if number of replacment needed (= window length- maxFreq) > k
      while ((right - left + 1) - maxFreq > k) {
        freq[s[left]]--;
        left++;
      }

      ans = max(ans, right - left + 1);
    }

    return ans;
  }
};

// Use vector 26 alphabets
class Solution {
public:
  int characterReplacement(string s, int k) {
    int n = s.size();
    int l = 0, r = 0, maxlen = 0;
    int maxf = 0;
    vector<int> count(26, 0);

    while (r < n) {
      count[s[r] - 'A']++;
      maxf = max(maxf, count[s[r] - 'A']);

      // If more than k chars need replacement, shrink window
      if ((r - l + 1) - maxf > k) {
        count[s[l] - 'A']--;
        l++;
      }

      maxlen = max(maxlen, r - l + 1);
      r++;
    }
    return maxlen;
  }
};
