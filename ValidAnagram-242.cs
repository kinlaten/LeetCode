/*
 * Given two strings s and t, return true if t is an anagram of s, and false
otherwise.. Example 1:

Input: s = "anagram", t = "nagaram"

Output: true
*/

// Solution: Count each char of s, if that char not in t, false, else minus the
// count of the char. End loop. If elements in dic have values 0: true
public class Solution {
  public bool IsAnagram(string s, string t) {
    if (s.Length != t.Length)
      return false;

    var mapper = new Dictionary<char, int>();
    foreach (var c in s) {
      if (mapper.ContainsKey(c)) {
        mapper[c]++;
      } else {
        mapper.Add(c, 1);
      }
    }
    foreach (var c in t) {
      if (!mapper.ContainsKey(c)) {
        return false;
      }

      mapper[c]--;

      if (mapper[c] < 0)
        return false;
    }

    foreach (var v in mapper.Values) {
      if (v != 0) {
        return false;
      
    }
    return true;
  }
}
