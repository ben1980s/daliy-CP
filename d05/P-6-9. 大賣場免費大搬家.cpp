#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,w;
    cin >> n >> w;
    vector<int> weight(n + 1);
    vector<int> value(n + 1);
    for(int i = 1 ; i <= n ; i ++){
        cin >> weight[i];
    }
    for(int i = 1 ; i <= n ; i ++){
        cin >> value[i];
    }
    vector<vector<int>> dp(n + 1,vector<int>(w + 1,0));
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= w ; j ++){
            if(j - weight[i] >= 0){
                dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - weight[i]] + value[i]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][w]<<"\n";
}