#include <stdio.h>
#include <stdlib.h>
void read_matrix(int m[][500],int r,int c);
void sum_matrix(int m[][500],int n[][500],int r,int c);
void pro_matrix(int m[500][500],int n[500][500],int r1,int c1,int c2);
void trans_matrix(int m[][500],int r,int c);
void disp_matrix(int m[][500],int r,int c);
void main()
{
    int m[500][500],n[500][500],r1,r2,c1,c2,CHOICE;
    printf("Enter the size of the 1st matrix :\n");
    scanf("%d %d",&r1,&c1);
    printf("Enter the size of the 2nd matrix :\n");
    scanf("%d %d",&r2,&c2);
    while(1)
    {
        printf("**********MENU**********\n");
        printf("________________________\n");
        printf("1. READ MATRIX\n2. SUM OF MATRIX\n3. PRODUCT OF MATRIX\n4. TRANSPOSE OF MATRIX\n5. DISPLAY MATRIX\n6. EXIT\n");
        printf("What do you want to do: \n");
        scanf("%d",&CHOICE);
        switch(CHOICE)
        {
            case 1: read_matrix(m,r1,c1);
                    read_matrix(n,r2,c2);
                    break;
            case 2: if(r1==r2 && c1==c2)
                        sum_matrix(m,n,r1,c1);
                    else
                        printf("can't add\n");
                    break;
            case 3: if(c1=r2)
                        pro_matrix(m,n,r1,c1,c2);
                    else
                        printf("can't multiply\n");
                    break;
            case 4: printf("Transpose of 1st matrix is\n");
                    trans_matrix(m,r1,c1);
                    printf("Transpose of 2nd matrix is\n");
                    trans_matrix(n,r2,c2);
                    break;
            case 5: printf("1st matrix: \n");
                    disp_matrix(m,r1,c1);
                    printf("2nd matrix: \n");
                    disp_matrix(n,r2,c2);
                    break;
            case 6: exit(0);
        }
    }
}
void read_matrix(int m[][500],int r,int c)
{
    int i,j;
    printf("Enter the elements: \n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&m[i][j]);
}
void disp_matrix(int m[][500],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%3d",m[i][j]);
        }
        printf("\n");
    }
}
void sum_matrix(int m[][500],int n[][500],int r,int c)
{
    int i,j,p[500][500];
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            p[i][j]=m[i][j]+n[i][j];
    printf("Sum of matrices: \n");
    disp_matrix(p,r,c);
}
void pro_matrix(int m[500][500],int n[500][500],int r1,int c1,int c2)
{
    int i,j,p[500][500],k;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            p[i][j]=0;
            for(k=0;k<c1;k++)
                p[i][j]+=m[i][k]*n[k][j];
        }
    }
    printf("Product of matrices: \n");
    disp_matrix(p,r1,c2);
}
void trans_matrix(int m[][500],int r,int c)
{
    int i,j,p[500][500];
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            p[j][i]=m[i][j];
    disp_matrix(p,c,r);
}
