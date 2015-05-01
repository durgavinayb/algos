#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string.h>

using namespace std;

int binary_search(int A[], int L[], int maxSize, int value)
{
	int lo =0, hi = maxSize, mid ;

	while(lo < hi)
	{
		mid = (hi + lo)/2;

		if(L[mid] > value)
			hi = mid;
		else if(L[mid] < value)
			lo = mid +1;
		else return mid;
	}
	return lo;
}

int main()
{
		int n, i, maxSize,  value;
		cin>>n;
		int A[n], L[n];
		memset(A, 0, sizeof(A));
		memset(L, -1, sizeof(A));

		for(i=0; i<n; i++)
			cin>>A[i];

		maxSize = 1;
		L[0] = -1;
		L[1] = A[0];
		for(i=1; i<n; i++)
		{
			if(A[i] > L[maxSize])
			{
				maxSize++;
				L[maxSize] = A[i];
			}
			else
			{
				int posi = binary_search(A, L, maxSize, A[i]);
				L[posi] = A[i];
			}
		}

	cout<<maxSize<<endl;
}