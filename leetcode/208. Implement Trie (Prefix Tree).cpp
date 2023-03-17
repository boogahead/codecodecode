class Trie {
public:
    vector<string>inputs;
    Trie() {
        
    }
    
    void insert(string word) {
        inputs.push_back(word);
    }
    
    bool search(string word) {
        for(auto i:inputs)
        {
            if(i==word)return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        for(auto i:inputs)
        {
            if(i.substr(0,prefix.length())==prefix)return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
