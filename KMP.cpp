#include<iostream>
#include<vector>

using namespace std;

vector<int> buildLPS(string& pattern)
{
    int n=pattern.size();
    vector<int> lps(n,0);
    int i=1;
    int j=0;
    while(i<n){
        if(pattern[i]==pattern[j])
        {
            lps[i++]=++j;
        }
        else{
            if(j!=0) j=lps[--j];
            else i++;
        }
    }
    return lps;
}

vector<int> kmpAlgo(string& text, string& pattern)
{
    int m=text.size();
    int n=pattern.size();
    vector<int> lps=buildLPS(pattern);
    vector<int> res;
    cout<<"\n LPS=[ ";
    for(int x: lps) cout<<x<<" ";
    cout<<"]"<<endl;
    
    int i=0;
    int j=0;
    while(i<m)
    {
        if(pattern[j]==text[i])
        {
            i++;
            j++;
        }
        else{
            if(j!=0 )
            {
                j=lps[j-1];
            }
            else i++;
        }
        if(j==n){
            res.push_back(i-j);
        }
        
    }
    return res;
}

int main()
{
    string text;
    string pattern;
    cout<<"Enter the pattern to be searched for: ";
    cin>>pattern;
    cout<<"\nEnter the text to be searched :";
    cin>>text;
    vector<int> res=kmpAlgo(text,pattern);
    if(res.empty()) cout<<"Not found";
    else{
        cout<<"Found at: ";
        for(int x:res) cout<<x<<"  ";
        cout<<endl;
    }

}