#include<bits/stdc++.h>
using namespace std;

int cnt;
int n;
void search(vector<vector<char>> &ar, int y, vector<int> &col, vector<int> &diag1, vector<int> &diag2){

    if(y == n){
        cnt++;
        return;
    }

    for(int x=0; x<n; x++){
        if(col[x] || diag1[x+y] || diag2[x-y+n-1] || ar[x][y] == '*') continue;
        
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(ar,y+1,col,diag1,diag2);

        col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
}
int main(){

    n = 8;
    vector<vector<char>> ar(8,vector<char>(8,'a'));

    for(int i=0; i<8; i++){

        for(int j=0; j<8; j++){
            char ch; cin>>ch;
            ar[i][j] = ch;
        }
    }

    int sz = 2*n;
    vector<int> col(sz,0);
    vector<int> diag1(sz,0);
    vector<int> diag2(sz,0);

    cnt = 0;

    search(ar,0,col,diag1,diag2);

    cout<<cnt<<endl;

    return 0;
}