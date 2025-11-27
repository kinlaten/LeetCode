// Two pointer method O(s1+s2)
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    vector<int> merged;

    if (nums1.empty())
      merged = nums2;
    else if (nums2.empty())
      merged = nums1;
    else {
      // merge 2 array using 2 pointer to check if which element of 2 array
      // smaller
      int *p1 = &nums1[0];
      int *p2 = &nums2[0];
      int *p1_end = nums1.data() + nums1.size();
      int *p2_end = nums2.data() + nums2.size();

      while (p1 != p1_end && p2 != p2_end) {
        if (*p1 <= *p2) {
          merged.push_back(*p1);
          p1++;
        } else {
          merged.push_back(*p2);
          p2++;
        }
      }

      while (p1 != p1_end) {
        merged.push_back(*p1);
        p1++;
      }
      while (p2 != p2_end) {
        merged.push_back(*p2);
        p2++;
      }
    }

    // calculate median
    int size = merged.size();
    if (size == 0)
      return 0;
    if (size % 2 == 1) {
      return (double)merged[size / 2];
    } else {
      int mid1 = merged[size / 2 - 1];
      int mid2 = merged[size / 2];
      return ((double)mid1 + mid2) / 2.0;
    }
  }
};

// Partition method O(log(min(s1, s2)))
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int s1 = nums1.size();
    int s2 = nums2.size();

    // Find mid based on smaller array
    if (s1 > s2)
      return findMedianSortedArrays(nums2, nums1);

    int low = 0, high = s1;

    while (low <= high) {
      int mid1 = (low + high) / 2;
      int mid2 = (s1 + s2 + 1) / 2 - mid1;

      int left1 = mid1 == 0 ? INT_MIN : a[mid1 - 1];
      int right1 = mid1 == s1 ? INT_MAX : a[mid1];

      int left2 = mid2 == 0 ? INT_MIN : a[mid2 - 1];
      int right2 = mid2 == s1 ? INT_MAX : a[mid2];

      // element on left partition should be smaller than right side
      if (left1 <= right2 && left2 <= right1) {
        if ((s1 + s2) % 2 == 0) {
          return (max(left1, left2) + min(right1, right2)) / 2.0;
        } else
          return max(left1, left2);
      } else if (left1 > right2) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return 0;
  }
};
