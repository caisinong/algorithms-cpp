#include <iostream>
#include <string>


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
	int i = length_s1 + 1;
	int j = length_s2 + 1;
	int lengthOfLCS = r[i][j];
	char LCS[lengthOfLCS];
	char *p_LCS = &LCS[0];
	while(i != 0 && j != 0)
	{
		if(r[i][j] > r[i-1][j] && r[i][j] > r[i][j-1])
		{
			*p_LCS = s1[i];
			i--;
			j--;
			p_LCS++;
		}
		else
		{
			j--;
		}
	}
	ReverseString(LCS, 0, lengthOfLCS - 1);
	std::cout << "The Longest Common Subsequence is:" << std::endl;
	std::cout << LCS << std::endl;

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
	char s1[] = "ABCBDAB";
	char s2[] = "BDCABA";
	LongestCommonSubsequence(s1, s2);
}