/**
   *@file 131.cpp
   *@version 0.1
   *@date 09.0515
   *@title Release algoritym Prima
   */
#include<conio.h>
#include<iostream>
using namespace std;
/**
	*@brief �������� ����� � �������� ���������� ������������ ��������� ������ ����������� �������� ������������������ �����. 
	�������� ������� ��� ������ � 1930 ���� ������� ����������� �������� �������, ����� ���������� �������� ������ � 1957 ����, �, ���������� �� ���, �. ��������� � 1959 ����.
*/
void main()
{
	int N;
	cout<<"Vvedite kolichestvo uzlov: "; cin>>N;
	int **A=new int* [N];/// int **A=new int* [N] ������ ���������� ����� ���������
	for(int i=0;i<N;i++)
	{
		A[i]=new int[N];
	}
	int *Visit=new int [N];/// int *Visit=new int [N] ������ ��� ���������� ����, 1-�� 0-���
	cout<<"Ispolzuetsa svjaznij neorientirovannij graf"<<endl;
	cout<<"Vvedite matrizu smejnosti:"<<endl;
	cout<<"Primechanie: esli net rebra mejdu vershinami to vvedite 0"<<endl;
	for(int i=0;i<N;i++)/// for(int i=0;i<N;i++) ���� ����� ����������
	{
		for(int j=0;j<N;j++)
		{
			if(i==j)
			{
				A[i][j]=0;
			}
			if(i<j)
			{
			cout<<"Rasstojanie ot "<<i+1<<" do "<<j+1<<": ";
			cin>>A[i][j];
			A[j][i]=A[i][j];
			}
		}
	} 
	cout<<"Poluchivsheesja matriza smejnosti"<<endl;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<A[i][j]<<" ";
			if(A[i][j]==0)
			{
				A[i][j]=INT_MAX;
			}
		}
		cout<<endl;
	}
	for(int i=0;i<N;i++)/// ������ ���, ��� ��� ������� �� ��������
	{
		Visit[i]=0;
	}
	Visit[0]=1;/// Visit[0]=1 ��������� ����� 1 ��� ���������
	int a,a1,b,b1,index1=0,index2=1,mincost=0,min;
	while(index2!=N)/// while(index2!=N) ���� ������ ����������� ���� � �������� ��������� ������������� ������������ ��������� ������. ���� ��������, ���� ��� ������� �� ����� ��������
	{
		min=INT_MAX;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(A[i][j]<min)
				{
					if(Visit[i]!=0)
						{
							min=A[i][j];
							a=a1=i;
							b=b1=j;
						}
				}
			}
		}
		/// �� ������ ����� ����������� �����
		if(Visit[a]==0 || Visit[b]==0)/// if(Visit[a]==0 || Visit[b]==0) ��������� ��������
		{
		cout<<"Minimalnoe rebro mejdu "<<++a1<<" i "<<++b1<<" : "<<min<<endl;
		Visit[b]=1;/// Visit[b]=1 �������� ���������� �����
		index2++;
		mincost+=min;
		}
		A[a][b]=A[b][a]=INT_MAX;/// A[a][b]=A[b][a]=INT_MAX ��������� ������������� ����, ������� ���������� ��� INT_MAX
	}
	cout<<"Minimalnaja stoimost poluchivchegosa ostovnogo dereva: "<<mincost;
	return;
}

