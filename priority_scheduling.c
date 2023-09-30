#include <stdio.h>
struct process{
    int at,wt,tat,bt,pr,ct;
};
struct process a[10];

int main(){
    int count=0,i,temp[10],short_p,n,t;
    float twt=0,ttat=0;
    printf("Enter the number of Processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nEnter arrival time for process %d: ", i + 1);
        scanf("%d", &a[i].at);
        printf("\nEnter burst time for process %d: ", i + 1);
        scanf("%d",a[i].bt);
        printf("nEnter Priority for process %d: ", i + 1);
        scanf("%d",a[i].pr);
        temp[i]=a[i].bt;
    }
    a[9].pr=-1;
    int gchart[100];
    int gct[100];
    int gindex=0;
    for(t=0;count!=n;t++){
        short_p=90;
        for(i=0;i<n;i++){
             if(a[short_p].pr>a[i].pr && a[i].at<=t && a[i].bt>0){
                short_p=i;
            }
        }
        a[short_p].bt--;
        gchart[gindex]=short_p;
        gct[gindex]=t+1;
        gindex++;
        if(a[short_p].bt==0){
            count++;
            a[short_p].wt=t+1-a[short_p].at-temp[short_p];
            a[short_p].tat= t+1 -a[short_p].at;
            a[short_p].ct= t+1;
            twt+=a[short_p].wt;
            ttat+=a[short_p].tat;
        }

    }
     printf("ID\tWT\tTAT\tCT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", i + 1, a[i].wt, a[i].tat, a[i].ct);
    }
    printf("\nGantt Chart:\n");
    for (i = 0; i < gindex; i++) {
        printf("| P%d %d ", gchart[i] + 1,gct[i]);
    }
    printf("|\n");

    printf("Avg waiting time is %.2f\n", 1.0*twt/n);
    printf("Avg turn around time is %.2f\n",1.0*ttat/n);

    return 0;
}

























