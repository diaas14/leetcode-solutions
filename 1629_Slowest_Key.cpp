/**
 * Question:
 * ...
 * Return the key of the keypress that had the longest duration. 
 * If there are multiple such keypresses, 
 * return the lexicographically largest key of the keypresses.
 */


class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char key = keysPressed[0];
        int longest = releaseTimes[0], duration{};
        for(int i=1; i<keysPressed.size(); i++) {
            if ((duration = releaseTimes[i]-releaseTimes[i-1]) > longest){
                longest = duration;
                key = keysPressed[i];
            } else if (duration == longest) {
                if (keysPressed[i] > key) key = keysPressed[i];
            }
        }
        return key;
    }
};
