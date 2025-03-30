/*
    This is the solution to LeetCode problem 8: String to Integer (atoi).
    The problem is to convert a string to an integer, following the rules of the C/C++ function atoi.
    Example 1:
    Input: s = "42"
    Output: 42
    Explanation: The function converts the string "42" to the integer 42.
*/

/*
Approach used -
    The idea is to iterate through the string and ignore leading whitespace characters.
    We then check for an optional sign ('+' or '-') and start converting the digits to an integer.
    We also handle overflow and underflow cases by checking if the result exceeds the limits of a 32-bit signed integer.
    We also check if the string contains any digits before returning the result.
*/

/*
    The time complexity of this approach is O(n), where n is the length of the string.
    The space complexity is O(1) since we are using a constant amount of space.
*/

class Solution {
    public:
        int myAtoi(string s) {
            long final =0;
            int sign=1;
            int i = 0 ;
            bool hasDigit= false;
            while (i < s.length() && s[i] == ' ') {
                i++;
            }
            if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
                if(s[i]=='-') sign = -1;
                i++;
            }
             while (i < s.length() && isdigit(s[i])) {
                if (final > (INT_MAX - (s[i]-'0')) / 10) {
                    return (sign == 1) ? INT_MAX : INT_MIN;
                }
                final = final*10+(s[i]-'0');
                hasDigit = true;
                i++;
            }
            if(hasDigit == false) return 0;
            return (int)(final*sign);
        }
    };