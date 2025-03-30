/*
This is the solution to LeetCode problem 3: Longest Substring Without Repeating Characters.
The problem is to find the length of the longest substring without repeating characters in a given string.
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
 */

 /*
 Approach used - Sliding Window Technique
    The idea is to use a sliding window to keep track of the current substring without repeating characters.
    We maintain a hash map to store the last index of each character.
    We expand the right end of the window by moving the right pointer and check if the character is already in the hash map.
    If it is, we move the left pointer to the right of the last occurrence of that character.
    We update the maximum length of the substring at each step.
    The time complexity of this approach is O(n), where n is the length of the string.
    The space complexity is O(min(n, m)), where n is the length of the string and m is the size of the character set.
 */


class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex; 
        int maxLength = 0;
        int left = 0; 
    
        for (int right = 0; right < s.length(); right++) {
            if (charIndex.find(s[right]) != charIndex.end() && charIndex[s[right]] >= left) {
                left = charIndex[s[right]] + 1; 
            }
    
            maxLength = max(maxLength, right - left + 1);
            charIndex[s[right]] = right; 
        }
        return maxLength; 
        }
    };