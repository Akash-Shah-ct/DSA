/*
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
 * such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * Notice that the solution set must not contain duplicate triplets.
 *
 *
 *
 * Example 1:

 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation: 
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not matter.
 * Example 2:
 *
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 * Example 3:
 *
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 */


/*
 * The key point to learn here, is that if i have a 3sum problem, i can solve it using 
 * two sum + for each number approach.
 * For that we would need to sort the array.
 * Lets say we get the array as -4, -1, -1, 0, 1, 2.
 * Now for each index [i], do two sum method using two pointer method and find out the three numbers if possible.
 * One thing to note here for optimisation is that if your [i] is already non-zero, that means we do not need to process
 * as numbers ahead of [i] would be positive only, and since they are sorted, they would not be summing to 0.
 * Secondly dont forget to consider there could be multiple answers one two pass array.
 * for example for array -1, -1, 0, 1, 2
 * i = 0 ie nums[i] = -1.
 * two pointer will run on -1, 0, 1, 2. 
 * now, -1 +  -1 + 2 == 0 but if we break here, we woud not get another scenario ie -1 + 0 + 1 == 0.
 * This needs to be handled. 
 * also another thing that needs to be handled is what if there are duplicate in the above array. like -1, -1, -1, 0, 1, 2 ,2
 * such scenario also needs to be handled.
 *
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0 ; i < nums.size() - 2; i++) {
            
            if (nums[i] > 0) break;                                                   /* Optimisation: what if the starting number of sorted list is positive. All positive Numbers cannot add to 0. */
            if (i > 0 && nums[i] == nums[i - 1]) continue;                            /* Initial number duplication solved */
            int start = i + 1;
            int end = nums.size() - 1;
            if (start == end) continue;
            int sum = nums[start] + nums[end] + nums[i];
            while (start < end) {
                
                if ((nums[start] + nums[end] + nums[i]) == 0) {
                    result.push_back({nums[i],nums[start],nums[end]});
                    start++;                                                          /* if in two pointer, we find the result, keep looking for inner results if any */
                    end--;
                    while (start < end && nums[start] == nums[start - 1]) start++;    /* Two pointer number duplication handled */
                } else if ((nums[start] + nums[end] + nums[i]) > 0) {
                    end--;
                } else {
                    start++;
                }
            }
        }

        return result;
     }
};
















