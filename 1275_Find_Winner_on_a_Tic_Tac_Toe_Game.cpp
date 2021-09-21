/**
 * Question:
 * Tic-tac-toe is played by two players A and B on a 3 x 3 grid.
 */
 
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        bool odd_turn = true;
        int rows[3]{0}, cols[3]{0};
        int diag=0, anti_diag=0, player;
        for (auto move: moves) {
            player = (odd_turn) ? 1 : -1;
            rows[move[0]] += player;
            cols[move[1]] += player;
            if (move[0] == move[1])
                diag += player;
            if (move[0] + move[1] == 2)
                anti_diag += player;
            if (abs(rows[move[0]]) == 3 || abs(cols[move[1]]) == 3 || abs(diag) == 3 || abs(anti_diag) == 3)
                return (player == 1)? "A" : "B";
            odd_turn = !(odd_turn);
        }
        return (moves.size() == 9)? "Draw": "Pending";
    }
};
