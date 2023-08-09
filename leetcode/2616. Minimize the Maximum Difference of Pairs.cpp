class Solution {
public:
    int thresholdchecker(vector<int>&nums,int threshold){
        /*
        returns the number of instances with the pair difference of variable threshold
        */
        int count=0,i=0;
        while(i<nums.size()-1){
            if(abs(nums[i]-nums[i+1])<=threshold){
                count++;i++;
            }
            i++;
        }
        return count;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int left=0,right=nums[nums.size()-1]-nums[0];
        while(left<right){
            int mid=left+(right-left)/2;
            /*
            safer since it prevents number larger than right from being stored
            */
            if(thresholdchecker(nums,mid)>=p){
                /*
                threshold is too big so its returning more than we need - reduce the threshold
                */
                right=mid;
            }
            else{
                /*
                we need larger threshold to have more count returned
                */
                left=mid+1;
            }
        }
        return left;
    }
};
