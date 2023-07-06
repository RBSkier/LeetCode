//
//  Solution.hpp
//  leetcode
//
//  Created by Jimmy Liu on 2/7/2023.
//

#include <functional>
using namespace std;

class MedianFinder {
public:
    void addNum(int num) {
        //如果数组大小是偶数，插入右边
        if(((max.size() + min.size()) & 1) == 0)
        {
            if(!max.empty() && num < max[0])  //如果num比大顶堆的最大值要小，就要将该数改为插入左边。然后弹出最大值更新num的值
            {
                //将num改为插入左堆，然后重新校正堆结构
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());
                
                num = max[0];   //num改为左堆的新最大值
                //pop_heap和pop_back成套使用来弹出元素
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }
            //将num插入右堆
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<int>());
        }
        else    //如果数组大小是奇数，插入左堆
        {
            if(!min.empty() && min[0] < num)
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());
                
                num = min[0];
                
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }
    
    double findMedian() {
        //鲁棒性
        int size = static_cast<int>(min.size() + max.size());
        if(size == 0)
            throw runtime_error("No numbers are available");
        
        double median;
        if((size & 1) == 1) //如果大小是奇数
            median = min[0];
        else
            median = static_cast<double>(max[0] + min[0]) / 2.0;
        
        return median;
    }
private:
    vector<int> min;
    vector<int> max;
};
