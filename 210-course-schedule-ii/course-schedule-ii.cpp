class Solution {
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>premap;
        unordered_set<int>cycle;
        vector<int>output;
        unordered_set<int>visit;

    for(int i=0;i<numCourses;i++)
    {
         premap[i]={};

    }
for(const auto&pre: prerequisites)
{
    premap[pre[0]].push_back(pre[1]);
}
for(int c=0;c<numCourses;c++)
{
    if(!dfs(premap,cycle,output,visit,c)) return {};
}

return output;
        
    }

    bool dfs(unordered_map<int, vector<int>>&premap, unordered_set<int>&cycle, vector<int>&output,unordered_set<int>&visit, int crs)
    {
        if(cycle.count(crs)) return false;
        if(visit.count(crs)) return true;

        cycle.insert(crs);

        if(premap.count(crs))
        {
            for(int pre: premap.at(crs))
            {
                if(!dfs(premap,cycle,output,visit,pre)) return false;
            }
        }

        cycle.erase(crs);
        visit.insert(crs);
        output.push_back(crs);

        return true;
    }
};
