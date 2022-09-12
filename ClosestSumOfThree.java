/** 
 * 16_3Sum_Closest
 * Given an integer array nums of length n and an integer target
 * find three integers in nums such that the sum is closest to target.
 * Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 */

class ClosestSumOfThree {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int j, k;
        int closestSum=10000, sum;        
        for (int i=0; i<nums.length; i++) {
            if (i!=0 && i < nums.length) 
                if (nums[i] == nums[i-1]) continue;
            j=i+1;
            k=nums.length-1;
            while (j<k) {
                if (nums[j]+nums[k] == target-nums[i])
                    return target;
                sum = nums[i]+nums[j]+nums[k];
                closestSum = (Math.abs(target - sum) < Math.abs(target - closestSum)) ? sum : closestSum;
                if (nums[j]+nums[k] < target-nums[i])
                    j++;
                else k--;
            }
        }
        return closestSum;
    }
}
