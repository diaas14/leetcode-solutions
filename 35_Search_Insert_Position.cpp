/**
 * Question: 
 * Given a sorted array of distinct integers and a target value, 
 * return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in order.
 * You must write an algorithm with O(log n) runtime complexity.
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid{}, l{0}, h{(int)nums.size()-1};
        while(l < h) {
            mid=l+(h-l)/2;
            if (nums[mid] == target) 
                return mid;
            if (nums[mid] > target) 
                h=mid-1;
            else l=mid+1;
        }
        return (target<=nums[l]) ? l: l+1;
    }
};
