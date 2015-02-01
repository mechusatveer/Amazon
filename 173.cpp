1) You are given an array of both negative and positive integers.
You need to rearrange the array such that positive and negative
numbers alternate. Also, the order should be same as previous
array and only O(1) auxiliary space can be used and time complexity O(n).
eg. -2 3 4 5 -1 -6 7 9 1
result – 3 -2 4 -1 5 -6 7 9 1.

void rearrange(int arr[], int n)
{
    // The following few lines are similar to partition process
    // of QuickSort.  The idea is to consider 0 as pivot and
    // divide the array around it.
    int i = -1;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] < 0)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    int pos = i+1, neg = 0;

    while (pos < n && neg < pos && arr[neg] < 0)
    {
        swap(&arr[neg], &arr[pos]);
        pos++;
        neg += 2;
    }
}
 
 
If we want order should be maintained then we need a stable sorting and then do above while only.
