/*
 * Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
 * Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
 *
 * Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
 *
 * The tests are generated such that there is exactly one solution. You may not use the same element twice.
 *
 * Your solution must use only constant extra space.
*/

class Solution {
public:
    /*
     * Since this is sorted, we can start at the 0 and end of the array.
     * then if the sum is greater than target, we need to lower the end
     * conversely, if the sum is lesser than target, we need to increment the start
     * And hence find the sum indexes.
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> returnSum;
        int start = 0;
        int end = numbers.size() - 1;
        while (start < end) {
            if (numbers[start] + numbers[end] == target) {      // if sum is equal break and return the indexes.
                returnSum.push_back(start + 1);
                returnSum.push_back(end + 1);
                break;
            } else if  (numbers[start] + numbers[end] > target) { // if sum is greater then decrement end pointer
                end--;
            } else {                                               // if sum is lesser than increment the start pointer.
                start++;
            }
        }

        return returnSum;
    }
};
