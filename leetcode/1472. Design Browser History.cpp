class BrowserHistory {
public:
    vector<string> links;
    int curidx=0;
    BrowserHistory(string homepage) {
        links.push_back(homepage);
    }
    
    void visit(string url) {
        //links.push_back(url);
        curidx++;
        for(int i=links.size()-1;i>=curidx;i--)
        {
            links.pop_back();
        }links.push_back(url);
        
    }
    
    string back(int steps) {
        curidx-=steps;
        if(curidx<0)curidx=0;
        return links[curidx];
    }
    
    string forward(int steps) {
        curidx+=steps;
        if(curidx>=links.size())curidx=links.size()-1;
        return links[curidx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
