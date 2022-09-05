#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

void print_sol(map<string,string> mp,string final_state){
    vector<string> ans;
    string parent,child=final_state;
    while(child!="-1"){
        ans.push_back(child);
        parent=mp[child];
        child=parent;
    }
    
    for(int i=ans.size()-1;i>=0;i--){
        string str=ans[i];
        int k=0;
        for(int m=0;m<=2;m++){
            for(int n=0;n<=2;n++){
                cout<<str[k]<<" ";
                k++;
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;
    }
    
}


int find0(string str)
{
    int i=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='0')
            return i;
    }
    return -1;
}

void bfs_8Puzzle(string start_state,string final_state)
{
    map<string,int> visited;
    map<string,string> mp;
    bool flag=false;
    queue<string>q;
    int level=0;
    q.push(start_state);
    visited[start_state]++;
    mp[start_state]="-1";
    while(!q.empty() && flag==false)
    {
        int size=q.size();
        while(size--)
        {
            string temp=q.front();
            string z=temp;
            q.pop();
            if(temp==final_state)
            {
                flag=true;
                break;
            }
            int p=find0(temp);

            if(p>=3){
                swap(temp[p],temp[p-3]);
                if(visited.find(temp)==visited.end())
                    { 
                        q.push(temp);
                        visited[temp]++;
                        mp[temp]=z;
                    }
                swap(temp[p],temp[p-3]);
            }
            if(p<=5){
                swap(temp[p],temp[p+3]);
                if(visited.find(temp)==visited.end())
                    { 
                        q.push(temp);
                        visited[temp]++;
                         mp[temp]=z;
                    }
                swap(temp[p],temp[p+3]);
            }
            if(p==1 || p==2 || p==4 || p==5 || p==7 || p==8){
                swap(temp[p],temp[p-1]);
                if(visited.find(temp)==visited.end())
                    { 
                        q.push(temp);
                        visited[temp]++;
                         mp[temp]=z;
                    }
                swap(temp[p],temp[p-1]);
            }
            if(p==0 || p==1 || p==3 || p==4 || p==6 || p==7){
                swap(temp[p],temp[p+1]);
                if(visited.find(temp)==visited.end())
                    { 
                        q.push(temp);
                        visited[temp]++;
                         mp[temp]=z;
                    }
                swap(temp[p],temp[p+1]);
            }



        }
        level++;
    }

    if(flag==false){
        cout<<"This cant be solved\n";
        return;
    }

    

    cout<<"\nThis 8-Puzzle can be solved in "<<level<<" moves\n\n";
    print_sol(mp,final_state);
    return;
}

int main(int argc, char const *argv[])
{
    string start_state="324567810",final_state="123456780";
    bfs_8Puzzle(start_state,final_state);
    return 0;
}

