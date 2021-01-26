class Solution {
public:
    /*
    struct cmp
    {
        bool operator()(pair<long, short>& a, pair<long, short>& b)
        {
            return a.first > b.first;
        }
    };
    */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        /*
        vector<int> ugly(n, 1);
        vector<int> ptr(n, 0);
        ptr[0] = 1;
        priority_queue<pair<long, short>, vector<pair<long, short>>, cmp> pq;
        pq.push(make_pair(primes[0], 0));
        int size = primes.size();
        for (short i = 1; i < n; ++i)
        {
            pair<long, short> temp(pq.top());
            pq.pop();
            if (temp.first <= ugly[i - 1])
                --i;
            else
            {
                ugly[i] = temp.first;
                short j = temp.second;
                if (ptr[j] < size) {
                    pq.push(make_pair(ugly[j] * primes[ptr[j]], j));
                    ++ptr[j];
                }
                pq.push(make_pair(ugly[i] * primes[ptr[i]], i));
                ++ptr[i];
            }
        }
        return ugly[n - 1];
        */
        
        vector<long> ugly(n, 1);
        priority_queue<long, vector<long>, greater<long>> pq;
        int size = primes.size();
        for (int i = 0; i < size; ++i)
            pq.push(primes[i]);
        for (int i = 1; i < n; ++i)
        {
            ugly[i] = pq.top();
            pq.pop();
            if (ugly[i] <= ugly[i - 1])
                --i;
            else
                for (int j = 0; j < size; ++j)
                    pq.push(ugly[i] * primes[j]);
        }
        return ugly[n - 1];
        
    }
};