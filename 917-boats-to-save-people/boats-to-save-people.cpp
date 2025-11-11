class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        //counting sort
        //in this you create a frequency array, the size of array
        //is the max element in the array

        int max=*max_element(people.begin(),people.end());


        vector<int>count(max+1,0);

        for(int p:people)
        {
            count[p]++; //created the frq table of weights

        }

        int idx=0;
        int i=1;

        while(idx<people.size()) //for traversing the people array
        {
            while(count[i]==0)
            {
                i++;
            }

            people[idx++]=i;
            count[i]--;

        }

        //now the people is sorted

        int res=0;
        int l=0;
        int r=people.size()-1;

        while(l<=r)
        {
            int remain=limit-people[r--];
            res++;

            if(remain>=people[l] && l<=r) l++;
        }
return res;
        
    }
};