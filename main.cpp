#include <stdio.h>
#include<stdlib.h>
#define N 9
#define UNASSIGNED 0

int is_exist_row(int grid[N][N], int row, int num)
{
	for (int col = 0; col < 9; col++)
        {
		if (grid[row][col] == num)
		{
			return 1;
		}
        }
	return 0;
}

int is_exist_col(int grid[N][N], int col, int num)
 {
	for (int row = 0; row < 9; row++)
    {
		if (grid[row][col] == num)
		{
			return 1;
		}
    }
	return 0;
}

int is_exist_box(int grid[N][N], int startRow, int startCol, int num)
{
	for (int row = 0; row < 3; row++)
    {
		for (int col = 0; col < 3; col++)
		 {
			if (grid[row + startRow][col + startCol] == num)
			{
				return 1;
			}
		}
	}
	return 0;
}

int is_safe_num(int grid[N][N], int row, int col, int num)
{
	return !is_exist_row(grid, row, num)
			&& !is_exist_col(grid, col, num)
			&& !is_exist_box(grid, row - (row % 3), col - (col %3), num);
}

int find_unassigned(int grid[N][N], int *row, int *col)
{
	for (*row = 0; *row < N; (*row)++)
    {
		for (*col = 0; *col < N; (*col)++)
		{
			if (grid[*row][*col] == 0)
			{
				return 1;
			}
		}
	}
	return 0;
}

int solve(int grid[N][N])
{

	int row = 0;
	int col = 0;

	if (!find_unassigned(grid, &row, &col))
    {
		return 1;
	}

	for (int num = 1; num <= N; num++ )
    {

		if (is_safe_num(grid, row, col, num))
        {
			grid[row][col] = num;

			if (solve(grid))
            {
				return 1;
			}

			grid[row][col] = UNASSIGNED;
		}
	}

	return 0;
}

