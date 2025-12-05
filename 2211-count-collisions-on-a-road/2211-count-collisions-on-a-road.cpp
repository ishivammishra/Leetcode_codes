class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();

        int left = 0;
        int right = n-1;

        while(left < n and directions[left] =='L')
            left++;
        
        while(right>= 0 and directions[right] == 'R')
            right--;
        
        int count = 0;

        for(int i = left; i <= right; i++)
        {
            count += directions[i] != 'S';
        }

        return count;

    }
};