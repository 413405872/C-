#include<iostream>
#include"Sort_Algorithm.h"
using namespace std;

void Test_Sort()
{
	Sort_Algorithm<int> sa;
	sa.Bubble_Sort();//ð������
	sa.Insert_Sort();//��������
	sa.Select_Sort();//ѡ������
	sa.Shell_Sort();//ϣ������
	sa.Quick_Sort();//��������
	sa.Merge_Sort();//�鲢����
	sa.Heap_Sort();//������
}

int main()
{
	Test_Sort();
	return 0;
}
