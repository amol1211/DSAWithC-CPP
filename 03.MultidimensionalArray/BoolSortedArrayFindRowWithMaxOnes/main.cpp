#include <iostream>
#include <vector>
using namespace std;

// Function to find the index of the row with the leftmost 1 in a matrix
int leftMostOneRow(vector<vector<int>>& V) {

    // Initialize leftmost row and maximum 1's row to -1
    int leftMostRow = -1;
    int maxOneRow = -1;

    // Initialize j to the number of columns in the first row minus 1,
    // or to -1 if the matrix is empty
    int j = V.empty() ? -1 : V[0].size() - 1;

    // Find the leftmost 1 in the matrix
    for (int i = 0; i < V.size(); i++) {
        // If the current row has fewer columns than the previous row,
        // update j to the minimum of the number of columns in the current
        // row minus 1 and the current value of j
        j = min(j, (int)V[i].size() - 1);
        while (j >= 0 && V[i][j] == 1) {
            leftMostRow = j;
            j--;
            maxOneRow = i;
        }
    }

    // Return the index of the row with the leftmost 1, or -1 if there are no 1's
    return maxOneRow;
}


// Main function
int main() {

    // Read in the number of rows and columns
    int n,m;
    cin >> n >> m;

    // Create a vector of vectors to store the matrix
    vector<vector<int>> vec(n, vector<int>(m));

    // Read in the elements of the matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }

    // Find the index of the row with the leftmost 1 and print it
    int ans = leftMostOneRow(vec);
    cout << ans << '\n'; 

    // Return 0 to indicate successful program execution
    return 0;
}
