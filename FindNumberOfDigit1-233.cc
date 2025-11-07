class Solution
{
public:
    int countDigitOne(int n)
    {
        int res = 0;
        for (long i = 1; i <= n; i *= (long)10)
        {
            int a = n / i;  // Full cycle
            int b = n % i;  // Suffix of current digit
            int x = a % 10; // Current digit

            // Given number 2105= 2000 + 100 + 00 + 5
            // each element is called full cycle, e.g. 2000, 100
            // if currentDigit = 0, we dont count block : currentDigit_+_suffix ; e.g. 05
            // if currentDigit = 1, we count to n; e.g 100 -> 105
            // else; we count the full cycle of the pre-fix digits (2 dont have prefix -> 0; means we count to 1*i, Other wise count to prefix*i)
            if (x == 0)
            {
                res += (a / 10) * i; // count fullcycle part 21 only bc we want exclude 05
            }
            else if (x == 1)
            {
                res += (a / 10) * i + (b + 1); // count fullcycle part 2 + suffix part 05
            }
            else
            {
                res += (a / 10 + 1) * i;
            }
        }
        return res;
    }
};