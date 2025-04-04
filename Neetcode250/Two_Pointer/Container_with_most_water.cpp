/*
 * You are given an integer array height of length n. 
 * There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
 * Find two lines that together with the x-axis form a container, such that the container contains the most water.
 * Return the maximum amount of water a container can store.
 * Notice that you may not slant the container.
 *
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
 * In this case, the max area of water (blue section) the container can contain is 49.
 */

class Solution {
public:

    /*
     * The idea is that we should itterate between all the 
     * heights and then calculate the maximum area.
     * Time complexity would be O(n^2)
     */
    int maxAreaWithBruteForce(vector<int>& height) {
        int maxAreaVal = 0;

        int start = 0; 
        int end = height.size() - 1;

        for (int i = end ; i > 0; i--) {
            for (int j = 0 ; j < i; j++) {
                int area = min(height[i],height[j])*(i-j);
                if (maxAreaVal < area) maxAreaVal = area;
            }
        }

        return maxAreaVal;
        
    }


    /*
     * Consider we start at 0 and end.
     * then calculate the area.
     * Now for next steps, go the start++ or end-- according to which is greater.
     */
    int maxAreaUsingTwoPointer(vector<int>& height) {
        int mArea = 0;
        int start = 0;
        int end = height.size() - 1;
        while (start < end) {
            int area = min(height[start],height[end])*(end-start);
            if (area > mArea) mArea = area;
            if (height[start] >= height[end]) end--;
            else start++;
        }


        return mArea;
    }
};
