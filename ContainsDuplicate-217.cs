/*
Given an integer array nums, return true if any value appears at least twice in
the array, and return false if every element is distinct.
*/

// Dictionary: hashmap
public class Solution {
  public bool ContainsDuplicate(int[] nums) {
    Dictionary<int, bool> mapper = new Dictionary<int, bool>();
    // We can use HashSet<int> instead but it is slower than Dictionary in this
    // case https://theburningmonk.com/2011/03/hashset-vs-list-vs-dictionary/
    foreach (var i in nums) {
      if (mapper.ContainsKey(i))
        return true;
      mapper.Add(i, true);
    }
    return false;
  }
}
