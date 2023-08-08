class Solution {
public:
    int bsearch(vector<int>&nums,int left,int right,int target){
        int start=left,end=right;
        int mid=(start+end)/2;
        while(start<=end){
            mid=(start+end)/2;
            if(nums[mid]==target){return mid;}
            if(nums[mid]<target){
                start=mid+1;
            }
            if(nums[mid]>target){
                end=mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        //modified binary search
        int start=0,end=nums.size()-1;
        //int mid=(start+end)/2;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]>nums[nums.size()-1]){//value is currently between mid and last value of array
                start=mid+1;
            }
            else{//pivot value is larger than last value of array - must be on the left side of mid
                end=mid-1;
            }
        }
        int answer=bsearch(nums,0,start-1,target);
        if(answer!=-1)return answer;
        return bsearch(nums,start,nums.size()-1,target);
        //found pivot point

    }
};
