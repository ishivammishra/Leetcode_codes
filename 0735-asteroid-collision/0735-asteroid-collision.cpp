class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> s;
        for(int i = 0; i < n; i++)
        {
            int curr = asteroids[i];
        // here we are pushing all the pos value in the stack
            if(curr>0 || s.empty())
            {
                s.push(curr);
            }
            // handling collisons
            else
            {
                // we are destroying all the smaller values
                while(!s.empty() and s.top() > 0 and s.top() < abs(curr))
                {
                    s.pop();
                }
                // if we get same elements
                if(!s.empty() and s.top() == abs(curr))
                {
                    s.pop();
                }
                else
                {
                    // simply pushing neg values 
                    if(s.empty() || s.top()<0)
                    {
                        s.push(curr);
                    }
                }
            }
        }

        vector<int> ans(s.size());
        for(int i = (int) s.size()-1; i>=0; i--)
        {
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};