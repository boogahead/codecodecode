class Solution {
public:
    bool detectCapitalUse(string word) {
        int i;
        int length=word.size();
        if(length==1){return true;}
        bool allcaps=false;
        bool nocaps=false;
        bool firstcaps=false;
        if(word[0]>=65&&word[0]<=90)
        {
            firstcaps=true;
        }
        else{nocaps=true;}
        for(i=1;i<length;i++)
        {
            if((word[i]>=65&&word[i]<=90))
            {
                //cout<<"hi\n";
                allcaps=true;
               if(firstcaps==false||nocaps==true){return false;}// first not capital but we have capital in the middle 
            }
            if(!(word[i]>=65&&word[i]<=90))
            {
                nocaps=true;
                if(allcaps==true){return false;}//mixed
            }

        }
        return true;
    }
};
