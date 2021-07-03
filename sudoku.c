#include <stdio.h>

int over(int a, int b, int f);
int najdi(int* a, int* b);
int solve();
void vypis();
void nacitaj();
int array[9][9]= {
    {0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 8, 0, 0, 2, 0, 0},
    {6, 1, 0, 0, 0, 4, 5, 0, 0},
    {4, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 6, 8, 1, 2, 5, 0, 0, 3},
    {0, 0, 0, 0, 8, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 3, 4},
    {0, 0, 3, 0, 0, 0, 0, 5, 0},
    {0, 0, 0, 0, 7, 6, 8, 0, 0}
};
int a,b;

int main()
{
    //nacitaj();
   if(solve())
    vypis();
}

int najdi(int* c, int* d)
{
    int match = 0;

    for(int j = 0; j < 9; j++)
    {
        for(int i = 0; i < 9; i++)
            if((array[j][i]) == 0)
            {
                *c = j;
                *d = i;
                match +=1;
                break;
            }
        if(j >= 8 && match == 0)
            return 0;

        if (match)
            break;
    }
}

int over(int a, int b, int f)
{

    int x,y;
    for(int c = 0; c < 9; c++) {
        if(c == b)
            continue;
        if(array[a][c] == f)
        {
            return 0;
            break;
        }
    }

    for(int d = 0; d < 9; d++) {
        if(d == a)
            continue;
        if(array[d][b] == f) {
            return 0;
            break;
        }

    }
    x = a;
    y = b;

    if (x >= 0 && x < 3 )x = 0;
    if (x >= 3 && x < 6 )x = 3;
    if (x >= 6 )x = 6;

    if (y >= 0 && y < 3 )y = 0;
    if (y >= 3 && y <6 )y = 3;
    if (y >= 6 )y = 6;

    for(int i = x; i < x+3; i++) {
        for(int j = y; j < y+3; j++) {
            if(i == a && j == b)
                continue;
            if(array[i][j] == f) {
                return 0;
                break;
            }
        }
    }
    return 1;
}

int solve()
{
    int x,y;
    if(najdi(&a,&b))
    {
    x = a;
    y = b;
        for(int j = 1; j < 10; j++)
        {
            if(over(x,y,j))
            {
                array[x][y] = j;
                if(solve())
                    return 1;

                array[x][y] = 0;
            }
        }
        return 0;
    }
    else
        return 1;

}

void vypis()
{
    printf("\n\n");
    int i,j;

    for(i=0;i<9;i++)
    {
        printf(" ");

        if(i%3 == 0 && i != 0)
           printf("-----------------------\n ");

        for(j=0;j<9;j++)
        {
            if(j%3 == 0 && j !=0)
                printf(" | ");

            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
}

void nacitaj()
{
 int i,j;

    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            scanf("%d",&array[i][j]);
        }
    }
}
