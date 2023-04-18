#include <iostream>
#include <vector>
using namespace std;

int leftMostOneRow(vector<vector<int>>& V) {

    int leftMostRow = -1;
    int maxOneRow = -1;

    int j = V.empty() ? -1 : V[0].size() - 1;

    for (int i = 0; i < V.size(); i++) {
        
        j = min(j, (int)V[i].size() - 1);
        while(j >= 0 && V[i][j] == 1) {
            leftMostRow = j;
            j--;
            maxOneRow = i;
        }
    }
    return maxOneRow;
}

int main() {

    int n,m;
    cin>>n>>m;

    vector<vector<int>> vec(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }

    int ans = leftMostOneRow(vec);
    cout << ans << '\n';

    return 0;
}

/*--------------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;

int leftMostOneRow(vector<vector<int>>& V) {

    int leftMostRow = -1;
    int maxOneRow = -1;

    int j = V.empty() ? -1 : V[0].size() - 1;

    for(int i = 0; i < V.size(); i++) {
        j = min(j, (int)V[i].size() - 1);
        while (j >= 0 && V[i][j] == 1) {
            leftMostRow = j;
            j--;
            maxOneRow = i;
        }
    }

    return maxOneRow;

    
}

int main() {
    int n,m;
    cin>>n>>m;

    vector<vector<int>> vec(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }

    int ans = leftMostOneRow(vec);
    cout << ans << '\n';

    return 0;
}

/*---------------------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;

int leftMostOneRow(vector<vector<int>>& V) {

    int leftMOstRow = -1;
    int maxOneRow = -1;

    int j = V.empty() ? -1 : V[0].size() - 1;

    for(int i = 0; i < V.size(); i++) {
        j = min(j, (int)V[i].size() - 1);
        while (j >= 0 && V[i][j] == 1) {
            leftMostRow = j;
            j--;
            maxOneRow = i;
        }
    }

    return maxOneRow;

    
}

int main() {

    int n,m;
    cin>>n>>m;

    vector<vector<int>> vec(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }

    int ans = leftMostOneRow(vec);
    cout << ans << '\n';

    return 0;
}
/*---------------------------------------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;

int leftMostRow(vector<vector<int>>& V) {

    int leftMostRow = -1;
    int maxOneRow = -1;

    int j = V.empty() ? -1 : V[0].size() - 1;

    for(int i = 0; i < V.size(); i++) {
        j = min(j, (int)V[i].size() - 1);
        while (j >= 0 && V[i][j] == 1) {
            leftMostRow = j;
            j--;
            maxOneRow = i;
        }
    }

    return maxOneRow;
}

int main() {
    
    int n,m;
    cin>>n>>m;

    vector<vector<int>> vec(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }

    int ans = leftMostOneRow(vec);
    cout << ans << '\n';

    return 0;
}