//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int count = 0;
        int total = row*col;

        int startingRow = 0;
        int endingCol = col-1;
        int endingRow = row-1;
        int startingCol = 0;

        while(count < total){
            //printing 1st Row
            for(int i = startingCol; i<=endingCol && count<total ; i++){
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;
            //printing last column
            for(int i=startingRow; i<=endingRow && count<total ;i++){
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            //printing last row
            for(int i=endingCol; i>=startingCol && count<total ;i--){
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            //printing 1st Col
            for(int i=endingRow; i>=startingRow && count< total; i--){
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends