class Solution {
public:
   // bool comparer(vector<int> a,vector<int> b){return a<b;}
    int peakIndexInMountainArray(vector<int>& arr) {
        vector<int>tmp=arr;
        sort(tmp.begin(),tmp.end());
        return find(arr.begin(),arr.end(),tmp[arr.size()-1])-arr.begin();
    }
};
