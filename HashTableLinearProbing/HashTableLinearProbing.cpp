// HashTableLinearProbing.cpp 


#include <iostream>
#define sh 20


using namespace std;


int Hash(int key)
{
	return key % sh;
}


int linearProbing(int ht[],int i)
{
	int k = 1;
	while (ht[(i +k )%sh] != 0)
		k++;
	return (i + k) % sh;
}


void insert(int ht[], int key)
{
	int i = Hash(key);

	if (ht[i] != 0)
	{
		i=linearProbing(ht, i);
	}
	ht[i] = key;
}


int search(int ht[], int key)
{
	int i = Hash(key);
	int k = 0;

	while(ht[(i+k)%sh]!=key)
	{
		k++;

		if (ht[(i + k) % sh] == 0)
			return -1;

	}

	return (i + k) % sh;

}


int main()
{
   //hash table 
	int ht[20] ={0};

	int a[] = { 26, 30, 45, 23, 25, 43, 74, 19, 29 };
	int n = sizeof(a) / sizeof(a[0]);

	//Insertion
	for (int i = 0;i < n;i++)
		insert(ht, a[i]);

	//Searching
	search(ht,25);




}
