//lexical analysis for properly indented program
# include<stdio.h>
# include<string.h>
# define MAX 65536
//roll no 32255
int main() 
{ 
	FILE *fptr,*fpo,*fpc,*fps,*fpi;
		
	char filename[100], c; 
	printf("Enter the filename to open \n"); 
	scanf("%s", filename); 
	// Open file 
	fptr = fopen(filename,"r"); 
	if (fptr == NULL) 
	{ 
		printf("Cannot open file \n"); 
		return 0;
	} 
	// Read contents from file 
	char opr[MAX],idn[MAX],sep[MAX];
	int i=0,j=0,k=0,l=0;
	
	fpo = fopen("operators.txt","w") ;
	fpi = fopen("identifiers.txt","w") ;
	fpc = fopen("constants.txt","w") ;
	fps = fopen("separators.txt","w") ;
	
	char whole[MAX];
	c = fgetc(fptr);
	int m=0; 
	while (c != EOF) 
	{ 
		whole[m]=whole[m]+c; 
		m++;
		c = fgetc(fptr); 
	} 
	printf("%s",whole);
	for (i=0; i<strlen(whole); i++ ) {
        if(whole[i]>='0' && whole[i]<='9') {
        	if((whole[i+1]>='0' && whole[i+1]<='9') || (whole[i+1]=='.' && (whole[i+2]>='0' && whole[i+2]<='9')))
        	{
        		fprintf(fpc,"%c",whole[i]);
        		if(whole[i+1]=='.')
        		fprintf(fpc,"%c",whole[i+1]);
			}
        	else{
        		fprintf(fpc,"%c",whole[i]);
        		fprintf(fpc," ");
			}
        		
        }
        else if (whole[i] == '+' || whole[i] == '-' || whole[i] == '*' || whole[i] == '/' || whole[i] == '>' || whole[i] == '<' || whole[i] == '='
		|| whole[i] == '&' || whole[i] == '|' || whole[i] == '!' || whole[i] == '%')
        {
        	if(whole[i+1] == '+' || whole[i+1] == '-' || whole[i+1] == '=' || whole[i+1] == '&' || whole[i+1] == '|')
        	    opr[j++]=whole[i];
        	else{
        		opr[j++]=whole[i];
        		opr[j++]=' ';
			}
		}
		else if(whole[i] == ';' || whole[i] == ',' || whole[i] == '(' ||  whole[i] == ')' || whole[i] == '{' ||  whole[i] == '}' 
		|| whole[i] == '[' ||  whole[i] == ']' || whole[i] == '"' || whole[i] == '\'') 
		{
        	sep[k++]=whole[i];		
        	sep[k++]=' ';
        }
        else{
        	idn[l++]=whole[i]; 	
		}   
	}
	
	fputs(opr,fpo);
	fputs(sep,fps);
	fputs(idn,fpi);	
	 
	fclose(fpc);
	fclose(fpo); 
	fclose(fps);
	fclose(fpi);
	fclose(fptr); 
	
	//further dividing identifiers-header files,keywords,variables
	fpi = fopen("identifiers.txt","r") ;
	
	FILE *fph,*fpk,*fpv,*fpco; 
	
	fph = fopen("headers.txt","w") ;
	fpk = fopen("keywords.txt","w") ;
	fpv = fopen("variables.txt","w") ;//variables,functions,comments and printf 
	
	char token[MAX];

	while(fscanf(fpi, "%s", token)!=EOF)
	{
		//printf("%s\n", token); //printing each token
		if (!strcmp(token, "if") || !strcmp(token, "else") || !strcmp(token, "while") || !strcmp(token, "do") || !strcmp(token, "for") || !strcmp(token, "break") 
		|| !strcmp(token, "continue") || !strcmp(token, "int") || !strcmp(token, "double") || !strcmp(token, "float") || !strcmp(token, "return") 
		|| !strcmp(token, "char") || !strcmp(token, "case") || !strcmp(token, "bool") || !strcmp(token, "sizeof") || !strcmp(token, "long") || !strcmp(token, "short") 
		|| !strcmp(token, "typedef") || !strcmp(token, "switch") || !strcmp(token, "unsigned") || !strcmp(token, "void") || !strcmp(token, "static") 
        || !strcmp(token, "struct") || !strcmp(token, "goto") || !strcmp(token, "printf") || !strcmp(token, "scanf") || !strcmp(token, "main") 
		|| !strcmp(token, "#include")) 
			fprintf(fpk,"%s\n",token);
		else if(!strcmp(token,"stdio.h")||!strcmp(token,"conio.h")||!strcmp(token,"string.h"))
			fprintf(fph,"%s\n",token);
		else
			fprintf(fpv,"%s\n",token);
	}
		
	fclose(fph); 
	fclose(fpk); 
	fclose(fpv);
	fclose(fpi);
	
	getch();
	return 0; 
}
