#include<iostream>
using namespace std;
//2016����������ѧ������������ַhttp://cg.hrbust.edu.cn
//�ύ����ʱ�䣺12��11��ǰÿ��8:00-20:00
//ѡ�����庯��
#include "usercode.h"
//int player(int board[19][19])
//{
//	int m,n;
//	for(m=0;m<=18;m++)
//		for(n=0;n<=18;n++)
//			if(board[m][n]==0)
//				return m*100+n;
//	return -1;
//}
//�˹����庯��
int demo(int board[19][19])
{
	int i,j,k,m,n,max;
	double vmap[19][19]={0};
	int mycolor=0;
	for(i=0;i<=18;i++)
		for(j=0;j<=18;j++)
		{
			if(board[i][j]!=0)
				vmap[i][j]=-9999;
			else
			{
				//������
				for(k=1;k<=4 && j-k>=0;k++)
					if(board[i][j-k]!=0 && board[i][j-k]%2!=mycolor)//�Է�������������
						vmap[i][j]+=1.0*k;
					else
						break;
				//���Ҽ��
				for(k=1;k<=4 && j+k<=18;k++)
					if(board[i][j+k]!=0 && board[i][j+k]%2!=mycolor)//�Է�������������
						vmap[i][j]+=1.0*k;
					else
						break;
				//���ϼ��
				for(k=1;k<=4 && i-k>=0;k++)
					if(board[i-k][j]!=0 && board[i-k][j]%2!=mycolor)//�Է�������������
						vmap[i][j]+=1.0*k;
					else
						break;
				//���¼��
				for(k=1;k<=4 && i+k<=18;k++)
					if(board[i+k][j]!=0 && board[i+k][j]%2!=mycolor)//�Է�������������
						vmap[i][j]+=1.0*k;
					else
						break;
				//�����ϼ��
				for(k=1;k<=4 && j-k>=0 && i-k>=0;k++)
					if(board[i-k][j-k]!=0 && board[i-k][j-k]%2!=mycolor)//�Է�������������
						vmap[i][j]+=1.0*k;
					else
						break;
				//�����¼��
				for(k=1;k<=4 && j-k>=0 && i+k<=18;k++)
					if(board[i+k][j-k]!=0 && board[i+k][j-k]%2!=mycolor)//�Է�������������
						vmap[i][j]+=1.0*k;
					else
						break;
				//�����ϼ��
				for(k=1;k<=4 && j+k<=18 && i-k>=0;k++)
					if(board[i-k][j+k]!=0 && board[i-k][j+k]%2!=mycolor)//�Է�������������
						vmap[i][j]+=1.0*k;
					else
						break;
				//�����¼��
				for(k=1;k<=4 && j+k<=18 && i+k<=18;k++)
					if(board[i+k][j+k]!=0 && board[i+k][j+k]%2!=mycolor)//�Է�������������
						vmap[i][j]+=1.0*k;
					else
						break;

			}

		}
	m=-1;
	n=-1;
	max=-9999;
	for(i=0;i<=18;i++)
		for(j=0;j<=18;j++)
			if(vmap[i][j]>max)
			{
				max=vmap[i][j];
				m=i;
				n=j;
			}
	if(m>=0)
		return m*100+n;
	else
		return -1;
}
//��ʾ���̺���
void showboard(int board[19][19])
{
	int i,j;
	cout<<endl;
	cout<<"  ";
	for(j=0;j<=18;j++)
		if(j<10)
			cout<<j<<" ";
		else
			cout<<j;
	cout<<endl;
	for(i=0;i<=18;i++)
	{
		if(i<10)
			cout<<" "<<i;
		else
			cout<<i;

		for(j=0;j<=18;j++)
		{
			if(board[i][j]==0)
				cout<<"+ ";
			else
				if(board[i][j]%2==1)
					cout<<"@ ";
				else
					cout<<"X ";
		}
		cout<<endl;
	}
	cout<<endl;
}
//��������
int checkerror(int board[19][19],int stepmn)
{
	int m,n;
	m=stepmn/100;
	n=stepmn%100;
	if(m<0)
		return 1;
	if(n<0)
		return 1;
	if(m>=19)
		return 1;
	if(n>=19)
		return 1;

	if(board[m][n]!=0)
		return 1;
	else
		return 0;
}
//���ʤ������
int checkwin(int board[19][19])
{
	int i,j,k,count;
	for(i=0;i<=18;i++)
	{
		for(j=0;j<=18-4;j++)
		{
			if(board[i][j]==0)
				continue;
			count=1;
			for(k=1;k<=4;k++)
				if(board[i][j+k]!=0 && board[i][j+k]%2==board[i][j]%2)
					count++;
			if(count==5)
				return 1;
		}
	}
	for(i=0;i<=18-4;i++)
	{
		for(j=0;j<=18;j++)
		{
			if(board[i][j]==0)
				continue;
			count=1;
			for(k=1;k<=4;k++)
				if(board[i+k][j]!=0 && board[i+k][j]%2==board[i][j]%2)
					count++;
			if(count==5)
				return 1;
		}
	}
	for(i=0;i<=18-4;i++)
	{
		for(j=0;j<=18-4;j++)
		{
			if(board[i][j]==0)
				continue;
			count=1;
			for(k=1;k<=4;k++)
				if(board[i+k][j+k]!=0 && board[i+k][j+k]%2==board[i][j]%2)
					count++;
			if(count==5)
				return 1;
		}
	}
	for(i=0;i<=18-4;i++)
	{
		for(j=4;j<=18;j++)
		{
			if(board[i][j]==0)
				continue;
			count=1;
			for(k=1;k<=4;k++)
				if(board[i+k][j-k]!=0 && board[i+k][j-k]%2==board[i][j]%2)
					count++;
			if(count==5)
				return 1;
		}
	}
	return 0;
}
//������
int main()
{
	int board[19][19]={0};
	int i,stepmn,m,n,stepcount=0,score;
	int stepxy[722]={0};
	for(i=0;i<722;i++)
		stepxy[i]=-1;
	for(m=0;m<=18;m++)
		for(n=0;n<=18;n++)
			board[m][n]=0;
	showboard(board);
	m=0;
	n=0;
	for(i=1;i<=180;i++)
	{
		stepcount++;
		stepmn=player(board);
		if(checkerror(board,stepmn))
		{
			cout<<"mn="<<stepmn<<endl;
			break;
		}
		m=stepmn/100;
		n=stepmn%100;
		board[m][n]=stepcount;
		stepxy[stepcount*2-2]=m;
		stepxy[stepcount*2-1]=n;

//		showboard(board);
		if(checkwin(board)==1)
		{
			cout<<"player1 win"<<endl;
			break;
		}

		stepcount++;
		stepmn=demo(board);
		if(checkerror(board,stepmn))
		{
			cout<<"mn="<<stepmn<<endl;
			break;
		}
		m=stepmn/100;
		n=stepmn%100;
		board[m][n]=stepcount;
		stepxy[stepcount*2-2]=m;
		stepxy[stepcount*2-1]=n;
//		showboard(board);
		cout<<"checkwin(board)="<<checkwin(board)<<endl;
		if(checkwin(board)==1)
		{
			cout<<"player2 win"<<endl;
			break;
		}
	}
	showboard(board);
	cout<<"GameOver"<<endl;
	if(board[m][n]%2==1)
		score=(800-stepcount)*10;
	else
		score=stepcount*10;
	cout<<endl<<"stepxy="<<endl;
	for(i=0;stepxy[i]>=0 && i<722;i++)
		cout<<stepxy[i]<<",";
	cout<<endl;
	cout<<"stepcount="<<stepcount<<endl;
	cout<<"score="<<score<<endl;
    char name;
    cin>>name;
	return 0;
}
