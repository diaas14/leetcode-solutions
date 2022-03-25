/**
 * You are given two integers, x and y, which represent your current location on a Cartesian grid: (x, y). 
 * You are also given an array points where each points[i] = [ai, bi] represents that a point exists at (ai, bi). 
 * A point is valid if it shares the same x-coordinate or the same y-coordinate as your location.
 * Return the index (0-indexed) of the valid point with the smallest Manhattan distance from your current location. 
 * If there are multiple, return the valid point with the smallest index. 
 * If there are no valid points, return -1.
 * The Manhattan distance between two points (x1, y1) and (x2, y2) is abs(x1 - x2) + abs(y1 - y2).
 */
 
class Solution {
    public int nearestValidPoint(int x, int y, int[][] points) {
        Integer minDistPos = null;
        int dist = 0;
        for (int i=0; i<points.length; i++) {
            if (points[i][0] - x == 0 || points[i][1] - y == 0) {
                dist = Math.abs(points[i][0] - x) + Math.abs(points[i][1] - y);
                if (minDistPos == null) 
                    minDistPos = i;
                else if (dist < Math.abs(points[minDistPos][0] - x) + Math.abs(points[minDistPos][1] - y)) minDistPos = i;
            }
        }
        return minDistPos == null ? -1 : minDistPos;
    }
}
