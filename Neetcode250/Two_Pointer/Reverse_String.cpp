/*
 * Write a function that reverses a string. The input string is given as an array of characters s.
 * You must do this by modifying the input array in-place with O(1) extra memory.
 *
 * Example 1:
 * Input: s = ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 *
 * Example 2:
 * Input: s = ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 *
 */


class Solution {
public:
    void reverseString(vector<char>& s) {
        /* Using Two pointer approach. 
         * The idea is to use two pointers at start and end
         * and do the reversal of string.
         * After each itteration, move start pointer forward
         * and end pointer backward until the meet the midpoint of the array.
         */
        int start_index = 0;
        int end_index = s.size() - 1;
        while (start_index < end_index) {
            swap (s[start_index],s[end_index]);
            start_index++;
            end_index--;
        }
    }
};


