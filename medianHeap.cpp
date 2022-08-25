// checked on https://www.spoj.com/problems/WEIRDFN/

struct medianHeap {
    priority_queue<int> less;
    priority_queue<int, vector<int>, greater<>> more;
    int median = numeric_limits<int>::max();

    void addNum(int x) {
        if (less.empty() && more.empty()) {
            less.push(x);
            median = x;
            return;
        }
        if (x >= less.top()) {
            more.push(x);
        } else {
            less.push(x);
        }
        while (less.size() > more.size() + 1) {
            more.push(less.top());
            less.pop();
        }
        while (more.size() > less.size()) {
            less.push(more.top());
            more.pop();
        }
        median = less.top();
    }
};