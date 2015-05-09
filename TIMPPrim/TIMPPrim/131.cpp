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
	*@brief Алгоритм Прима — алгоритм построения минимального остовного дерева взвешенного связного неориентированного графа. 
	Алгоритм впервые был открыт в 1930 году чешским математиком Войцехом Ярником, позже переоткрыт Робертом Примом в 1957 году, и, независимо от них, Э. Дейкстрой в 1959 году.
*/
void main()
{
	int N;
	cout<<"Vvedite kolichestvo uzlov: "; cin>>N;
	int **A=new int* [N];/// int **A=new int* [N] Массив расстояний между вершинами
	for(int i=0;i<N;i++)
	{
		A[i]=new int[N];
	}
	int *Visit=new int [N];/// int *Visit=new int [N] Массив для посещённых рёбер, 1-да 0-нет
	cout<<"Ispolzuetsa svjaznij neorientirovannij graf"<<endl;
	cout<<"Vvedite matrizu smejnosti:"<<endl;
	cout<<"Primechanie: esli net rebra mejdu vershinami to vvedite 0"<<endl;
	for(int i=0;i<N;i++)/// for(int i=0;i<N;i++) Цикл ввода расстояний
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
	for(int i=0;i<N;i++)/// Делаем так, что все вершины не посещены
	{
		Visit[i]=0;
	}
	Visit[0]=1;/// Visit[0]=1 Начальное ребро 1 для посещения
	int a,a1,b,b1,index1=0,index2=1,mincost=0,min;
	while(index2!=N)/// while(index2!=N) Цикл поиска минимальных рёбер и подсчёта стоимости получившегося минимального остовного дерева. Цикл работает, пока все вершины не будут посещены
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
		/// На выходе имеем минимальное ребро
		if(Visit[a]==0 || Visit[b]==0)/// if(Visit[a]==0 || Visit[b]==0) Выполняем проверку
		{
		cout<<"Minimalnoe rebro mejdu "<<++a1<<" i "<<++b1<<" : "<<min<<endl;
		Visit[b]=1;/// Visit[b]=1 Отмечаем посещённое ребро
		index2++;
		mincost+=min;
		}
		A[a][b]=A[b][a]=INT_MAX;/// A[a][b]=A[b][a]=INT_MAX Исключаем просмотренный путь, методом присвоения ему INT_MAX
	}
	cout<<"Minimalnaja stoimost poluchivchegosa ostovnogo dereva: "<<mincost;
	return;
}

