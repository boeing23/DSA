class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // first get the count of each task and maxHeap to keeep track of most freq tasks


        vector<int>count(26,0);

        for(int i=0; i<tasks.size();i++)
        {
            count[tasks[i]-'A']++;
        }
        priority_queue<int>maxHeap;

        for(int i=0;i<26;i++)
        {
            if(count[i]>0)
            {
                maxHeap.push(count[i]);
            }
        }

        int time=0;
        queue<pair<int,int>>q;


        while(!maxHeap.empty() || !q.empty())
        {
            time++;

            if(maxHeap.empty())
            {
                time=q.front().second;
            }
            else
            {
                int cnt=maxHeap.top()-1;
                maxHeap.pop();
                if(cnt>0)
                {
                    q.push({cnt,time+n});

                }

                

            }
            if(!q.empty() && q.front().second==time)
            {
                int front=q.front().first;
                q.pop();
                maxHeap.push(front);
            }
        }


        return time;
    }
};