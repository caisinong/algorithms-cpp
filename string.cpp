#include <iostream>
#include <string>

void swap(char* s, int a, int b)
{
	int length = strlen(s);
	if(s != nullptr && a > 0 && b > 0 && a < length-1 && b < length-1)
	{
		char tmp = s[a];
		s[a] = s[b];
		s[b] = tmp;
	}
}

void ReverseString(char* s, int from, int to)
{
	if(s == nullptr || from >= to)
		return;
	while(from < to)
	{
		char t = s[from];
		s[from++] = s[to];
		s[to--] = t;
	}
}

void LeftRotate(char* s, int n)
//rotate string s to the left
//eg. s='abcdef', n='2', should return 'cdefab'
{
	if(s == nullptr || n == 0)
		return;

	int length = strlen(s);

	if(n < 0)
	{
		n = -(n%length) + length;
	}
	else
		n = n % length;
	ReverseString(s, 0, n-1);
	ReverseString(s, n, length-1);
	ReverseString(s, 0, length-1);
}

void ReverseSentence(char *s)
//Given a sentence e.g. I love you.
//Return: you. love I
{
	if(s == nullptr)
		return;
	int i = 0, j = 0, length = strlen(s);
	while(j < length)
	{
		if(s[j] == ' ' && j - i > 1)
		{
			ReverseString(s, i, j-1);
			i = j + 1;
		}
		j++;
	}
	if(length - i > 2)
	{
		ReverseString(s, i, length-1);
	}
	ReverseString(s, 0, length-1);
}

void LongestCommonSubsequence(char* s1, char* s2)
{
	const int length_s1 = strlen(s1);
	const int length_s2 = strlen(s2);
	int r[length_s1+1][length_s2+1];
	for(int i = 0; i < length_s1 + 1; i++)
	{
		for(int j = 0; j < length_s2 + 1; j++)
		{
			if(i == 0 || j == 0)
				r[i][j] = 0;
			else
				if(s1[i-1] == s2[j-1])
					r[i][j] = r[i-1][j-1] + 1;
				else
					r[i][j] = r[i-1][j] > r[i][j-1] ? r[i-1][j] : r[i][j-1];
		}
	}
	for(int i = 0; i < length_s1 + 1; i++)
	{
		for(int j = 0; j < length_s2 + 1; j++)
		{
			std::cout << r[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	int i = length_s1;
	int j = length_s2;
	int lengthOfLCS = r[i][j];
	char LCS[lengthOfLCS+1];
	LCS[lengthOfLCS] = '\0';
	int k = lengthOfLCS - 1;
	while(i != 0 && j != 0)
	{
		if(r[i][j] > r[i-1][j] && r[i][j] > r[i][j-1])
		{
			LCS[k] = s2[j-1];
			i--;
			j--;
			k--;
		}
		else if(r[i-1][j] > r[i][j-1])
		{
			i--;
		}
		else
			j--;
	}
	std::cout << "The Longest Common Subsequence is:" << std::endl;
	std::cout << LCS << std::endl;

}

void Permutation(char* s, int start)
{
	using namespace std;
	//print all permutations of a string.
	int length = strlen(s);
	if(s == nullptr || start < 0)
	{
		return;
	}
	if(length - start == 1)
	{
		cout << s << endl;
		return;
	}
	for(int i = start; i < length; i++)
	{
		swap(s[i], s[start]);
		Permutation(s, start+1);
		swap(s[i], s[start]); 
	}
}

void Permutation_iterative(int* s)
{
	 
}
int main()
{
	using namespace std;
	char s[]= "Fuck you";
	LeftRotate(s, 3);
	cout << s << endl;
	char sent[] = "Fuck you leather man!";
	ReverseSentence(sent);
	cout << sent << endl;
	char s1[] = "Fuck you leather man!";
	char s2[] = "Me fuck leather mann.";
	LongestCommonSubsequence(s1, s2);
	char s3[] = "ABCDEFGHIJK";
	Permutation(s3, 0);
}