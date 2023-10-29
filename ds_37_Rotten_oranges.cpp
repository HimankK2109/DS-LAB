#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int minutes = 0;
    
    queue<pair<int, int>> rotten;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                rotten.push({i, j});
            }
        }
    }

    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    while (!rotten.empty()) {
        int size = rotten.size();

        for (int i = 0; i < size; i++) {
            int r = rotten.front().first;
            int c = rotten.front().second;
            rotten.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    rotten.push({nr, nc});
                }
            }
        }

        if (!rotten.empty()) {
            minutes++;
        }
    }

    // Check if there are any fresh oranges left
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }
    return minutes;
}

int main() {
    cout<<"Himank Kumar C0/206"<<endl;
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = orangesRotting(grid);

    if (result != -1) {
        cout << "Time taken to rot all oranges: " << result << " minutes" << endl;
    } else {
        cout << "It's not possible to rot all oranges." << endl;
    }

    return 0;
}
