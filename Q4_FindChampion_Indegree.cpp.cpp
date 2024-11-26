#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find the champion (node with 0 indegree and no competition)
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0); // Array to store the indegree of each node

        // Update indegree for each node based on the edges
        for (auto edge : edges) {
            indegree[edge[1]]++; // Increment indegree for the destination node
        }

        int champ = -1; // Variable to store the potential champion
        int champCount = 0; // Counter to track nodes with 0 indegree

        // Iterate through all nodes to identify champions
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) { // Node with 0 indegree
                champCount++; // Increment the count of nodes with 0 indegree
                champ = i;    // Update the champion to the current node
            }
        }

        // If more than one node has 0 indegree, no unique champion exists
        if (champCount > 1) {
            return -1;
        } else {
            return champ; // Return the unique champion
        }
    }
};

int main() {
    Solution solution; // Create an instance of the Solution class

    int n = 5; // Number of nodes
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {3, 4},
    }; // List of directed edges in the graph

    int champion = solution.findChampion(n, edges); // Call the findChampion function

    // Output the result
    if (champion == -1) {
        cout << "There is no unique champion in the graph." << endl;
    } else {
        cout << "The champion is node: " << champion << endl;
    }

    return 0;
}
