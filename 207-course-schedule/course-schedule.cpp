class Solution {
public:
    bool detectCycle(vector<vector<int>>& graph, vector<int>& vis, vector<int>& dfsVis, int curr) {
        vis[curr] = 1;      // Mark the current node as visited
        dfsVis[curr] = 1;   // Mark the current node in the recursion stack

        for (auto neighbor : graph[curr]) {
            if (!vis[neighbor]) {
                // If the neighbor is not visited, recursively call the function
                if (detectCycle(graph, vis, dfsVis, neighbor)) return true;
            } else if (dfsVis[neighbor]) {
                // If the neighbor is in the recursion stack, a cycle is detected
                return true;
            }
        }

        dfsVis[curr] = 0;  // Remove the node from the recursion stack
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build the adjacency list for the graph
        vector<vector<int>> graph(numCourses);
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]); // Directed edge: pre[1] -> pre[0]
        }

        vector<int> vis(numCourses, 0);      // Visited nodes
        vector<int> dfsVis(numCourses, 0);  // Recursion stack

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (detectCycle(graph, vis, dfsVis, i)) return false;
            }
        }
        return true;
    }
};
