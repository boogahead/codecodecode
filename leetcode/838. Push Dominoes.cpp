class Solution {
public:
    string pushDominoes(string dominoes) {
        int right=-1;
        for(int i=0;i<dominoes.size();i++){
            //cout<<i<<" "<<right<<"\n";
            if(dominoes[i]=='.')continue;
            if(dominoes[i]=='L'&&right==-1){
                for(int j=i-1;j>=0;j--){
                    if(dominoes[j]=='L')break;
                    dominoes[j]='L';
                }
                continue;
            }
            if(dominoes[i]=='L'&&right!=-1){
                int j=i;
                while(j!=right){
                    if(dominoes[right]=='L'||dominoes[j]=='R'||right==j)break;
                    dominoes[j--]='L';dominoes[right++]='R';
                }
                if(j==right){
                    dominoes[j]='.';
                }
                right=-1;
                continue;
            }
            if(dominoes[i]=='R'){
                if(right!=-1){
                    for(int j=right;j<=i;j++)dominoes[j]='R';
                }
                right=i;
                continue;
            }
        }
        if(right!=-1){
            for(int i=right;i<dominoes.size();i++)dominoes[i]='R';
        }
        return dominoes;
    }
};
