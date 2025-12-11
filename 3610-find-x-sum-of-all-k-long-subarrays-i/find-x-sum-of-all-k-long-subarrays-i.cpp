class Solution {
    struct Node {
    int freq;
    int val;
};
struct Cmp {
    bool operator()(const Node &a, const Node &b) const {
        if (a.freq != b.freq) {
            // higher freq should come first → max-heap by freq
            return a.freq < b.freq;
        }
        // if same freq, higher value should come first
        return a.val < b.val;
    }
};
    
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {

        //this question i have to maintain a sliding window of n-k+1 size

        vector<int>ans(nums.size()-k+1);
        unordered_map<int,int>frqmap;
      priority_queue<Node,vector<Node>, Cmp> pq;

      int l=0;
      for(int r=0;r<nums.size();r++)
      {
        frqmap[nums[r]]++;
        pq.push({frqmap[nums[r]],nums[r]});

        while(r-l+1>k )
        {
            frqmap[nums[l]]--;
            pq.push({frqmap[nums[l]],nums[l]});
            l++;
        }

        if(r-l+1==k)
        {
            int sum=0;
            int count=x;
            auto tmp=pq;
unordered_set<int> used;
            while(count>0 &&!tmp.empty())
            {
                Node top=tmp.top();
                tmp.pop();
                if (top.freq <= 0) continue;
                    if (frqmap[top.val] != top.freq) continue;
                    if (used.count(top.val)) continue; // already counted this value

                    used.insert(top.val);

                sum+=1LL * top.freq * top.val;
                

                count--;
                
            }
            ans[l]=(int)sum;
        }
      }

      return ans;

        
    }

        


    

       






        
    
};