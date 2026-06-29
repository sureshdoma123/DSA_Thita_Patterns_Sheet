/*
3. Longest Substring Without Repeating Characters
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
        Time Complexity: Brute Force O(n*n)
        if( s == "") return 0;
        int max_count = 1;
        for(int i = 0; i < s.size() - 1; i++){
            string temp = "";
            temp += s[i];
            for(int j = i + 1; j < s.size(); j++)
            {
                auto find_char = find(temp.begin(), temp.end(), s[j]);
                if(find_char == temp.end()){
                    temp += s[j];
                    max_count = max(max_count, j - i + 1);
                }
                else{ break;}
                
            }
            cout << temp << endl;
        }
        return max_count;
        */
        
        // Optimized code O(n)
        unordered_map<char, int> hashMap;
        int left = 0, maxCount = 0;
        for (int right = 0; right < s.size(); right++) {
            if (hashMap.find(s[right]) != hashMap.end() && hashMap[s[right]] >= left) {
                left = hashMap[s[right]] + 1;
            }
            hashMap[s[right]] = right;
            maxCount = max(maxCount, right - left + 1);
        }

        return maxCount;

    }
};
