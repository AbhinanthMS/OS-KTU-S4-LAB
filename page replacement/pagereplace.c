#include <stdio.h>

int main(){

    int n, f, pg[25], fr[10],found =0,k=0,pfault=0;
    printf("ENTER THE NUMBER OF PAGES : ");
    scanf("%d", &n);
    printf("ENTER THE REFERENCE STRING : ");
    for (int j = 0; j < n; j++)
        scanf("%d", &pg[j]);
    printf("ENTER THE NUMBER OF FRAMES : ");
    scanf("%d",&f);
    for(int j =0;j< f ;j++)
        fr[j] = -1;

    printf("\nREFERENCE PAGE  STATUS  FRAME CONTENT \n");
    for(int i = 0;i< n ;i++){
            found = 0;
            printf("\n\t%d\t ",pg[i]);
            for(int j = 0; j< f ;j++)
                if(fr[j] == pg[i])
                    found = 1;
            if(!found){
                fr[k] = pg[i];
                k = (k+1)%f;
                pfault++;
            }
            if(found)
                printf("HIT\t");
            else    
                printf("MISS\t");

            for(int j = 0;j<f;j++)
                if(fr[j]!=-1)
                    printf(" [%d] ",fr[j]);
    }
    printf("\nPAGE FAULT :%d",pfault);
}