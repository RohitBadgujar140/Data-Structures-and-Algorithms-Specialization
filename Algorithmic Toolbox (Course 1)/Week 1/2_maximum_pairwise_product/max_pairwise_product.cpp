#include<iostream>
using namespace std;
#include <vector>
#include <cstdlib>

long long maxpairwiseproduct(const vector<int>& array)
{
	long long result=0;
	int n=array.size();

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if( ((long long) array[i]*array[j]) > result)
			{
				result = ((long long) array[i]*array[j]);
			}
		}
	}
	return result;
}
long long maxpairwiseproductFast(const vector<int>& array)
{
	  int n = array.size();

	  int max_index1=-1;
	  for(int i=0;i<n;i++)
		  if((max_index1 == -1) || (array[i]>array[max_index1]))
			  max_index1 = i;

	  int max_index2=-1;
      for(int j=0;j<n;j++)
	 if((j != max_index1) && ((max_index2 == -1) || (array[j]>array[max_index2])))
		 max_index2 = j;

      //cout<<max_index1<<' '<<max_index2<<"\n";

      return ( (long long) (array[max_index1]) * (array[max_index2]) );
}
int main(int argc, char **argv) {
    // Stress Management
	while(true)
	{
		int n = rand()%1000 + 2;
		cout<<n<<"\n";
		vector<int> a;
		for(int i=0;i<n;i++)
		{
			a.push_back( rand()%100000 );
		}
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<' ';
		}
		cout<<"\n";

		long long res1 = maxpairwiseproduct(a);
		long long res2 = maxpairwiseproductFast(a);

		if(res1 != res2)
		{
				cout<<"Wrong Answer: "<<res1<<' '<<res2<<"\n";
				break;
		}
		else{
			cout<<"Ok\n";
		}
	}

	int n;
	cin>>n;

	vector<int> array(n);
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}

	long long result = maxpairwiseproductFast(array);
	cout<<result<<"\n";
	return 0;
}
