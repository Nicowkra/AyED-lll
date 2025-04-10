#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
bool esPosible(vector<vector<int> > grid,int n,int m){
    if (((n+m-1) % 2)!=0){return false;}
    
    vector<vector<int> > minSum(n, vector<int>(m, 1e9));
    vector<vector<int> > maxSum(n, vector<int>(m, -1e9));

    minSum[0][0] = maxSum[0][0] = grid[0][0];

    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                if (i + 1 < n) {
                    minSum[i + 1][j] = min(minSum[i + 1][j], minSum[i][j] + grid[i + 1][j]);
                    maxSum[i + 1][j] = max(maxSum[i + 1][j], maxSum[i][j] + grid[i + 1][j]);
                }
                if (j + 1 < m) {
                    minSum[i][j + 1] = min(minSum[i][j + 1], minSum[i][j] + grid[i][j + 1]);
                    maxSum[i][j + 1] = max(maxSum[i][j + 1], maxSum[i][j] + grid[i][j + 1]);
            }
        }
    }
    return minSum[n - 1][m - 1] <= 0 && 0 <= maxSum[n - 1][m - 1];
}
int main(){
    int i = 0;
    int casos;
    cin >> casos;
    while (casos>i){
        i++;
        int n, m;
        cin >> n >> m;
        vector<vector<int> > grid(n, vector<int>(m));
        for (int j = 0; j < n; ++j){
            for (int k = 0; k < m; ++k){
                cin >> grid[j][k];
            }}
    if (esPosible(grid,n,m)){cout << "YES\n";}
    else{cout << "NO\n";}
    }
    
return 0;
}