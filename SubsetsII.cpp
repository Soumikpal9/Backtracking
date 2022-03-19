/*

        Problem Description

        Given a collection of integers denoted by array A of size N that might contain duplicates, return all possible subsets.

        NOTE:

        Elements in a subset must be in non-descending order.
        The solution set must not contain duplicate subsets.
        The subsets must be sorted lexicographically.


        Problem Constraints

        0 <= N <= 16



        Input Format

        Only argument is an integer array A of size N.



        Output Format

        Return a 2-D vector denoting all the possible subsets.



        Example Input

        Input 1:

        A = [1, 2, 2]
        Input 2:

        A = [1, 1]


        Example Output

        Output 1:

        [
            [],
            [1],
            [1, 2],
            [1, 2, 2],
            [2],
            [2, 2]
        ]
        Output 2:

        [
            [],
            [1],
            [1, 1]
        ]


        Example Explanation

        Explanation 1:

        All the subsets of the array [1, 2, 2] in lexicographically sorted order.

*/

void getSubsets(vector<int> &A, int index, vector<int> &temp, vector<vcetor<int>> &ans){
    ans.push_back(temp);
    for(int i=index;i<A.size();i++){
        if(i!=index && A[i]==A[i-1]){
            continue;
        }
        temp.push_back(A[i]);
        getSubsets(A, i+1, temp, ans);
        temp.pop_back();
    }
}

vector<vector<int>> Solution::subsetsWithDup(vector<int> &A){
    vector<vector<int>> ans;
    vector<int> temp;
    sort(A.begin(), A.end());
    getSubsets(A, 0, temp, ans);
    return ans;
}