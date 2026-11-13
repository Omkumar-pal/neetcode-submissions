class MedianFinder {
public:
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;

    MedianFinder() {
        
    }
    
    
    void addNum(int num) {
    maxH.push(num);
    minH.push(maxH.top());
    maxH.pop();
    if (minH.size() > maxH.size() + 1) {
        maxH.push(minH.top());
        minH.pop();
    }
}
    double findMedian() {
        if (minH.size() > maxH.size()){
            return double(minH.top());
        }
        return (double(minH.top()) + double(maxH.top()))/2;
    }
};
