/*
2337. Move Pieces to Obtain a String
Hint
You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:

The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space directly to its right.
The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.
Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. Otherwise, return false.

 

Example 1:
Input: start = "_L__R__R_", target = "L______RR"
Output: true
Explanation: We can obtain the string target from start by doing the following moves:
- Move the first piece one step to the left, start becomes equal to "L___R__R_".
- Move the last piece one step to the right, start becomes equal to "L___R___R".
- Move the second piece three steps to the right, start becomes equal to "L______RR".
Since it is possible to get the string target from start, we return true.

Example 2:
Input: start = "R_L_", target = "__LR"
Output: false
Explanation: The 'R' piece in the string start can move one step to the right to obtain "_RL_".
After that, no pieces can move anymore, so it is impossible to obtain the string target from start.
Example 3:

Input: start = "_R", target = "R_"
Output: false
Explanation: The piece in the string start can move only to the right, so it is impossible to obtain the string target from start.
 

Constraints:

n == start.length == target.length
1 <= n <= 105
start and target consist of the characters 'L', 'R', and '_'.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void skipBlankChars(string& st, int& length, int&  start){
        while(start < length && st[start] == '_') start++;
    }
    bool canChange(string start, string target) {
        int index = -1, move1 = 0, move2 = 0, st_length = start.length();
        while(move1 < st_length){
            skipBlankChars(start, st_length, move1);
            skipBlankChars(target, st_length, move2);
            if(move1 == st_length && move2 == st_length) return true;
            if(start[move1] != target[move2]) return false;

            if(start[move1] == 'L' && (move2 <= index || move2 > move1)) return false;
            else if(start[move1] == 'R' && move1 > move2) return false;

            index = move2;
            move1++;
            move2++;
        }
        skipBlankChars(start, st_length, move1);
        skipBlankChars(target, st_length, move2);
        return move1 == st_length && move2 == st_length;
    }
};
