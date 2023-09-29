#include<stdio.h>
int main(){
    int at[10],bt[10],rt[10],ct[10],CT,i,smallest,n,remain=0,time=0,ttat=0,twt=0;
    printf("Enter number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nEnter arrival time for process %d\n",i+1);
        scanf("%d",&at[i]);
        printf("Enter burst time for process %d\n",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    printf("\nProcess\t|Turnaround Time|Waiting Time\n");
    for(time=0;remain!=n;time++){
        for(i=0;i<n;i++){
            if(at[i]<=time && rt[i]){
                smallest=i;
            }
        }
        rt[smallest]--;
        if(rt[smallest]==0){
            remain++;
            CT=time+1;
            printf("\nP%d\t|\t%d\t|\t%d\t",smallest+1,CT-at[smallest],CT-at[smallest]-bt[smallest]);
            twt+=CT-at[smallest]-bt[smallest];
            ttat+=CT-at[smallest];
        }
    }
    printf("\nAverage Waiting Time : %f",twt*1.0/n);
    printf("\nAverage Turnaround Time : %f",ttat*1.0/n);
    return 0;
}

