#include<iostream>
#include<algorithm>//array is almost same in c and cpp therefore this code is sufficient for both
using namespace std;
struct myArray{
	int total_size;
	int used_size;
	int* ptr;
};
void create_array(struct myArray* a, int tsize, int usize)
{
	a->total_size = tsize;
	a->used_size = usize;
	a->ptr = new int [tsize];
}
void set_values(struct myArray* a)
{
	cout << "Enter the values of array: ";
	for(int i=0;i<a->used_size;i++)
	{
		cin >> *(a->ptr + i); 
	}
}
void print_values(struct myArray a)
{
	cout << "The values stored in array are: ";
	for(int i=0;i<a.used_size;i++)
	{
		cout << *(a.ptr + i) <<" ";
	}
	cout<<"\n";
}
void insert_in_array(struct myArray* a,int num,int position)
{
	int i;
	for(i = (a->used_size)-1 ; i>=position ; i--)
	{
		*(a->ptr + i + 1) = *(a->ptr + i);
	}
	*(a->ptr + i + 1) = num;
	++(a->used_size);
}
void delete_in_array(struct myArray* a,int position)
{
	for(int i=position;i<(a->used_size)-1;i++)
	{
		*(a->ptr + i) = *(a->ptr + i + 1);
	}
	--(a->used_size);
}
void linear_search(struct myArray a, int num)
{
	for(int i=0;i<a.used_size;i++)
	{
		if(*(a.ptr + i) == num)
		{
			cout << "Found at " << i <<" position";
			return;
		}
	}
	cout << "Not Found";
}
void sort(struct myArray* a)
{
	int n = a->used_size;
	sort(a->ptr,a->ptr + n);
}
void binary_search(struct myArray a, int key)
{
	int start=0,last=a.used_size,mid;
	while(start<=last)
	{
		mid = (last - start)/2  + start;
		if(*(a.ptr + mid) == key)
		{
			cout << "Found at " << mid << " postion";
			return;
		}
		else if( key > *(a.ptr + mid))
		{
			start = mid+1;
		}
		else
		last = mid-1;
	}
	cout << "Not found";
}
int main(){
	struct myArray a;
	int totalsize,usedsize;
	cout << "Enter the total size and size you want to use for array: ";
	cin >> totalsize >> usedsize;
	create_array(&a,totalsize,usedsize);
	set_values(&a);
	print_values(a);
	
	int num,position;
	
	cout << "Enter the value and position for insertion: ";
	cin >> num >>position;
	insert_in_array(&a,num,position);
	
	print_values(a);
	
	cout << "Enter the position for deletion: ";
	cin >>position;
	delete_in_array(&a,position);
	
	print_values(a);
	
	cout << "Enter the value for linear searching: ";
	cin >> num;
	linear_search(a,num);
	
	cout << "\nnow sorting\n";
	sort(&a);
	print_values(a);
	
	cout << "Enter the value for binary searching: ";
	cin >> num;
	binary_search(a,num);
	
	delete(a.ptr);
	return 0;
}
/*
Output:
Enter the total size and size you want to use for array: 10 5
Enter the values of array: 5 4 3 2 1
The values stored in array are: 5 4 3 2 1
Enter the value and position for insertion: 12 1
The values stored in array are: 5 12 4 3 2 1
Enter the position for deletion: 3
The values stored in array are: 5 12 4 2 1
Enter the value for linear searching: 4
Found at 2 position
now sorting
The values stored in array are: 1 2 4 5 12
Enter the value for binary searching: 12
Found at 4 postion
*/
