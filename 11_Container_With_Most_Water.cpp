/**
 * Question:
 * Given n non-negative integers a1, a2, ..., an , 
 * where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
 * Find two lines, which, together with the x-axis forms a container, 
 * such that the container contains the most water.
 * Notice that you may not slant the container.
 */


class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = -1;
        // starting from the left and right corner
        // i.e., max width
        int l=0, r=height.size()-1;
        int h{};
        while (l<r) {
            h = min(height[l], height[r]);
            // calculate max area
            water = max(water, h * (r - l));
            // move left pointer until we encounter a height > h
            while (l<r && height[l]<=h) l++;
            // move right pointer until we encounter a height > h
            while (r>l && height[r]<=h) r--;
        }
        return water;
    }
};
