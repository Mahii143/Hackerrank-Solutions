/*
Flip the matrix:
  Your task is to flip rows and columns any number of times to get maximum sum from the first quadrant of the 2Nx2N matrix.
  
my solution:
  *The problem here is a little tricky
  *you might end up creating functions to reverse rows and columns seperately and check for maximum values in rows and columns to get reversed.
    But the solution is very simple.
  *If we want the maximum value for 00, 01, 10, 11 positions we just have to find maximum values of their respective opposite sides on 
   both verticals and horizontals.
  *The maximum value can be added to the sum.
  *Finally display the sum.
  *Don't panick after seeing so much matrix array elements being checked here. They are just eligible candidate elements for the required positions.
  *Example:
    Input: 2
    matrix: 4 x 4 (2N x 2N)
    00 index had it's eligible candidates on 00, 03, 30, 33
  :)
*/
int flipTheMatrix(vector<vector<int>> matrix){
    int row = matrix.size();
    int col = matrix[0].size();
    int max;
    int sum = 0;
    
    for(int i=0;i<row/2;i++) {
        for(int j=0;j<col/2;j++) {
            if(matrix[i][j] > matrix[row-i-1][j] && matrix[i][j] > matrix[i][col-j-1] &&
             matrix[i][j] > matrix[row-i-1][col-j-1]) {
                max = matrix[i][j];
             }
            else if(matrix[row-i-1][j] > matrix[i][col-j-1] && matrix[row-i-1][j] > matrix[row-i-1][col-j-1]) {
                max = matrix[row-i-1][j];
            }
            else if(matrix[i][col-j-1] > matrix[row-i-1][col-j-1] ) {
                max = matrix[i][col-j-1];
            }
            else {
                max = matrix[row-i-1][col-j-1];
            }
                        
            sum += max;
        }
    }
    return sum;
}
