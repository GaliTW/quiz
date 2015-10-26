#define max(a,b) \
        (a > b ? a : b)

int _maxSubArray(int A[], int n, int sum, int maxSum, int k)
{
    if (k <= 0)
        return maxSum;

    sum = A[n - k] + sum;
    if (sum < 0)
        sum = 0;

    maxSum = max(sum, maxSum);

    return _maxSubArray(A, n, sum, maxSum, k - 1);
}

int maxSubArray(int A[], int n)
{
    return _maxSubArray(A, n, 0, 0, n);
}
