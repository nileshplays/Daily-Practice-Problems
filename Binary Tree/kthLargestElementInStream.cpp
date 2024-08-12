#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if(pq.size() < k || val > pq.top()) {
            pq.push(val);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
