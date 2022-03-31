class Solution {
    
    public boolean isPowerOfThree(int n) {
        // if (n == 1) return true;
        // if (n < 1) return false;
        // return n % 3 == 0 ? isPowerOfThree(n/3) : false;
        
        return (Integer.toString(n, 3).matches("^10*"));
    }
}
