class NumArray {
public:
    vector<long long>segment_tree;
    vector<int>number;
    NumArray(vector<int>& nums) {
        int tree_height=(int)ceil(log2(nums.size()));
        int tree_size=(1<<(tree_height+1));
        segment_tree.resize(tree_size);
        number=nums;
        build(1,0,nums.size()-1);
    }
    long long build(long long node,int start,int end){
        if(start==end)return segment_tree[node]=(long long)number[start];
        int mid=(start+end)/2;
        long long left=build(node*2,start,mid);
        long long right=build(node*2+1,mid+1,end);
        return segment_tree[node]=left+right;
    }
    void update(int index, int val) {
        long long diff=val-number[index];
        number[index]=val;
        my_update(1,0,number.size()-1,index,diff);
    }
    void my_update(long long node,int start,int end,int idx,long long diff){
        if(idx<start||idx>end)return;
        segment_tree[node]+=diff;
        if(start!=end){
            int mid=(start+end)/2;
            my_update(node*2,start,mid,idx,diff);
            my_update(node*2+1,mid+1,end,idx,diff);
        }
    }
    int sumRange(int left, int right) {
        if(left>right)swap(left,right);
        return calculate(1,0,number.size()-1,left,right);
    }
    long long calculate(long long node,int start,int end,int left,int right){
        if(left>end||right<start)return 0;
        if(left<=start&&end<=right)return segment_tree[node];
        //cout<<node<<"\n";
        int mid=(start+end)/2;
        long long leftresult=calculate(node*2,start,mid,left,right);
        long long rightresult=calculate(node*2+1,mid+1,end,left,right);
        return leftresult+rightresult;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
