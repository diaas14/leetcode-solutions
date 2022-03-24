/**
 * You are given an array people where 
 * people[i] is the weight of the ith person, 
 * and an infinite number of boats where each boat can carry a maximum weight of limit. 
 * Each boat carries at most two people at the same time, 
 * provided the sum of the weight of those people is at most limit.
 * Return the minimum number of boats to carry every given person.
 */
 
class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int low = 0, high = people.length - 1;
        int count = 0;
        while (low <= high) {
            count ++;
            if (high >= 1 && people[high] + people[high-1] <= limit) {
                high -= 2;
                continue;
            }
            else if (people[low] + people[high] <= limit)
                low++;
            high--; // case where only 1 person fits in the boat
        }
        return count;
    }
}
