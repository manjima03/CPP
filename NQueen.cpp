#include<iostream>
#include<vector>
using namespace std;

class Solution{

    public: 

    bool isSafe(int row,int col,int n, vector<string>& board)
    {
        int row1=row;
        int col1=col;
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        row=row1;
        col=col1;
        while(col>=0)
        {
            if(board[row][col]=='Q') return false;
            col--;
        }
        row=row1;
        col=col1;
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }

    void solve(int col,vector<string>& board, int n , vector<vector<string>>& ans)
    {
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,n, board)){
                board[row][col]='Q';
                solve(col+1,board,n,ans);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueen(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for (int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,board,n,ans);
        return ans;
    }

    
};

int main(){
    int n;
    cout<<"Number: ";
    cin>>n;
    Solution s;
    vector<vector<string>> res=s.solveNQueen(n);
    cout<<"\nNumber of options: "<<res.size()<<endl;
    return 0;
}
