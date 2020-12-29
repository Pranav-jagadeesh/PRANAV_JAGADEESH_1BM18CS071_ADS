#include<bits/stdc++.h> 
using namespace std; 

void uniqueNumbers(int l, int r) 
{ 

	for (int i=l ; i<=r ; i++) 
	{ 
		int num = i; 
		bool visited[10] = {false}; 

		while (num) 
		{ 

			if (visited[num % 10]) 
				break; 

			visited[num%10] = true; 

			num = num/10; 
		} 

		if (num == 0) 
			cout << i << " "; 
	} 
} 

int main() 
{ 
	int l=0,r=0; 
	cout<<"Enter value of L:\n";
	cin>>l;
	cout<<"Enter value of R:\n";
	cin>>r;
	uniqueNumbers(l, r); 
	return 0; 
}

