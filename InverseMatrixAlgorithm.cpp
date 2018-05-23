/*
 * InverseMatrixAlgorithm.cpp
 *
 *  Created on: 22-May-2018
 *      Author: Sahil S
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define N 3


// Here p,q are the indices of A whose cofactor is being returened in temp
void getCofactor(int A[N][N], int temp[N][N], int p, int q, int n)
{
    int i = 0, j = 0;  // these variables are used to iterate and get elements from A

    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];

                // column end reached. row finished. go to new row.
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

//A[N][N] - is the cofactor matrix.
//n is the size of A which is cofactor

int determinant(int A[N][N], int n)
{
    int D = 0; // Initialize result

    //  Base case : if matrix contains single element
    if (n == 1)
        return A[0][0];

    int temp[N][N];

    int sign = 1;
    int f = 0;
    for (f=0; f < n; f++)
    {
        // Getting Cofactor of A[0][f]
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);

		//swapping signs
        sign = -sign;
    }

    return D;
}


//this function finds the adjoint of the matrix and updates it in output param: adj
void adjoint(int A[N][N], int adj[N][N]){
	if(N == 1){
		adj[0][0] = 1;
		return;
	}
	int sign =1,temp[N][N];

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			// this function will return the cofactor of every element in A in temp matrix.
			getCofactor(A,temp,i,j,N);

			// Change sign for even elements (2,4,6,8) to -1 and for odd elements (1,3,5,7,9) to + 1
			sign = ((i+j)%2 == 0)? 1:-1;

			//this function calculates the determinant value of every co-factor, and we ultimately find the transpose
			adj[j][i] = sign * determinant(temp, N-1);
		}
	}
}

bool isInverse(int A[N][N], float inverse[N][N]){
	int det = determinant(A,N);
	if(det == 0){
		cout<<"Singular Matrix";
		return false;
	}
	int adj[N][N];
	adjoint(A,adj);

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			inverse[i][j] = adj[i][j]/float(det);

	return true;
}

template<class T>
void display(T arr[N][N])
{
	for(int i =0;i<N;i++)
	{
		for(int j =0;j<N;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}
int main(){

    int A[N][N] = { {1, 4, 8},
                    {2, 6, 7},
                    {0, 4, 5}};
	//Getting the adjoint matrix = original matrix transpose + then co-facored + changed signs
	int adj[N][N];

	//inverse of a matrix = adj(A)/det(A)
	float inverse[N][N];


	cout<<"The original Matrix is: \n ";
	display(A);


	cout<<"The adjoint of the matrix is: \n";
	adjoint(A,adj);
	display(adj);


	cout<<"The inverse of the matrix is: \n";
	if(isInverse(A,inverse))
		display(inverse);

	return 0;
}


