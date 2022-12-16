struct compareTo{
    bool operator()(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}
};
vector<int> topKFrequent(vector<int>& nums, int k) {
    if(nums.size()<k)
        return vector<int>();
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        map[nums[i]]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,compareTo> pq;
    for(auto a: map){
        pq.push(a);
    }
    vector<int> result;
    for(int i = 0;i< k;i++){
        result.push_back(pq.top().first);
        pq.pop();
    }
    return result;
}