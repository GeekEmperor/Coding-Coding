class Solution {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
public:
    void Insert(int num)
    {
        if ((maxHeap.size() + minHeap.size()) & 1) {
            if (maxHeap.top() > num) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
            else
                minHeap.push(num);
        }
        else {
            if (!minHeap.empty() && minHeap.top() < num) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
            else
                maxHeap.push(num);
        }
    }
 
    double GetMedian()
    {
        if ((maxHeap.size() + minHeap.size()) & 1)
            return maxHeap.top();
        else
            return (maxHeap.top() + minHeap.top()) / 2.0;
    }
 
};