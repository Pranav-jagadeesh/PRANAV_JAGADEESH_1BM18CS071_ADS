#include <iostream>
using namespace std;
int main() 
{
        int T,N,a[100],i,j,temp;
        cout<<"Enter number of test cases:";
    cin>>T;//test cases
    while(T!=0)
    {
        cout<<"Enter number of elements:";
		cin>>N;
		cout<<"Enter array elements:";
        for(i=0;i<N;i++)
        {
            cin>>a[i];
        }
         temp=0;
        for(i=0;i<N-1;i++) // 18 -29 descending order.
        {
            for(j=i+1;j<N;j++)
            {
                if(a[i]<a[j])
                {
                    temp=a[j];
                    a[j]=a[i];
                    a[i]=temp;
                }
            }
        }
        for(i=N-1;i>1;i--)
        {
            cout<<a[i];
            cout<<" ";
        }
        cout<<endl;
    T--;    
    }
	return 0;
}

