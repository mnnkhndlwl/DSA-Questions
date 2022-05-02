class MedianFinder {
public:
     priority_queue<int> pqmax;
     priority_queue<int , vector<int> , greater<int>> pqmin;
  
    //function to simply add num in queues.
    void addNum(int num) {
        if(pqmax.empty() or pqmax.top()>=num)
            pqmax.push(num);
        else
            pqmin.push(num);
        balanceHeap();
        
    }
	//function to balance the queues.
    void balanceHeap(){  
        if(pqmax.size()>pqmin.size() and pqmax.size()-pqmin.size()>1){
            pqmin.push(pqmax.top());
            pqmax.pop();
        }
        else if(pqmin.size()>pqmax.size() and pqmin.size()-pqmax.size()>1){
            pqmax.push(pqmin.top());
            pqmin.pop();
        }
            
    }
    
    double findMedian() {
        if(pqmax.size() ==pqmin.size())
            return (pqmax.top() + pqmin.top())/2.0;
        else if(pqmax.size()>pqmin.size())
            return pqmax.top();
        else
            return pqmin.top();
    }
};