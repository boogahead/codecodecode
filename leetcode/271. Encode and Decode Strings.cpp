class Codec {
public:
    /*
    we add "/*" to mark end of a string
    but there are cases when / exists.
    so we add an extra / to the / temporarily -
    e.g. table/ => table//
    and we go through the string and look ahead to see
    if we have : or / one index further when we encounter
    '/'.
    
    */
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encodedstring;
        for(auto i:strs){
            for(auto j : i){
                if(j=='/'){
                    encodedstring+="//";
                }else{
                    encodedstring+=j;
                }
            }encodedstring=encodedstring+"/:";
        }
        //cout<<encodedstring<<"\n";
        return encodedstring;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string>answer;
        string tmp;
        for(int i=0;i<s.length();i++){
            if(s[i]=='/'&&s[i+1]==':'){
                answer.push_back(tmp);
                i+=1;
                tmp.clear();
                continue;
            }
            else if(s[i]=='/'&&s[i+1]=='/'){
                tmp+='/';
                i+=1;continue;
            }
            tmp+=s[i];
        }
        return answer;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
