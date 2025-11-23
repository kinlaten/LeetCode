using System;
using System.Text.RegularExpressions;

public class Solution
{
    public bool IsPalindrome(string s)
    {
        string cleanS = Regex.Replace(s, @"[^a-zA-Z0-9]", string.Empty).ToLower();
        for (int i = 0, j = cleanS.Length - 1; i < j; i++, j--)
        {
            if (cleanS[i] != cleanS[j])
                return false;
        }
        return true;
    }
}

//C++ version
#include <string>
#include <algorithm> // Required for std::tolower and std::isalnum

class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // 1. Move left pointer past non-alphanumeric characters
            // std::isalnum checks for letters or digits
            while (left < right && !std::isalnum(s[left])) {
                left++;
            }

            // 2. Move right pointer past non-alphanumeric characters
            while (left < right && !std::isalnum(s[right])) {
                right--;
            }

            // After skipping, if the pointers haven't crossed:
            if (left < right) {
                // 3. Compare the characters, converting both to lowercase
                if (std::tolower(s[left]) != std::tolower(s[right])) {
                    return false; // Found a non-matching pair
                }
                
                // 4. Move pointers inward
                left++;
                right--;
            }
        }

        return true;
    }
};
