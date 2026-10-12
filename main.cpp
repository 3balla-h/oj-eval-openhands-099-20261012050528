#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Directions for adjacent cells: up, right, down, left
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

// DFS to explore a connected water region and calculate total fish
int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int m, int n) {
    // Mark current cell as visited
    visited[x][y] = true;
    int totalFish = grid[x][y];  // Add fish from current cell
    
    // Explore all 4 adjacent cells
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // Check if the new position is within bounds and is unvisited water
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
            grid[nx][ny] > 0 && !visited[nx][ny]) {
            totalFish += dfs(grid, visited, nx, ny, m, n);
        }
    }
    
    return totalFish;
}

int main() {
    int m, n;
    cin >> m >> n;
    
    // Read the grid
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    // Track visited cells
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int maxFish = 0;
    
    // Explore each cell
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // If it's a water cell and not visited yet
            if (grid[i][j] > 0 && !visited[i][j]) {
                // Find the total fish in this connected water region
                int fishInRegion = dfs(grid, visited, i, j, m, n);
                maxFish = max(maxFish, fishInRegion);
            }
        }
    }
    
    cout << maxFish << endl;
    
    return 0;
}