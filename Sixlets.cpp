/* 

        Problem Description
        Given a array of integers A of size N and an integer B.

        Return number of non-empty subsequences of A of size B having sum <= 1000.



        Problem Constraints
        1 <= N <= 20

        1 <= A[i] <= 1000

        1 <= B <= N



        Input Format
        The first argument given is the integer array A.

        The second argument given is the integer B.



        Output Format
        Return number of subsequences of A of size B having sum <= 1000.



        Example Input
        Input 1:

            A = [1, 2, 8]
            B = 2
        Input 2:

            A = [5, 17, 1000, 11]
            B = 4


        Example Output
        Output 1:

        3
        Output 2:

        0


        Example Explanation
        Explanation 1:

        {1, 2}, {1, 8}, {2, 8}
        Explanation 1:

        No valid subsequence


*/

int generateSubsequences(vector<int> &A, int index, int counter, long long sum, int B){
    if(counter==B){
        if(sum<=1000){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(index==A.size()){
        return 0;
    }
    int x = generateSubsequences(A, index+1, counter+1, sum+A[index], B);
    int y = generateSubsequences(A, index+1, counter, sum, B);

    return x+y;
}

int Solution::solve(vector<int> &A, int B) {
    return generateSubsequences(A, 0, 0, 0, B);
}