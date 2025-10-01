#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        vector<int> minCost(n, INT_MAX);
        minCost[0] = 0;
        
        // Priority queue: {cost, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        
        int totalCost = 0;
        
        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            
            if (visited[u] || cost > minCost[u]) continue;
            
            visited[u] = true;
            totalCost += cost;
            
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    if (dist < minCost[v]) {
                        minCost[v] = dist;
                        pq.push({dist, v});
                    }
                }
            }
        }
        
        return totalCost;
    }
};

int main() {
    Solution sol;
    
    // Test case 1: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
    // Expected: 20
    vector<vector<int>> points1 = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << "Min cost for test case 1: " << sol.minCostConnectPoints(points1) << endl;
    
    // Test case 2: points = [[3,12],[-2,5],[-4,1]]
    // Expected: 18
    vector<vector<int>> points2 = {{3,12},{-2,5},{-4,1}};
    cout << "Min cost for test case 2: " << sol.minCostConnectPoints(points2) << endl;
    
    return 0;
}
