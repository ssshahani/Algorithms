#include <iostream>
using namespace std;
#define dim1 3 		//Macro Dimension 1
#define dim2 3		//Macro Dimension 2

// this function transposes the matrix - pass by pointers, takes in the dimensions
void transpose(int *arr, int d1, int d2){
	int *tmp =new int[d1*d2]; // tmp to take all elements of multi-dimensional array

	//copying all array elements into temp
	for(int i=0;i<d1*d2;i++)
		tmp[i] = arr[i];

	// performing transpose
	int idx = 0;
	for(int i=0;i<d2;i++)
		for(int j=0;j<d1;j++)
		arr[idx++] = tmp[i+d2*j];

	delete[] tmp; //delete from heap
	tmp = NULL;	  // so that it is not dangling
}
int main(){
	//int a[dim1][dim2] = {{1,5},{6,8},{2,9},{4,0}};
	int a[dim1][dim2] = {{1,2,3},{4,5,6},{7,8,9}};
	int *p = &a[0][0]; //pointer points to the first element in two dimensional array
/*
	cout <<" Before Transpose elements are ";
	for(int i=0;i<8;i++)
		cout<<*(p+i)<<" ";
*/

	cout<<"Before Matrix Transpose :"<<endl;
	int i=-1;
	for(int j=0;j<dim1;j++){
		for(int k=0;k<dim2;k++)
			cout<<p[++i]<<" ";
		cout<<endl;
	}
	// transpose function call
	transpose(p,dim1,dim2);

	cout<<"After Matrix Transpose :"<<endl;
	i=-1;
	for(int j=0;j<dim2;j++){
		for(int k=0;k<dim1;k++)
			cout<<p[++i]<<" ";
		cout<<endl;
	}
	return 0;
}
