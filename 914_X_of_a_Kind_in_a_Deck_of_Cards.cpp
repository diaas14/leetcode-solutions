/** 
 * Question:
 * In a deck of cards, each card has an integer written on it.
 * Return true if and only if you can choose X >= 2 such that 
 * it is possible to split the entire deck into 1 or more groups of cards, where:
 * Each group has exactly X cards.
 * All the cards in each group have the same integer.
 */

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;
        for (auto card: deck)
            freq[card]++;
        
        int X = 0;
        for (auto p: freq)
            if ((X =__gcd(X, p.second)) < 2) return false;
        return true;
    }
};
