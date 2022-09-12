/**
 * 1029_Two_City_Scheduling.java
 * A company is planning to interview 2n people. 
 * Given the array costs where costs[i] = [aCosti, bCosti], 
 * the cost of flying the ith person to city a is aCosti, 
 * and the cost of flying the ith person to city b is bCosti.
 * Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.
 */
 
class TwoCityScheduling {
    public int twoCitySchedCost(int[][] costs) {
        int totalCost = 0;
        // first go to city A
        // simultaneously count the cost person i couldve saved 
        // if they traveled to city B
        Integer [] savings = new Integer[costs.length];
        for (int i = 0; i < costs.length; i++) {
            totalCost += costs[i][0];
            savings[i] = costs[i][0] - costs[i][1];
        }
        Arrays.sort(savings, Collections.reverseOrder());
        for (int i = 0; i < savings.length/2; i++)
            totalCost -= savings[i];
        return totalCost;
    }
}
