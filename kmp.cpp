#include<iostream>
#include<vector>

using namespace std;

vector<int> buildLPS(string& pat)
{
    int n=pat.size();
    vector<int> lps(n,0);
    int len=0;
    int i=1;
    while(i<n){
        if(pat[i]==pat[len])
            lps[i++]=++len;
        else 
        {
            if(len!=0)
                len=lps[len-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> kmpAlg(string& str, string& pat)
{
    int m=str.size();
    int n=pat.size();
    vector<int> res;
    vector<int> lps=buildLPS(pat);

    int i=0;
    int j=0;

    while(i<m)
    {
        if(str[i]==pat[j])
        {
            i++;
            j++;
        }
        if(j==n)
        {
            res.push_back(i-j);
            j=lps[j-1];
        }
        else
        {
            if(i<m && str[i]!=pat[j])
            {
                if(j!=0)
                    j=lps[j-1];
                else
                    i++;
            }
            
        }
    }
    return res;
}

int main()
{
    string str="AABCDABCAABBCAABB";
    string pat="AABBCAABB";
    vector<int> res=kmpAlg(str,pat);
    // cout<<"abc";
    if(res.empty()) cout<<"No match found"<<endl;
    else{
        for(int i: res) cout<<i<<"  ";
    }
    return 0;
}