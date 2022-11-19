#include<stdio.h>

int max[10][10],allocation[10][10],avail[10],need[10][10];
int np,nr;

void readmatrix(int matrix[10][10]){
    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nr; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
        
    }
    
}

void displaymatrix(int matrix[10][10]){
    for (int i = 0; i < np; i++)
    {
        printf("\n p%d",i);
        for (int j = 0; j < nr; j++)
        {
            printf("%d",&matrix[i][j]);
        }
        
    }
    
}

void calculate_need(){
    for (int i = 0; i < np; i++)
    for (int j = 0; j < nr; j++)
        need[i][j]=max[i][j]-allocation[i][j];
      
}

void banker(){
    int k=0;
    int flag=0;
    int finish[10],safe_seq[10];
    for (int i = 0; i < np; i++)
    {
        finish[i]=0;
    }
    for (int i = 0; i < np; i++)
    {
        flag=0;
        if (finish[i]==0)
        {
            for (int j = 0; j < nr; i++)
            {
                if (need[i][j]>avail[j])
                {
                    flag=1;
                    break;
                }
                if (flag==0)
                {
                    finish[i]=1;
                    safe_seq[k]=i;
                    k++;

                    for (int j = 0; j < nr; j++)
                    {
                     avail[j]+=allocation[i][j];
                     i=-1;   
                    }
                    
                }
                
                
            }

            flag=0;
            for (int i = 0; i < np; i++)
            {
                if (finish[i]==0)
                {
                    printf("sys is deadlock");
                    flag=1;
                    break;
                }
                
            }
            if (flag==0)
            {
                printf("sys is in safe state");
                for (int i = 0; i < np; i++)
                {
                    printf(safe_seq[i]);
                }
                
            }
            
            
            
        }
        
    }
    
    
}

int main(int argc, char const *argv[])
{
    printf("enter number of processors");
    scanf("%d",&np);

    printf("enter number of resources");
    scanf("%d",&nr);

    printf("enter intial allocation");
    readmatrix(allocation);

    printf("enter maximum required");
    readmatrix(max);

    printf("enter available resource");
    for (int i = 0; i < nr; i++)
    {
        scanf("%d",avail[i]);
    }
    

  
    printf("****displaying data****");
    printf("Intial allocation");
    displaymatrix(allocation);

    printf("maximum requirement");
    displaymatrix(max);

    printf("available allocation");
    for (int i = 0; i < nr; i++)
    {
        printf("%d",avail[i]);
    }

    calculate_need();
    printf("need is");
    displaymatrix(need);


    banker();
    printf("\n\n\n");
    
    return 0;
}
