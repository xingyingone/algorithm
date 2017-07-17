/*
#include<iostream>
using namespace std;

#define N 8
//N代表皇后数
void queen()
{
	int Count=0;		 //计算总共的解的数量
	int column[N+1];     //column[m]=n 表示第m列，第n行放置了皇后,这里下表并从0开始
	int row[N+1];		 //row[m]=1表示第m行没有皇后，=0表示有皇后
	int b[2*N+1];		 //b[m]=1表示第m条主对角线没有皇后，
	int c[2*N+1];        //c[m]=1表示第m条次对角线没有皇后，=0表示有皇后
	int numQueen=1;		 //计数已经放置的皇后数目，当numQueen=N时候则表示已经完成探测
	int good=1;			 //good=1表示没有发生冲突,good=0表示发生冲突
	
	//初始化这些标记
	for(int j=0;j<N+1;++j)
	{
		row[j]=1; //没有皇后 
	}
	for(int j=0;j<2*N+1;++j)
	{
		b[j]=c[j]=1;
	}
	column[1]=1;
	column[0]=0;          //初始化第一行第一列，第二行第二列放置皇后
	do
	{
		//没有发生冲突，则继续向下探测，增加皇后或者判断当前是否是解
		if(good)
		{
			//当前皇后数是解，打印，继续向下探测
			if(numQueen==N)
			{
				Count++;
				cout<<"找到解"<<endl;
				for(int j=1;j<N+1;++j)
				{
					cout<<j<<"列"<<column[j]<<"行"<<endl;
				}
				//最后一个棋子向下移动,移动到本列最后一个
				while(column[numQueen]==N)
				{
					numQueen--;			//皇后数减1，即列数减1，回溯
					//回溯后将该列以及该列最后一行状态位修改
					//第numQueen列column[numQueen]行处状态位置修改
					row[column[numQueen]]=1;
					b[numQueen+column[numQueen]]=1;
					c[N+numQueen-column[numQueen]]=1;
				}
				column[numQueen]++;		//回溯至上一行，向上一行的下一列继续探测
			}
			//当前不是解，那么继续向下探测
			else
			{
				//改变该位置对应标志
				row[column[numQueen]]=0;
				b[numQueen+column[numQueen]]=0;
				c[N+numQueen-column[numQueen]]=0;
				//本次位置没有发生冲突，也不是正确解，那么就应该向下探测下一列的第一行
				column[++numQueen]=1;
			}
		}
		//如果当前发生了冲突，就在本列继续向下，如果到了本列最后一行，则回溯到上一列
		else
		{
			while(column[numQueen]==N) //到了本列最后一行，还是冲突，那么回溯到上一列
			{
				numQueen--;
				row[column[numQueen]]=1;
				b[numQueen+column[numQueen]]=1;
				c[N+numQueen-column[numQueen]]=1;
			}
			column[numQueen]++;	//发生冲突了，又没有到本列的最后一行，那么在本列继续向下一行探测
		}
		//检测放置了这个位置后是否冲突
		good=row[column[numQueen]]&b[numQueen+column[numQueen]]&c[N+numQueen-column[numQueen]];
	}while(numQueen);
	cout<<N<<"皇后总共找到解："<<Count<<"个"<<endl;
}
int  main()
{
	queen();
	system("pause");
	
	return 0;
}
*/
/*
** 八皇后问题
*/

#include <stdio.h>
#define  TRUE  1
#define  FALSE 0

/*
** 棋盘，8*8的二维矩阵，为全局变量
** 将有皇后的地方设置为TRUE
** FALSE，则没有皇后
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
** 函数功能：
**     给定某一行，在该行的每一列上放置皇后，检查是否相互攻击
*/
void place_queen( int row )
{
    int col;
    
    /*
    ** 尝试在该行的每一列上放置皇后
    */
    for( col = 0; col < 8; ++ col )
    {
        chessboard[ row ][ col ] = TRUE;
        
        /*
        ** 检查放上的皇后是否与其他皇后冲突
        ** 第1行的皇后是第1个放置的，肯定不与其他冲突
        ** 第1行和第2~7行刚放上的皇后不与其他冲突时，用递归放置下一个皇后
        ** 第8行放上的皇后不与其他冲突时，打印答案
        */
        if( row == 0 || !conflict( row, col ) )
        {
            if( row < 7 )
                place_queen( row + 1 );
            else
                print_board();
        }
        
        // 当前位置放上皇后与其他冲突时，将该位置重置为FALSE
        chessboard[ row ][ col ] = FALSE;
    }
}

/*
** 函数功能：
**     检查在棋盘某个位置放上皇后是否与其他皇后冲突
**   说明：
**     由于是一行一行从上往下放置皇后的，只需要检查
**     当前位置之前的皇后，当前位置之后还没有放置皇后
** 函数返回：
**     有冲突，返回TRUE；无冲突，返回FALSE
*/
int conflict( int row, int col )
{
    int i;
    for( i = 1; i < 8; ++ i )
    {
        // 检查当前棋子的上方直线上是否有皇后
        if( row - i >= 0 && chessboard[ row - i ][ col ] )
            return TRUE;
            
        // 检查当前棋子的左侧直线上是否有皇后
        if( col - i >= 0 && chessboard[ row ][ col - i ] )
            return TRUE;
            
        // 检查当前棋子的右侧直线上是否有皇后
        if( col + i < 8 && chessboard[ row ][ col + i ] )
            return TRUE;
            
        // 检查当前棋子左上角对角线上是否有皇后
        if( row - i >= 0 && col - i >= 0 
            && chessboard[ row - i ][ col - i ] )
                return TRUE;
                
        // 检查当前棋子右上角对角线上是否有皇后
        if( row - i >= 0 && col + i < 8 
            && chessboard[ row - i ][ col + i ] )
                return TRUE;        
    }
    
    // 执行到这里说明没有冲突，返回FALSE
    return FALSE;
}

/*
** 函数功能：
**     打印棋盘
*/
void
print_board()
{
    int row;
    int col;
    static int solution_count;  // 静态变量，计算第几个答案
    solution_count ++;
    printf( "Solution %d:\n", solution_count );
    
    /*
    ** 遍历棋盘，并打印
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