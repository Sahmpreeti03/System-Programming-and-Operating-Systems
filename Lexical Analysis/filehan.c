# include<stdio.h>
//roll no 32255
void main(){
	FILE *fp,*fpr;  
	fp = fopen("demo.txt","r") ; 	
	char aln[40];
	char str[40],sp[40];
	int x=0;
	int house=0;
	int j=0,k=0;
	fpr = fopen("result.txt","w") ;
	while(fscanf(fp, "%s", aln)!=EOF)
	for (x=0; x<strlen(aln); x++ ) {
        if(aln[x]>='0' && aln[x]<='9') {
        	fprintf(fpr,"%c",aln[x]);
        }
        else if (isalpha(aln[x]))
        str[j++]=aln[x];
        else
        sp[k++]=aln[x];
	}
	fprintf(fpr,"\n");
	fputs(str,fpr);
	fprintf(fpr,"\n");
	fputs(sp,fpr);	 
	fclose(fp) ; 
	fclose(fpr); 
}