void print_grid(int grid[N][N])
{

    int i,j;
    printf("\n\t\t %2d%2d%2d  %2d%2d%2d  %2d%2d%2d\n",1,2,3,4,5,6,7,8,9);
    printf("\t\t-------------------------\n");
    for(i=0;i<9;i++)
    {
        printf("\t");

        for(j=0;j<9;j++)
        {
            if(j==0)
            {
                printf("%d",i+1);
                printf("\t| ");
            }
            if(grid[i][j]==0)
                printf(". ");

            else
                printf("%d ",grid[i][j]);

            if((j+1)%3==0 )
                printf("| ");

        }

    if((i+1)%3==0 )
        printf("\n\t\t-------------------------");

    printf("\n");
    }
    printf("\n***************************************************************\n");
}
int main()
{
    int ans[N][N]={0 };
    char ch;
    char str[100];
    int choice;
    printf("\n***************************************************************\n");
    printf("\n                           WELCOME\n");
    printf("\n***************************************************************\n");
    printf("\n                         SUDOKU NINJA\n");
    printf("\n***************************************************************\n");
    printf("\n\n Are you ready for a fun game of sudoku?\n");

    printf(" Press y for yes(^.^) \n");
    scanf("%c%*c",&ch);

    if(ch!='y')
        exit(0);
    printf("\nxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxox\n");
    printf("\n Enter your name:\n");
    scanf("%[^\n]s",str);

    printf("\n HELLO PLAYER,%s !!!!\n",str);

    printf("\n Let's get started......\n");
    printf("\n##################################################################\n");
    printf("\n Which category do you want to play in?\n");
    printf("\n 1.Easy\n");
    printf("\n 2.Medium\n");
    printf("\n 3.Hard\n");
    printf("\n 4.Expert\n");

    printf("\n Enter your choice now:\n");
    scanf("%d",&choice);

    printf("\n***************************************************************\n");
    printf("\n Here is the puzzle for you (^.^)\n");
    printf("\n Don't forget to have fun!!!!!!!!\n");
    printf("\n***************************************************************\n");

    if(choice==1)
    {
        int grid[N][N] = {{4,0,9, 0,0,8, 0,3,0},
			 {7,5,0, 0,3,2, 0,1,8},
			 {0,0,0, 5,0,0, 2,0,6},
			 {8,0,0, 0,0,3, 9,0,0},
			 {0,3,0, 0,4,0, 0,7,5},
			 {0,0,1, 2,0,7, 0,0,0},
			 {0,0,8, 4,0,0, 0,0,9},
			 {0,1,0, 0,0,9, 0,4,0},
			 {2,0,0, 7,1,0, 8,5,0}
			 };

        int r,c;
        int sol;
        int f=0;

        int ans[N][N]={{4,0,9, 0,0,8, 0,3,0},
			 {7,5,0, 0,3,2, 0,1,8},
			 {0,0,0, 5,0,0, 2,0,6},
			 {8,0,0, 0,0,3, 9,0,0},
			 {0,3,0, 0,4,0, 0,7,5},
			 {0,0,1, 2,0,7, 0,0,0},
			 {0,0,8, 4,0,0, 0,0,9},
			 {0,1,0, 0,0,9, 0,4,0},
			 {2,0,0, 7,1,0, 8,5,0}
			 };

        print_grid(grid);
        solve(grid);

        do
        {
            printf("\n Enter the row no. :\n");
            scanf("%d",&r);

            r-=1;

            printf("\n Enter the column no.:\n");
            scanf("%d",&c);

            c-=1;

            printf("\n Enter the element:\n");
            scanf("%d",&sol);

            if(grid[r][c]==sol)
            {

            ans[r][c]=sol;
            printf("\n Correct\n");
            printf("\n Play on !!!\n");
            printf("\n***************************************************************\n");
            print_grid(ans);

                for(int i=0;i<9;i++)
                    {
                        for(int j=0;j<9;j++)

                            if(ans[i][j]==0)
                                f=0;
                            else
                                f+=1;
                    }
            }

            else
            {
                printf("\n Wrong answer\n");
                printf("\n Don't give up !!\n");
                printf("\n Continue Playing\n");
                printf("\n***************************************************************\n");
            }

        }while(f!=81);

        print_grid(ans);
	}

    if(choice==2)
    {

        int grid[N][N] = {{0,7,0, 0,2,0, 9,0,0},
			 {0,4,0, 8,0,6, 0,0,0},
			 {0,1,2, 0,0,0, 3,0,0},
			 {0,0,0, 0,0,0, 8,7,0},
			 {0,6,0, 9,7,2, 0,5,0},
			 {0,2,5, 0,0,0, 0,0,0},
			 {0,0,1, 0,0,0, 2,9,0},
			 {0,0,0, 5,0,4, 0,3,0},
			 {0,0,7, 0,6,0, 0,1,0}
			 };

        int r,c;
        int sol;
        int f=0;
        int ans[N][N]={{0,7,0, 0,2,0, 9,0,0},
			 {0,4,0, 8,0,6, 0,0,0},
			 {0,1,2, 0,0,0, 3,0,0},
			 {0,0,0, 0,0,0, 8,7,0},
			 {0,6,0, 9,7,2, 0,5,0},
			 {0,2,5, 0,0,0, 0,0,0},
			 {0,0,1, 0,0,0, 2,9,0},
			 {0,0,0, 5,0,4, 0,3,0},
			 {0,0,7, 0,6,0, 0,1,0}
			 };

        print_grid(grid);
        solve(grid);

        do
        {

        printf("\n Enter the row no. :\n");
        scanf("%d",&r);

        r-=1;

        printf("\n Enter the column no.:\n");
        scanf("%d",&c);

        c-=1;

        printf("\n Enter the element:\n");
        scanf("%d",&sol);

        if(grid[r][c]==sol)
        {

            ans[r][c]=sol;
            printf("\n Correct\n");
            printf("\n Play on\n");
            printf("\n***************************************************************\n");
            print_grid(ans);
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)

                    if(ans[i][j]==0)
                        f=0;
                    else
                        f+=1;
            }
        }

        else
        {

            printf("\n Wrong Answer\n");
            printf("\n Don't give up!!\n");
            printf("\n Continue Playing\n");
            printf("\n***************************************************************\n");

         }

        }while(f!=81);

        print_grid(ans);
    }

    if(choice==3)
    {

        int grid[N][N] = {{0,8,0, 7,0,1, 0,3,0},
			 {4,0,9, 0,0,0, 0,0,0},
			 {0,5,0, 0,6,0, 4,1,8},
			 {7,0,0, 0,0,9, 0,0,0},
			 {8,0,0, 6,1,0, 5,0,0},
			 {0,3,5, 0,0,0, 0,2,9},
			 {0,6,0, 4,0,7, 0,9,0},
			 {1,0,0, 0,0,8, 0,0,4},
			 {0,2,0, 0,5,0, 0,7,0}
			 };

        int r,c;
        int sol;
        int f=0;
        int ans[N][N]={{0,8,0, 7,0,1, 0,3,0},
			 {4,0,9, 0,0,0, 0,0,0},
			 {0,5,0, 0,6,0, 4,1,8},
			 {7,0,0, 0,0,9, 0,0,0},
			 {8,0,0, 6,1,0, 5,0,0},
			 {0,3,5, 0,0,0, 0,2,9},
			 {0,6,0, 4,0,7, 0,9,0},
			 {1,0,0, 0,0,8, 0,0,4},
			 {0,2,0, 0,5,0, 0,7,0}
			 };

        print_grid(grid);
        solve(grid);

        do
        {
            printf("\n Enter the row no. :\n");
            scanf("%d",&r);

            r-=1;

            printf("\n Enter the column no.:\n");
            scanf("%d",&c);

            c-=1;

            printf("\n Enter the element:\n");
            scanf("%d",&sol);

            if(grid[r][c]==sol)
            {

                ans[r][c]=sol;
                printf("\n Correct\n");
                printf("\n Play on\n");
                printf("\n***************************************************************\n");
                print_grid(ans);
                for(int i=0;i<9;i++)
                {
                    for(int j=0;j<9;j++)

                        if(ans[i][j]==0)
                            f=0;
                        else
                            f+=1;
                }
            }

            else
            {

                printf("\n Wrong answer\n");
                printf("\n Don't give up !!\n");
                printf("\n Continue playing\n");
                printf("\n***************************************************************\n");
            }

        }while(f!=81);

        print_grid(grid);
    }

    if(choice==4)
    {

        int grid[N][N] = {{8,0,0, 0,0,0, 0,0,0},
			 {0,0,3, 6,0,0, 0,0,0},
			 {0,7,0, 0,9,0, 2,0,0},
			 {0,5,0, 0,0,7, 0,0,0},
			 {0,0,0, 0,4,5, 7,0,0},
			 {0,0,0, 1,0,0, 0,3,0},
			 {0,0,1, 0,0,0, 0,6,8},
			 {0,0,8, 5,0,0, 0,1,0},
			 {0,9,0, 0,0,0, 4,0,0}
			 };
        int r,c;
        int sol;
        int f=0;

        int ans[N][N]={{8,0,0, 0,0,0, 0,0,0},
			 {0,0,3, 6,0,0, 0,0,0},
			 {0,7,0, 0,9,0, 2,0,0},
			 {0,5,0, 0,0,7, 0,0,0},
			 {0,0,0, 0,4,5, 7,0,0},
			 {0,0,0, 1,0,0, 0,3,0},
			 {0,0,1, 0,0,0, 0,6,8},
			 {0,0,8, 5,0,0, 0,1,0},
			 {0,9,0, 0,0,0, 4,0,0}
			 };

        print_grid(grid);
        solve(grid);

        do
        {

            printf("\n Enter the row no. :\n");
            scanf("%d",&r);

            r-=1;

            printf("\n Enter the column no.:\n");
            scanf("%d",&c);

            c-=1;

            printf("\n Enter the element:\n");
            scanf("%d",&sol);

            if(grid[r][c]==sol)
            {

                ans[r][c]=sol;
                printf("\n Correct\n");
                printf("\n Play on\n");
                printf("\n***************************************************************\n");
                print_grid(ans);

                for(int i=0;i<9;i++)
                {
                    for(int j=0;j<9;j++)

                        if(ans[i][j]==0)
                            f=0;
                        else
                            f+=1;
                }
            }

            else
            {

                printf("\n Wrong answer\n");
                printf("\n Don't give up!!\n");
                printf("\n Continue playing\n");
                printf("\n***************************************************************\n");

            }

        }while(f!=81);

        print_grid(grid);
    }


    printf("\nxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxox\n");

    printf("\n                 WINNER!!WINNER!!CHICKEN DINNER!!\n");
    printf("\n                     Good play today! %s",str);
    printf("\n                    See you next time\n");

    printf("\nxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxox\n");
	return 0;
}
