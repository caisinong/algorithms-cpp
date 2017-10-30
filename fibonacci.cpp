#include<iostream>
#include<ctime>
using namespace std;

long long fibonacci_recursive(unsigned int n)
{
	if(n <= 0)
	{
		return 0;
	}
	if(n == 1)
	{
		return 1;
	}

	return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

long long fibonacci_iterative(unsigned int n)
{
	long long f1 = 0;
	long long f2 = 1;
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
	for(int i=2; i<n; i++)
	{
		long long temp = f1 + f2;
		f1 = f2;
		f2 = temp;
	}
	return f1+f2;	
}

int main()
{
	unsigned int n;
	cout << "input a number and press Enter.";
	cin >> n;
	clock_t rstart, rend, istart, iend;
	rstart = clock();
	cout << fibonacci_recursive(n) << endl;
	rend = clock();
	istart = clock();
	cout << fibonacci_iterative(n) << endl;
	iend = clock();
	cout << "time comsuption of recursive method: " << rend - rstart << " miliseconds" <<endl;
	cout << "time comsuption of interative method: " << iend - istart << " miliseconds" <<endl;
}