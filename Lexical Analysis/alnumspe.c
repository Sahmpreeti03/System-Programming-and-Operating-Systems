# include<stdio.h>
//roll no 32255
void main(){
	char aln[40];
	scanf("%s",aln);
	char str[40],sp[40];
	int x=0;
	int house=0;
	int j=0,k=0;
	for (x=0; x<strlen(aln); x++ ) {
        if(aln[x]>='0' && aln[x]<='9') {
        	printf("%c",aln[x]);
        }
        else if (isalpha(aln[x]))
        str[j++]=aln[x];
        else
        sp[k++]=aln[x];
	}
	printf("\n");
	puts(str);
	puts(sp);	
}
