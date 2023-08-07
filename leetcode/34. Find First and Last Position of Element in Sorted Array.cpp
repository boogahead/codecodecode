class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==target)return{0,0};
            return{-1,-1};
        }
        int start=0,end=nums.size()-1;
        int mid,answerstart=-1,answerend=-1;
        while(start<=end){//looking for starting point 
            mid=(start+end)/2;
            if(nums[mid]==target){//if matches
                    if(mid-1>=0&&nums[mid-1]==target){
                        end=mid-1;//left side matches - pivot onto left side
                    }
                    else if(mid-1<0||nums[mid-1]!=target){//found the starting point
                        answerstart=mid;
                        break;
                    }
            }
            if(nums[mid]>target){
                end=mid-1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
        }
        //cout<<"hi\n";
        start=0,end=nums.size()-1;
        while(start<=end){//looking for starting point 
            mid=(start+end)/2;
            if(nums[mid]==target){//if matches
                    if(mid+1<nums.size()&&nums[mid+1]==target){
                        start=mid+1;//right side matches - pivot onto right side
                    }
                    else if(mid+1>=nums.size()||nums[mid+1]!=target){//found the starting point
                        answerend=mid;
                        break;
                    }
            }
            if(nums[mid]>target){
                end=mid-1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
        }
        return {answerstart,answerend};
    }
};
