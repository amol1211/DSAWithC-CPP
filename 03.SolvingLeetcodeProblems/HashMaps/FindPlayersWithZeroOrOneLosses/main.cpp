//2225. Find Players With Zero or One Losses

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    // Create a map to store the count of losses for each player
    unordered_map<int, int> lost_map; // key: player number, value: count of losses

    // Loop through the matches to update the loss count for each loser
    for (int i = 0; i < matches.size(); i++) {
        int loser = matches[i][1];
        lost_map[loser]++;
    }

    // Vectors to store players who have not lost and players who lost only once
    vector<int> notLost;
    vector<int> lostOnce;

    // Loop through the matches again to identify winners and losers
    for (int i = 0; i < matches.size(); i++) {
        int winner = matches[i][0];
        int loser = matches[i][1];

        // If the winner is not in the map, add them to notLost and set losses to 2
        if (lost_map.find(winner) == lost_map.end()) {
            notLost.push_back(winner);
            lost_map[winner] = 2;
        }

        // If the loser has lost only once, add them to lostOnce
        if (lost_map[loser] == 1) {
            lostOnce.push_back(loser);
        }
    }

    // Sort the vectors and return as a 2D vector
    sort(notLost.begin(), notLost.end());
    sort(lostOnce.begin(), lostOnce.end());

    return {notLost, lostOnce};
   }
};

/*Time complexity: O(N log N), where N is the number of matches (due to sorting).
Space complexity: O(N), where N is the number of players.*/
