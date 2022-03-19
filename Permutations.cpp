/* 

        Problem Description

        Given an integer array A of size N denoting collection of numbers , return all possible permutations.

        NOTE:

        No two entries in the permutation sequence should be the same.
        For the purpose of this problem, assume that all the numbers in the collection are unique.
        Return the answer in any order
        WARNING: DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS. Example : next_permutations in C++ / itertools.permutations in python.
        If you do, we will disqualify your submission retroactively and give you penalty points.


        Problem Constraints

        1 <= N <= 9



        Input Format

        Only argument is an integer array A of size N.



        Output Format

        Return a 2-D array denoting all possible permutation of the array.



        Example Input

        A = [1, 2, 3]


        Example Output

        [ [1, 2, 3]
        [1, 3, 2]
        [2, 1, 3] 
        [2, 3, 1] 
        [3, 1, 2] 
        [3, 2, 1] ]


        Example Explanation

        All the possible permutation of array [1, 2, 3].

*/

void generatePermutations(vector<int> &A, int index, vector<vector<int>> &ans){
    if(index==A.size()){
        ans.push_back(A);
        return;
    }
    for(int i=index;i<A.size();i++){
        swap(A[index], A[i]);
        generatePermutations(A, i+1, ans);
        swap(A[index], A[i]);
    }
}

vector<vector<int>> Solution::permute(vector<int> &A){
    vector<vector<int>> ans;
    generatePermutations(A, 0, ans);
    return ans;
}