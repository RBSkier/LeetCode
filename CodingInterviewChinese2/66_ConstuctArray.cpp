class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        if(n == 0)
            return vector<int>();
        
        vector<int> b(n);

        b[0] = 1;
        int left = 1;
        for(int i = 1; i < n; i++)
            b[i] = b[i-1] * a[i - 1];

        int right = 1;
        for(int i = n - 2; i >= 0; i--){
            right *= a[i + 1];
            b[i] *= right; //将之前左边的部份乘以右边的部份
        }

        return b;
    }
};

// A0 * A1 ... * Ai-1      x Ai+1 x ...
// A0 * A1 ... * Ai-1 * Ai x      x Ai+2

// ci表示0-(i-1)的连乘
// di表示(i+1)到n-1的连乘

// bi = ci-1 * di+1
