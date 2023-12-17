class FoodRatings {
public:
    typedef pair<string,int>info;
    
    
    struct compare{
        bool operator()(info a,info b){
            if(a.second!=b.second)return a.second<b.second;
            return a.first>b.first;
        }
    };
    
    unordered_map<string,int>foodrating;
    unordered_map<string,priority_queue<info,vector<info>,compare>>foodranking;
    unordered_map<string,string>fromwhere;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            foodrating.insert({foods[i],ratings[i]});
            fromwhere[foods[i]]=cuisines[i];
            foodranking[cuisines[i]].push({foods[i],ratings[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        foodrating[food]=newRating;
        foodranking[fromwhere[food]].push({food,newRating});
    }
    
    string highestRated(string cuisine) {
        info tmp=foodranking[cuisine].top();
        while(tmp.second!=foodrating[tmp.first]){
            foodranking[cuisine].pop();
            tmp=foodranking[cuisine].top();
        }
        return foodranking[cuisine].top().first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
