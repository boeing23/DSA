class Solution {
   inline static const unordered_map<char,int> VALUES{
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
    };
public:
    int romanToInt(string s) {
        int number=0;
        int i=0;

        while(i<s.size())
        {
            int curr=VALUES.at(s[i]);

            if(i+1<s.size())
            {
                int next=VALUES.at(s[i+1]);
                if(curr<next)
                {
                    number+=next-curr;
                    i+=2;
                    continue;
                }
            }

            
            
                number+=VALUES.at(s[i]);
                i++;
            
        }

        return number;

        
        
    }
};