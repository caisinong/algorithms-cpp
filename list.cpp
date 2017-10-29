#include <iostream>
#include <string>
#include <stack>

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

void AddToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	if(*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode *pNode = *pHead;

		while(pNode->m_pNext != nullptr)
		{
			pNode = pNode->m_pNext;
		}

		pNode->m_pNext = pNew;
	}
}

void RemoveNode(ListNode** pHead, int value)
{
	if(pHead == nullptr || *pHead == nullptr)
		return;
	ListNode* pToBeDeleted = nullptr;
	if((*pHead) -> m_nValue == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode* pNode = *pHead;
		while(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;
		if(pNode->m_pNext != nullptr && pNode -> m_pNext ->m_nValue == value)
		{
			pToBeDeleted = pNode -> m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if(pToBeDeleted != nullptr)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

void PrintList(ListNode* pHead)
{
	std::string arrow = "->";
	if(pHead == nullptr)
		return;
	ListNode* pNode = pHead;
	while(pNode->m_pNext != nullptr)
	{
		pNode = pNode->m_pNext;
		std::cout << pNode->m_nValue;
		if(pNode->m_pNext != nullptr)
			std::cout << arrow;
	}
	std::cout << std::endl;
}

void ReversePrint_Iteratively(ListNode* pHead)
{
	char* arrow[2];
	*arrow = "->";
	std::stack<ListNode*>nodes;
	ListNode* pNode = pHead;
	while(pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while(!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d%s", pNode->m_nValue, arrow);
		nodes.pop();
	}
}

void ReversePrint_Recursively(ListNode* pHead)
{	
	char* arrow[2];
	*arrow = "->";
	if(pHead != nullptr)
	{
		if (pHead->m_pNext != nullptr)
		{
			ReversePrint_Recursively(pHead->m_pNext);
		}
		printf("%d%s", pHead->m_nValue, arrow);
	}
}
int main()
{
	using namespace std;
	ListNode* pHead = new ListNode();
	pHead->m_nValue = 0;
	pHead->m_pNext = nullptr;
	ListNode* pNode = pHead;
	for(int i=0;i<10;i++)
	{
		ListNode* pNew = new ListNode();
		pNew->m_nValue = i;
		pNew->m_pNext = nullptr;
		pNode->m_pNext = pNew;
		pNode = pNode->m_pNext;
	}
	PrintList(pHead);
	AddToTail(&pHead, 18);
	PrintList(pHead);
	RemoveNode(&pHead, 4);
	PrintList(pHead);
	ReversePrint_Iteratively(pHead);
	cout << endl;
	ReversePrint_Recursively(pHead);
}