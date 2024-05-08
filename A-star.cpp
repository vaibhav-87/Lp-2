#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Node {
    int x, y; // Coordinates of the node
    int cost; // Cost to reach this node
    int heuristic; // Heuristic value (estimated cost to goal)
    
    bool operator>(const Node& other) const {
        return (cost + heuristic) > (other.cost + other.heuristic);
    }
};

int calculateHeuristic(int x, int y, int goalX, int goalY) {
    // Using Euclidean distance as the heuristic
    return static_cast<int>(sqrt(pow(goalX - x, 2) + pow(goalY - y, 2)));
}

bool isValid(int x, int y, int rows, int cols) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

int AStar(vector<vector<int>>& grid, int startX, int startY, int goalX, int goalY) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    priority_queue<Node, vector<Node>, greater<Node>> pq; // Min heap
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Initial node
    Node startNode = {startX, startY, 0, calculateHeuristic(startX, startY, goalX, goalY)};
    pq.push(startNode);

    // Possible movements: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.x == goalX && current.y == goalY) {
            return current.cost;
        }

        if (visited[current.x][current.y]) {
            continue;
        }

        visited[current.x][current.y] = true;

        for (int i = 0; i < 4; ++i) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (isValid(newX, newY, rows, cols) && !visited[newX][newY] && grid[newX][newY] != -1) {
                Node neighbor = {newX, newY, current.cost + 1, calculateHeuristic(newX, newY, goalX, goalY)};
                pq.push(neighbor);
            }
        }
    }

    // Goal not reached
    return -1;
}

int main() {
    // Example usage
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {0, -1, -1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, -1, 0, -1, 0},
        {0, 0, 0, 0, 0}
    };

    int startX = 0, startY = 0;
    int goalX = 4, goalY = 4;

    int shortestPathCost = AStar(grid, startX, startY, goalX, goalY);

    if (shortestPathCost != -1) {
        cout << "Shortest path cost: " << shortestPathCost << endl;
    } else {
        cout << "No path found to the goal." << endl;
    }

    return 0;
}
