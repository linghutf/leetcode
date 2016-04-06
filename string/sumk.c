#include <stdio.h>

#define MAXN 100
const int a[]={3,-1,2,4,-7,8};
const int n = 6;
_Bool used[100];

void Print()
{
    for(int i=0;i<n;++i)
    {
        if(used[i]) printf("%4d",a[i]);
    }
    printf("\n");
}

void dfs(int *sum,int k,int step)
{
    if(step==n){
        if(*sum==k) Print();
    }else{
        if(*sum==k){
            Print();
        }else{
            if(!used[step]){
                used[step]=1;
                *sum=*sum+a[step];
                dfs(sum,k,step+1);
                *sum=*sum-a[step];
                used[step]=0;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int sum = 0;
    int k;
    scanf("%d",&k);
    dfs(&sum,k,0);

    return 0;
}
