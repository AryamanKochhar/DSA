#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to solve the sliding puzzle
    int slidingPuzzle(vector<vector<int>>& board) {
        // Direction map for possible moves of the blank space ('0') in a 1D representation of the 2x3 board
        // Each index represents the position of '0' and the vector contains the indices it can move to
        vector<vector<int>> directions = {
            {1, 3},    // From position 0, '0' can move to positions 1 and 3
            {0, 2, 4}, // From position 1, '0' can move to positions 0, 2, and 4
            {1, 5},    // From position 2, '0' can move to positions 1 and 5
            {0, 4},    // From position 3, '0' can move to positions 0 and 4
            {1, 3, 5}, // From position 4, '0' can move to positions 1, 3, and 5
            {2, 4}     // From position 5, '0' can move to positions 2 and 4
        };

        string target = "123450"; // Target state of the board (solved state)
        string startState;        // Current state of the board as a string

        // Convert the 2D board into a 1D string representation
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                startState += to_string(board[i][j]);
            }
        }

        unordered_set<string> visited; // To track visited states
        queue<string> queue;           // Queue for BFS
        queue.push(startState);        // Start BFS with the initial state
        visited.insert(startState);    // Mark the initial state as visited

        int moves = 0; // To count the number of moves taken

        // Perform BFS
        while (!queue.empty()) {
            int size = queue.size(); // Number of states at the current BFS level
            while (size-- > 0) {
                string currentState = queue.front(); // Get the current state
                queue.pop();

                // Check if the current state is the solved state
                if (currentState == target) {
                    return moves; // Return the number of moves taken
                }

                // Find the position of '0' (blank space) in the current state
                int zeroPos = currentState.find('0');

                // Explore all possible moves of '0'
                for (int newPos : directions[zeroPos]) {
                    string nextState = currentState; // Create a new state by swapping
                    swap(nextState[zeroPos], nextState[newPos]); // Swap '0' with the target position

                    // If the new state has already been visited, skip it
                    if (visited.count(nextState)) continue;

                    // Mark the new state as visited and add it to the queue
                    visited.insert(nextState);
                    queue.push(nextState);
                }
            }
            moves++; // Increment the number of moves after processing one BFS level
        }
        return -1; // If the target state is not reachable, return -1
    }
};
