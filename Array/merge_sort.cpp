#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &a,int left,int mid,int right)
{
	int size1,size2;
	size1=(mid-left)+1;
	size2=(right-(mid+1))+1;
	int* a1 = new int[size1];
	int* a2 = new int[size2];
	for(int i=0;i<size1;i++)
	{
		a1[i]=a[left+i];
	}
	for(int j=0;j<size1;j++)
	{
		a2[j]=a[mid+1+j];
	}
	int ind1=0,ind2=0,indM=left;
	while(ind1<size1 && ind2<size2)
	{
		if(a1[ind1]<=a2[ind2]){
			a[indM]=a1[ind1];
			++ind1;
		}
		else{
			a[indM]=a2[ind2];
	    	++ind2;
		}
		++indM;
	}
	
	while(ind1<size1)
	{
		a[indM]=a1[ind1];
		++ind1;
		++indM;
	}
	while(ind2<size2)
	{
		a[indM]=a2[ind2];
		++ind2;
		++indM;
	}
	delete[]a1;
	a1=NULL;
	delete[]a2;
	a2=NULL;
}
void mergesort(vector<int> &a,int left,int right)
{
	if(left>=right)
	return;
	
	int mid=left+((right-left)/2);
	mergesort(a,left,mid);
	mergesort(a,mid+1,right);
	merge(a,left,mid,right);
	
}
int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	mergesort(a,0,a.size()-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}