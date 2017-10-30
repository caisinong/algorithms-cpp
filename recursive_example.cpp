#include<iostream>

int main()
{
	void binary(int i);
	int n = 4267;
	binary(n);
}

void binary(int m)
{
	int p;
	p = m/10;
	if(p != 0)
	{
		binary(p);
	}
	std::cout << m%10 << std::endl;
}