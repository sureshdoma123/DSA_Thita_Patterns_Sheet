/*
647. Palindromic Substrings
Hint
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.

Time Complexity: O(n2)
Space Complexity: O(1)
*/

class Solution {
public:
    int countPalindromicSubStrings(string& s, int left, int right)
    {
        int count = 0;
        while( left >= 0 && right <= s.length() && s[left] == s[right]){
            left--;
            right++;
            count++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int result = 0;
        for(int centre = 0; centre < s.length(); centre++)
        {
            result += countPalindromicSubStrings(s, centre, centre) + countPalindromicSubStrings(s, centre, centre + 1);
        }
        return result;
    }
};
