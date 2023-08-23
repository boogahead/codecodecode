class Solution {
public:
    typedef pair<int,int>info;
    string reorganizeString(string s) {
        priority_queue<info>pq;
        vector<int>table(26);
        for(auto i:s){
            table[i-'a']++;
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            if(table[i]>0)pq.push({table[i],i});
        }
        string answer;
        while(!pq.empty()){
            auto top=pq.top();//put first most frequently used character
            top.first--;//since we used it, deduct its count
            pq.pop();//pop from priority queue
            if(answer.length()==0||top.second+'a'!=answer[answer.length()-1]){//if its empty or the last character on the answer string is different to the current top value we just popped
                answer+=top.second+'a';//add it to the answer string
            }
            else{//if last character on answer string is the same 
                //cout<<pq.size();
                if(pq.empty()){return "";}//if theres no more characters to use, this string cannot be done
                auto sec=pq.top();//pop the second value 
                sec.first--;
                pq.pop();
                answer+=sec.second+'a';//since this is guaranteed to be different from the last character on answer string, add it
                if(sec.first>0){//if theres more of this character to be used,
                pq.push(sec);//add it to the priority queue
                }
                top.first++;//since we did not use the 'top' character - or literally the most frequently appearing character left in string s, add one count for more usage
            }
            if(top.first>0){
                //cout<<"pushed\n";
            pq.push(top);
            }
            //cout<<answer<<" ";
        }
        return answer;
    }
};
