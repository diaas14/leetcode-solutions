/**
 * Question:
 * Given an integer array arr, return the length of a maximum size turbulent subarray of arr.
 * A subarray is turbulent if the comparison sign flips 
 * between each adjacent pair of elements in the subarray.
 */
 
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int max_size=1, temp_max=1;
        bool pos=true;
        
        for (int i=1; i<arr.size(); i++) {
            if (i==1) pos = !(arr[i] > arr[i-1]);
            if (arr[i] != arr[i-1] && (arr[i] > arr[i-1]) != pos) {
                pos = arr[i] > arr[i-1];
                temp_max++;
            } else {
                max_size = max(max_size, temp_max);
                pos = arr[i] > arr[i-1];
                temp_max = (arr[i] != arr[i-1]) ? 2 : 1;
            }   
        }
        return max(max_size, temp_max);
    }
};
