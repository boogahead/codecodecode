class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>missing;
        int idx=0;
        for(int i=1;i<=arr[arr.size()-1];i++)
        {
            if(i<arr[idx])
            {
                missing.push_back(i);
                if(missing.size()==k){
                    return missing[missing.size()-1];
                }
            }
            if(i==arr[idx])idx++;
        }
        return (arr[arr.size()-1]+k-missing.size());
        /*for(int i=arr[arr.size()-1]+1;i<=2500;i++)
        {
            missing.push_back(i);
            if(missing.size()==k)return  missing[missing.size()-1];
        }
        return 0;*/
    }
};
