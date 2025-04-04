/*
 * You are given an array people where people[i] is the weight of the ith person, 
 * and an infinite number of boats where each boat can carry a maximum weight of limit. 
 * Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
 * Return the minimum number of boats to carry every given person.
 *
 * Example 1:
 *
 * Input: people = [1,2], limit = 3
 * Output: 1
 * Explanation: 1 boat (1, 2)
 * Example 2:
 *
 * Input: people = [3,2,2,1], limit = 3
 * Output: 3
 * Explanation: 3 boats (1, 2), (2) and (3)
 * Example 3:
 *
 * Input: people = [3,5,3,4], limit = 5
 * Output: 4
 * Explanation: 4 boats (3), (3), (4), (5)
 */


class Solution {
public:
     /* This is two pointer solution without limit with sorting 
      * This is a simple approach. Sort the array and find out which one pairs.
      * A more optimised approach would be to eliminate the sorting altogether, 
      * which would be explored in furture commits
      */
    int numRescueBoatsUsingTwoPointerSorted(vector<int>& people, int limit) {
        int minBoats = 0;
        sort(people.begin(), people.end());
        int start = 0;
        int sum = 0;
        int end = people.size() - 1;
        while (start <= end) {
            sum = people[start] + people[end];
            if (sum <= limit){
                minBoats++;
                end--;
                start++;
            } else {
                minBoats++;
                end--;
            }
        }
        return minBoats;
    } 
};
