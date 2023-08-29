class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes)\
    {
        vector<int>arr;
        for(int i=0;i<sideLength;i++){
          for(int j=0;j<sideLength;j++){
            arr.push_back((1+(width-j-1)/sideLength)*(1+(height-i-1)/sideLength));
          }
        }
        sort(arr.begin(),arr.end());
        int answer=0;
        for(int i=0;i<maxOnes;i++){
          answer+=arr[arr.size()-1-i];
        }
        return answer;
    }
};
