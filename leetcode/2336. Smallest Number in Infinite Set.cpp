class SmallestInfiniteSet {
public:
    map<int,bool>table;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)
        {
            table.insert({i,true});
        }
    }
    int popSmallest() {
        for(int i=1;i<=1000;i++)
        {
            if(table[i])
            {
                table[i]=false;
                return i;
            }
        }return 0;
    }
    
    void addBack(int num) {
        if(!table[num])
        {
            table[num]=true;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
