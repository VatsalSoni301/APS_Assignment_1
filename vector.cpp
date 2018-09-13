//2018201005
#include<iostream>
#include<stdlib.h>
using namespace std;

class vector
{
public:
	int *dynamic_array;
	int tsize,i,currentSize,init;
	vector()		// create vector of 2 size default
	{
		tsize=2;
		currentSize=0;
		init=-1;
		dynamic_array = (int *)malloc(tsize*sizeof(int));
	}
	vector(int noOfElements)	// create vector of a size as per user input
	{
		if(noOfElements>0)
		{
			tsize=noOfElements*2;
			currentSize=noOfElements;
			dynamic_array = (int *)malloc(tsize*sizeof(int));
		}
		else
		{
			cout<<"No of elements cant be zero";
		}
	}
	vector(int noOfElements,int data)	// create vector of a size as per user input and inialized with user data
	{
		if(noOfElements>0)
		{
			tsize=noOfElements*2;
			currentSize=noOfElements;
			dynamic_array = (int *)malloc(tsize*sizeof(int));
			for(i=0;i<currentSize;i++)
				dynamic_array[i]=data;
		}
		else
		{
			cout<<"No of elements cant be zero";
		}
	}
	int insert(int position,int data)	// insert element at given position
	{
		if(position>currentSize || position<0)
		{
			cout<<"Index Out Of Bound";
			return -1;
		}
		else
		{
			init++;
			if((currentSize+1)==tsize)
			{
				tsize=tsize*2;
				dynamic_array=(int*)realloc(dynamic_array,tsize*sizeof(int));
			}
		
			for(i=currentSize;i>=position;i--)
			{
				dynamic_array[i+1]=dynamic_array[i];
			}
			dynamic_array[position]=data;
			currentSize++;
			return 0;
		}
	}
	int push_back(int data)	// insert element at last position
	{
		if(currentSize>100000000)
		{
			cout<<"Segmentation fault";
			return -1;
		}
		else
		{
			init++;
			if((currentSize+1)==tsize)
			{
				tsize=tsize*2;
				dynamic_array=(int*)realloc(dynamic_array,tsize*sizeof(int));
			}
			dynamic_array[currentSize]=data;
			currentSize++;
			return 0;
		}
	}
	int pop_back()	// delete element from last index
	{
		if(init<0)
		{
			cout<<"vector is empty";
			return -1;
		}
		else
		{
			init--;
			currentSize--;
			if((tsize/2)>currentSize)
			{
				tsize=tsize/2;
				dynamic_array=(int*)realloc(dynamic_array,tsize*sizeof(int));
			}
			return 0;
		}
	}
	int front()	// get first element
	{
		if(init<0)
		{
			cout<<"vector is empty";
			return -1;
		}
		else
			return dynamic_array[0];
	}
	int back()	// get last element
	{
		if(init<0)
		{
			cout<<"vector is empty";
			return -1;
		}
		else
			return dynamic_array[currentSize-1];
	}
	int v(int position)	// get element at given position
	{
		if(position>currentSize || position<0)
		{
			cout<<"Index out of bound";
			return -1;
		}
		else
			return dynamic_array[position];
	}
	int erase(int position)	// delete element at given position
	{
		if(position>currentSize || position<0)
		{
			cout<<"Index out of bound";
			return -1;
		}
		else
		{
			init--;
			for(i=position;i<currentSize;i++)
			{
				dynamic_array[i]=dynamic_array[i+1];
			}
			currentSize--;
			if((tsize/2)>currentSize)
			{
				tsize=tsize/2;
				dynamic_array=(int*)realloc(dynamic_array,tsize*sizeof(int));
			}
			return 0;
		}
	}
	int clear()	// clear vector
	{
		tsize=2;
		currentSize=0;
		free(dynamic_array);
		return 0;
	}
	int size()	//get current size of vector
	{
		return currentSize;
	}
	int maxsize()	// get max size of a vector
	{
		return tsize;
	}
	int display()	// display elements of a vector
	{
		//cout<<endl;
		for(i=0;i<currentSize;i++)
		{
			cout<<dynamic_array[i]<<endl;
		}	
	}
};