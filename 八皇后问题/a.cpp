/*
#include<iostream>
using namespace std;

#define N 8
//N����ʺ���
void queen()
{
	int Count=0;		 //�����ܹ��Ľ������
	int column[N+1];     //column[m]=n ��ʾ��m�У���n�з����˻ʺ�,�����±���0��ʼ
	int row[N+1];		 //row[m]=1��ʾ��m��û�лʺ�=0��ʾ�лʺ�
	int b[2*N+1];		 //b[m]=1��ʾ��m�����Խ���û�лʺ�
	int c[2*N+1];        //c[m]=1��ʾ��m���ζԽ���û�лʺ�=0��ʾ�лʺ�
	int numQueen=1;		 //�����Ѿ����õĻʺ���Ŀ����numQueen=Nʱ�����ʾ�Ѿ����̽��
	int good=1;			 //good=1��ʾû�з�����ͻ,good=0��ʾ������ͻ
	
	//��ʼ����Щ���
	for(int j=0;j<N+1;++j)
	{
		row[j]=1; //û�лʺ� 
	}
	for(int j=0;j<2*N+1;++j)
	{
		b[j]=c[j]=1;
	}
	column[1]=1;
	column[0]=0;          //��ʼ����һ�е�һ�У��ڶ��еڶ��з��ûʺ�
	do
	{
		//û�з�����ͻ�����������̽�⣬���ӻʺ�����жϵ�ǰ�Ƿ��ǽ�
		if(good)
		{
			//��ǰ�ʺ����ǽ⣬��ӡ����������̽��
			if(numQueen==N)
			{
				Count++;
				cout<<"�ҵ���"<<endl;
				for(int j=1;j<N+1;++j)
				{
					cout<<j<<"��"<<column[j]<<"��"<<endl;
				}
				//���һ�����������ƶ�,�ƶ����������һ��
				while(column[numQueen]==N)
				{
					numQueen--;			//�ʺ�����1����������1������
					//���ݺ󽫸����Լ��������һ��״̬λ�޸�
					//��numQueen��column[numQueen]�д�״̬λ���޸�
					row[column[numQueen]]=1;
					b[numQueen+column[numQueen]]=1;
					c[N+numQueen-column[numQueen]]=1;
				}
				column[numQueen]++;		//��������һ�У�����һ�е���һ�м���̽��
			}
			//��ǰ���ǽ⣬��ô��������̽��
			else
			{
				//�ı��λ�ö�Ӧ��־
				row[column[numQueen]]=0;
				b[numQueen+column[numQueen]]=0;
				c[N+numQueen-column[numQueen]]=0;
				//����λ��û�з�����ͻ��Ҳ������ȷ�⣬��ô��Ӧ������̽����һ�еĵ�һ��
				column[++numQueen]=1;
			}
		}
		//�����ǰ�����˳�ͻ�����ڱ��м������£�������˱������һ�У�����ݵ���һ��
		else
		{
			while(column[numQueen]==N) //���˱������һ�У����ǳ�ͻ����ô���ݵ���һ��
			{
				numQueen--;
				row[column[numQueen]]=1;
				b[numQueen+column[numQueen]]=1;
				c[N+numQueen-column[numQueen]]=1;
			}
			column[numQueen]++;	//������ͻ�ˣ���û�е����е����һ�У���ô�ڱ��м�������һ��̽��
		}
		//�����������λ�ú��Ƿ��ͻ
		good=row[column[numQueen]]&b[numQueen+column[numQueen]]&c[N+numQueen-column[numQueen]];
	}while(numQueen);
	cout<<N<<"�ʺ��ܹ��ҵ��⣺"<<Count<<"��"<<endl;
}
int  main()
{
	queen();
	system("pause");
	
	return 0;
}
*/
/*
** �˻ʺ�����
*/

#include <stdio.h>
#define  TRUE  1
#define  FALSE 0

/*
** ���̣�8*8�Ķ�ά����Ϊȫ�ֱ���
** ���лʺ�ĵط�����ΪTRUE
** FALSE����û�лʺ�
*/
int chessboard[8][8] = { 0 };

int conflict( int row, int col );
void print_board();
void place_queen( int row );

int main()
{
    place_queen( 0 );
    return 0;
}

/*
** �������ܣ�
**     ����ĳһ�У��ڸ��е�ÿһ���Ϸ��ûʺ󣬼���Ƿ��໥����
*/
void place_queen( int row )
{
    int col;
    
    /*
    ** �����ڸ��е�ÿһ���Ϸ��ûʺ�
    */
    for( col = 0; col < 8; ++ col )
    {
        chessboard[ row ][ col ] = TRUE;
        
        /*
        ** �����ϵĻʺ��Ƿ��������ʺ��ͻ
        ** ��1�еĻʺ��ǵ�1�����õģ��϶�����������ͻ
        ** ��1�к͵�2~7�иշ��ϵĻʺ���������ͻʱ���õݹ������һ���ʺ�
        ** ��8�з��ϵĻʺ���������ͻʱ����ӡ��
        */
        if( row == 0 || !conflict( row, col ) )
        {
            if( row < 7 )
                place_queen( row + 1 );
            else
                print_board();
        }
        
        // ��ǰλ�÷��ϻʺ���������ͻʱ������λ������ΪFALSE
        chessboard[ row ][ col ] = FALSE;
    }
}

/*
** �������ܣ�
**     ���������ĳ��λ�÷��ϻʺ��Ƿ��������ʺ��ͻ
**   ˵����
**     ������һ��һ�д������·��ûʺ�ģ�ֻ��Ҫ���
**     ��ǰλ��֮ǰ�Ļʺ󣬵�ǰλ��֮��û�з��ûʺ�
** �������أ�
**     �г�ͻ������TRUE���޳�ͻ������FALSE
*/
int conflict( int row, int col )
{
    int i;
    for( i = 1; i < 8; ++ i )
    {
        // ��鵱ǰ���ӵ��Ϸ�ֱ�����Ƿ��лʺ�
        if( row - i >= 0 && chessboard[ row - i ][ col ] )
            return TRUE;
            
        // ��鵱ǰ���ӵ����ֱ�����Ƿ��лʺ�
        if( col - i >= 0 && chessboard[ row ][ col - i ] )
            return TRUE;
            
        // ��鵱ǰ���ӵ��Ҳ�ֱ�����Ƿ��лʺ�
        if( col + i < 8 && chessboard[ row ][ col + i ] )
            return TRUE;
            
        // ��鵱ǰ�������ϽǶԽ������Ƿ��лʺ�
        if( row - i >= 0 && col - i >= 0 
            && chessboard[ row - i ][ col - i ] )
                return TRUE;
                
        // ��鵱ǰ�������ϽǶԽ������Ƿ��лʺ�
        if( row - i >= 0 && col + i < 8 
            && chessboard[ row - i ][ col + i ] )
                return TRUE;        
    }
    
    // ִ�е�����˵��û�г�ͻ������FALSE
    return FALSE;
}

/*
** �������ܣ�
**     ��ӡ����
*/
void
print_board()
{
    int row;
    int col;
    static int solution_count;  // ��̬����������ڼ�����
    solution_count ++;
    printf( "Solution %d:\n", solution_count );
    
    /*
    ** �������̣�����ӡ
    */
    for( row = 0; row < 8; ++ row )
    {
        for( col = 0; col < 8; ++ col )
        {
            if( chessboard[ row ][ col ] )
                printf( " Q" );
            else
                printf( " +" );
        }
        putchar( '\n' );
    }
    putchar( '\n' );
}