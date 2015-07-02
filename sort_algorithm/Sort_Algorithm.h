#include<iostream>
using namespace std;

template<class T>
class Sort_Algorithm{
public:
	Sort_Algorithm():sort_Array(NULL),length(0)
	{}
	
	void Bubble_Sort();//ð������
	
	void Insert_Sort();//��������
	
	void Select_Sort();//ѡ������
	
	void Shell_Sort();//ϣ������
	
	void Quick_Sort();//��������

	void Merge_Sort();//�鲢����

	void Heap_Sort();//������
private:
	void creat();//����һ������
	void Print();//��ӡ����������
	void destroy();//��������

	void Quick_Sort(int,int);//���ڿ�������
	int Partition(int start,int end);
	
	void Merge_Sort(T temp[],int l,int r);//���ڹ鲢����
	void Merge_Array(T temp[],int l,int m,int r);
	
	void Build_Heap(int i,int size);//���ڶ�����

private:
	T *sort_Array;
	int length;//����ĳ���
};

template<class T>
void Sort_Algorithm<T>::creat()
{
	cout<<"������Ҫ��������ݸ���:"<<endl;
	cin>>length;
	while(length<=0)
	{
		cout<<"���볤������,����������";
		cin>>length;
	}
	sort_Array=new T[length];
	cout<<"�����������"<<endl;
	for(int i=0;i<length;i++)
		cin>>sort_Array[i];
}

template<class T>
void Sort_Algorithm<T>::Print()
{
	for(int i=0;i<length;i++)
		cout<<sort_Array[i]<<"  ";
	cout<<endl<<endl<<endl;
}

template<class T>
void Sort_Algorithm<T>::destroy()
{
	delete [] sort_Array;
}

template<class T>
void Sort_Algorithm<T>::Bubble_Sort()
{
	creat();//�����Ҫ����һ������Ĳ��Ҳ������ݵģ�
	bool isSorted=false;
	for(int i=0;i<length-1&&!isSorted;i++)
	{
		isSorted=true;
		for(int j=0;j<length-1-i;j++)
		{
			if(sort_Array[j]>sort_Array[j+1])
			{
				isSorted=false;
				swap(sort_Array[j],sort_Array[j+1]);
			}
		}
	}
	cout<<"ð������Ľ��Ϊ��"<<endl;
	Print();//��ӡ���
	destroy();//��������
}

template<class T>
void Sort_Algorithm<T>::Insert_Sort()
{
	creat();
	int key;
	for(int i=1;i<length;i++)
	{
		key=sort_Array[i];
		int j=i-1;
		while(j>=0&&sort_Array[j]>key)//���������һ��ֵ������Ľ��бȽ�
		{
			sort_Array[j+1]=sort_Array[j];
			j--;
		}
		sort_Array[j+1]=key;
	}
	cout<<"��������Ľ��Ϊ��"<<endl;
	Print();//��ӡ���
	destroy();//��������
}

template<class T>
void Sort_Algorithm<T>::Select_Sort()
{
	creat();
	for(int i=0;i<length-1;i++)
	{
		int index=i;
		for(int j=i+1;j<length;j++)//ÿһ���ҳ���С�������±�
		{
			if(sort_Array[j]<sort_Array[index])
				index=j;
		}
		swap(sort_Array[i],sort_Array[index]);
	}
	cout<<"ѡ������Ľ��Ϊ��"<<endl;
	Print();//��ӡ���
	destroy();//��������
}

template<class T>
void Sort_Algorithm<T>::Shell_Sort()
{
	creat();
	for(int gap=length/2;gap>0;gap/=2)//���������gap�Ľ��
	{
		for(int i=gap;i<length;i++)
		{
			for(int j=i-gap;j>=0;j-=gap)
			{
				if(sort_Array[j+gap]<sort_Array[j])
					swap(sort_Array[j+gap],sort_Array[j]);
			}
		}
	}
	cout<<"ϣ������Ľ��Ϊ��"<<endl;
	Print();//��ӡ���
	destroy();//��������
}

template<class T>
void Sort_Algorithm<T>::Quick_Sort()
{
	creat();
	Quick_Sort(0,length-1);
	cout<<"��������Ľ��Ϊ��"<<endl;
	Print();//��ӡ���
	destroy();//��������
}

template<class T>
void Sort_Algorithm<T>::Quick_Sort(int start,int end)
{
	if(start>=end)
		return ;
	int pivot=Partition(start,end);
	Quick_Sort(start,pivot-1);
	Quick_Sort(pivot+1,end);
}

template<class T>
int Sort_Algorithm<T>::Partition(int start,int end)
{
	T temp=sort_Array[start];
	while(start<end)
	{
		while(start<end&&sort_Array[end]>temp)
			end--;
		if(start==end)//���һ��Ҫ��
			break;
		sort_Array[start++]=sort_Array[end];
		while(start<end&&sort_Array[start]<temp)
			start++;
		if(start==end)
			break;
		sort_Array[end--]=sort_Array[start];
	}
	sort_Array[start]=temp;
	return start;
}

template<class T>
void Sort_Algorithm<T>::Merge_Sort()
{
	creat();
	T *temp=new T[length];
	Merge_Sort(temp,0,length-1);
	delete [] temp;
	cout<<"�鲢����Ľ��Ϊ��"<<endl;
	Print();//��ӡ���
	destroy();//��������
}

template<class T>
void Sort_Algorithm<T>::Merge_Sort(T temp[],int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		Merge_Sort(temp,l,mid);
		Merge_Sort(temp,mid+1,r);
		Merge_Array(temp,l,mid,r);//�ϲ���������
	}
}

template<class T>
void Sort_Algorithm<T>::Merge_Array(T temp[],int l,int m,int r)
{
	int left=l;
	int mid=m;
	int mid1=m+1;
	int right=r;
	int count=0;
	while(left<=mid&&mid1<=right)
	{
		if(sort_Array[left]<sort_Array[mid1])
		{
			temp[count++]=sort_Array[left++];
		}
		else
		{
			temp[count++]=sort_Array[mid1++];
		}
	}
	while(left<=mid)
		temp[count++]=sort_Array[left++];
	while(mid1<=right)
		temp[count++]=sort_Array[mid1++];
	for(int i=0;i<count;i++)
		sort_Array[i+l]=temp[i];
}

template<class T>
void Sort_Algorithm<T>::Heap_Sort()
{
	creat();
	for(int i=length/2;i>=0;i--)//����
		Build_Heap(i,length);
	for(int i=0;i<length;i++)
		cout<<sort_Array[i]<<"  ";
	cout<<endl<<endl<<endl;
	for(int j=length-1;j>0;j--)
	{
		swap(sort_Array[0],sort_Array[j]);//ÿ�������ĵ�����βȥ
		Build_Heap(0,j);
		for(int i=0;i<length;i++)
			cout<<sort_Array[i]<<"  ";
		cout<<endl<<endl<<endl;
	}
	cout<<"������Ľ��Ϊ��"<<endl;
	Print();//��ӡ���
	destroy();//��������
}

template<class T>
void Sort_Algorithm<T>::Build_Heap(int i,int size)
{
	T temp=sort_Array[i];//����Ǹ���
	int child;
	for(;i*2<size;i=child)
	{
		child=i*2+1;//����
		if(child<size-1&&sort_Array[child+1]>sort_Array[child])
			child++;//�ҳ���������������
		if(child<size&&sort_Array[child]>temp)
			sort_Array[i]=sort_Array[child];//�����Ķ��ӱȸ��״��ǽ���
		else
			break;
	}
	sort_Array[i]=temp;
}
