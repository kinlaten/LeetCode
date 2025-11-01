/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
*/

// Using 64 bit integer
class Solution
{
public:
    int reverse(int x)
    {
        // Use modulo of 10 to get last digit, add into new int
        long r = 0; // 64 bit
        while (x)
        {
            r = r * 10 + x % 10; // we *10 to new int along with /10 to input
            x /= 10;
        }

        // INT_MIN        = -2147483648 (32bit signed)
        // INT_MAX        = +2147483647 (32bit signed)
        if (r > INT_MAX || r < INT_MIN)
        {
            return 0;
        }
        return int(r); // if r in range of 32 bit
    }
};

// Using 32 bit integer
class Solution
{
public:
    int reverse(int x)
    {
        int r = 0;
        while (x)
        {
            if (r > INT_MAX / 10 || r < INT_MIN / 10)
            {
                return 0;
            }
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }
};