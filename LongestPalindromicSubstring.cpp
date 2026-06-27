/*
5. Longest Palindromic Substring
Hint
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.

Time Complexity: O(n2)
Space Complexity: O(1)
*/

class Solution {
public:
    int get_max_subString(string& s, int left, int right)
    {
        while( left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
    string longestPalindrome(string s) {
        int start = 0, max_len = 1;
        for( int i = 0; i < s.length(); ++i)
        {
            int even_length_centre = get_max_subString(s, i, i);
            int odd_length_centre = get_max_subString(s, i, i + 1);
            int current_len = max(even_length_centre, odd_length_centre);
            if( max_len < current_len){
                max_len = current_len;
                start = i - ( max_len - 1 ) / 2;
            }
        }
        cout << start << " " << max_len << endl;
        return s.substr(start, max_len);
    }
};
