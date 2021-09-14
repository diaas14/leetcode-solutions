/**
 * Question:
 * Given an array of non-negative integers arr, 
 * you are initially positioned at start index of the array. 
 * When you are at index i, you can jump to i + arr[i] or i - arr[i], 
 * check if you can reach to any index with value 0.
 * Notice that you can not jump outside of the array at any time.
 */

class Solution {
public:
    
    bool canReachBfs(vector<int>& arr, int start) {
        queue<int> bfs;
        vector<int> visited(arr.size(), 0);
        visited[start]=1;
        
        bfs.push(start);
        while (!bfs.empty()) {
            int pos = bfs.front();
            if (arr[pos] == 0) return true;
            bfs.pop();
            if (pos + arr[pos] < arr.size() &&!visited[pos + arr[pos]]) {
                bfs.push(pos + arr[pos]);
                visited[pos + arr[pos]] = 1;
            }
            if (pos - arr[pos] >= 0  && !visited[pos - arr[pos]]) {
                bfs.push(pos - arr[pos]);
                visited[pos - arr[pos]] = 1;
            }
                
        }
        return false;
    }
    
    bool canReachRecDfs(vector<int>& arr, vector<int>& visited, int pos) {
        if (pos < 0 || pos >= arr.size() || visited[pos]) 
            return false;
        if (arr[pos] == 0)
            return true;
        
        visited[pos] = 1;
        return (canReachRec(arr, visited, pos+arr[pos]) || canReachRec(arr, visited, pos-arr[pos]));
    }
    
    bool canReachDfs(vector<int>& arr, int start) {
        vector<int> visited(arr.size(), 0);
        return canReachRec(arr, visited, start);
    }
};
