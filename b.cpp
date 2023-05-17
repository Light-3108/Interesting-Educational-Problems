#include<bits/stdc++.h>
using namespace std;
#define ll long long

int visited[7][7];
string s;
int ans;
void dfs(int i, int j, int a){

    //optmize - 4  

    if(j-1>=0 && j+1<=6 && i-1>=0 && j+1<=6){
        if(visited[i][j-1] && visited[i][j+1] && (!visited[i-1][j] && !visited[i+1][j])){
            return;
        }

        if(visited[i-1][j] && visited[i+1][j] && (!visited[i][j-1] && !visited[i][j+1])){
            return;
        }
    }
    
    if(i == 6 && j == 0){
        if(a == 48){
            ans++;                           // opt - 1
        }
        return;
    }


    visited[i][j] = 1;


    if(i == 0){
        if(j>0 && j<6 && !visited[i][j-1] && !visited[i][j+1]){
            visited[i][j] = 0;
            return;
        }
    }
    if(j == 0){
        if(i>0 && i<6 && !visited[i-1][j] && !visited[i+1][j]){
            visited[i][j] = 0;
            return;
        }
    }
    if(i == 6){
        if(j>0 && j<6 && !visited[i][j-1] && !visited[i][j+1]){
            visited[i][j] = 0;
            return;
        }
    }
    if(j == 6){
        if(i>0 && i<6 && !visited[i-1][j] && !visited[i+1][j]){
            visited[i][j] = 0;
            return;
        }
    }
    if(s[a] == '?' || s[a] == 'U'){  
              
        if(i && !visited[i-1][j]){
            dfs(i-1,j,a+1);
        }
    }

    if(s[a] == '?' || s[a] == 'D'){
        
        if(i<6 && !visited[i+1][j]){
            dfs(i+1,j,a+1);
        }
    }

    if(s[a] == '?' || s[a] == 'L'){
        if(j && !visited[i][j-1]){
            dfs(i,j-1,a+1);
        }
    }

    if(s[a] == '?' || s[a] == 'R'){

        if(j<6 && !visited[i][j+1]){
            dfs(i,j+1,a+1);
        }
    }

    visited[i][j] = 0;
}
int main(){
    cin>>s;
    ans = 0;
    dfs(0,0,0);
    cout<<ans<<endl;
    return 0;
}