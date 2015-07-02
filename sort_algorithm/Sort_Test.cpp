#include<iostream>
#include"Sort_Algorithm.h"
using namespace std;

void Test_Sort()
{
	Sort_Algorithm<int> sa;
	sa.Bubble_Sort();//√∞≈›≈≈–Ú
	sa.Insert_Sort();//≤Â»Î≈≈–Ú
	sa.Select_Sort();//—°‘Ò≈≈–Ú
	sa.Shell_Sort();//œ£∂˚≈≈–Ú
	sa.Quick_Sort();//øÏÀŸ≈≈–Ú
	sa.Merge_Sort();//πÈ≤¢≈≈–Ú
	sa.Heap_Sort();//∂—≈≈–Ú
}

int main()
{
	Test_Sort();
	return 0;
}
