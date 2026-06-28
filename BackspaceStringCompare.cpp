/*
844. Backspace String Compare
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 

Follow up: Can you solve it in O(n) time and O(1) space?

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int getNextValidCharacter(string& s, int index){
        int backSpaceCount = 0;
        while(index >= 0)
        {
            if(s[index] == '#') backSpaceCount++;
            else if(backSpaceCount > 0) backSpaceCount--;
            else break;
            index--;
        }
        return index;
    }
    bool backspaceCompare(string s, string t) {
        int first = s.length() -1, second = t.length() - 1;
        while( first >= 0 || second >= 0){
            first = getNextValidCharacter(s, first);
            second = getNextValidCharacter(t, second);

            if( first < 0 && second < 0) return true;
            if(first < 0 || second < 0) return false;
            if( s[first] != t[second]) return false;
            first--;
            second--;
        }
        return true;
    }
};
