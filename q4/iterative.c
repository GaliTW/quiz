#define max(a,b) \
        (a > b ? a : b)

int maxSubArray(int A[], int n)
{
    int sum = 0;
    int maxSum = 0;
    for (int i = 0; i < n; ++i) {
        sum = A[i] + sum;
        if (sum < 0)
            sum = 0;

        maxSum = max(sum, maxSum);
    }

    return maxSum;
}
