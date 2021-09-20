/**
 * Question:
 * Given an integer array nums sorted in non-decreasing order, 
 * return an array of the squares of each number sorted in non-decreasing order.
 */ 
 
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> squares(nums.size());
        int l=0, r=nums.size()-1;
        int k=nums.size()-1;
        while(l <= r) {
            if (abs(nums[l]) < abs(nums[r])) {
                squares[k--] = nums[r]*nums[r];
                r--;
            } else {
                squares[k--] = nums[l]*nums[l];
                l++;
            }
        }
        return squares;
    }
};
