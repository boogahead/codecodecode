class TicTacToe {
public:
    vector<vector<int>> table;
    int size;
    TicTacToe(int n) {
        table.resize(n,vector<int>(n));
    }
    int move(int row, int col, int player) {
        table[row][col]=player;
        bool hor,vert,leftdiag,rightdiag;
        hor=vert=leftdiag=rightdiag=true;
        //go horizontal
        int cnt=0;
        for(int i=0;i<table.size();i++)
        {
            if(table[row][i]!=player)
            {hor=false;break;
            }cnt++;
        }
        if(hor&&cnt==table.size())return player;
        //go vertical
        cnt=0;
        for(int i=0;i<table.size();i++)
        {
            if(table[i][col]!=player){
                vert=false;break;
            }cnt++;
        }if(vert&&cnt==table.size())return player;
        //go left top to right bottom
        cnt=0;
        if(row==col)
        {
            int i=0;
            while(i<table.size())
            {
                if(table[i][i]!=player){
                    leftdiag=false;break;
                }i++;cnt++;
            }
            if(leftdiag&&cnt==table.size())return player;
        }
        //go right top to left bottom
        cnt=0;
        int i=table.size()-1,j=0;
        for(int j=0;j<table.size();j++)
        {
            if(table[j][i]!=player){
                rightdiag=false;break;
            }cnt++;
            i--;
        }if(rightdiag&&cnt==table.size())return player;
        return 0;
        //if(hori||vert||leftdiag||rightdiag)return player;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
