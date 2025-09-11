class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // max-heap: farthest at top; store (d2, index)
        priority_queue<pair<long long,int>> pq;

        for (int i = 0; i < (int)points.size(); ++i) {
            long long dx = points[i][0], dy = points[i][1];
            long long d2 = dx*dx + dy*dy;
            pq.push({d2, i});
            if ((int)pq.size() > k) pq.pop(); // keep only K closest
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res; // order not guaranteed; reverse() if needed
    }
};