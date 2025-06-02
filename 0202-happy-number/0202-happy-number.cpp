class Solution {
public:
    
    int next(int n)
    {
        int new_num = 0;
        while(n != 0)
        { 
            int num = n % 10;
            new_num += num * num;
            n = n / 10;
        }
        return new_num;
    }
    
    bool isHappy(int n) {
        int slow = n;
        int fast = next(n);
        while( fast != 1 and fast != slow)
        {
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1;
    }
};