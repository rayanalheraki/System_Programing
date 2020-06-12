/*    
------ Soru 2  
------ Rayan Alheraki
------ G171210556
------ 2B
*/
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv)
{
	int satirNo=0;
	char* a,*b,*c,*d,*e,*j;
	char *guvensiz[5]={"strcpy","strcat","sprintf","gets(","getpw"};
	char *guvenli[5]={"strlcpy","strlcat","snprintf","fgets","getpwuid"};

	char const* const fileName = argv[2]; 
    FILE* file = fopen(fileName, "r"); 
    char line[256];

    while (fgets(line, sizeof(line), file)) {
		satirNo++;
		char * token ;
		token = strtok(line, "//"); //yorum satirlari almasin diye
		
		a=strstr(token,guvensiz[0] );
		b=strstr(token,guvensiz[1] );
		c=strstr(token,guvensiz[2] );
		d=strstr(token,guvensiz[3] );  j=strstr(token,"fgets");
		e=strstr(token,guvensiz[4] );
		if(a)
		{
		  	if(strcmp(argv[1], "-s") == 0)
				printf("Satır %d:  guvensiz komutu\n",satirNo);
			else if(strcmp(argv[1], "-r") == 0)
				printf("Satır %d: %s() kullanılmış, yerine %s() kullanmalısınız.\n",satirNo,guvensiz[0],guvenli[0]);

		}
		if(b)
		{
		  	if(strcmp(argv[1], "-s") == 0)
				printf("Satır %d:  guvensiz komutu\n",satirNo);
			else if(strcmp(argv[1], "-r") == 0)
				printf("Satır %d: %s() kullanılmış, yerine %s() kullanmalısınız.\n",satirNo,guvensiz[1],guvenli[1]);
		}
		if(c)
		{
		  	if(strcmp(argv[1], "-s") == 0)
				printf("Satır %d:  guvensiz komutu\n",satirNo);
			else if(strcmp(argv[1], "-r") == 0)
				printf("Satır %d: %s() kullanılmış, yerine %s() kullanmalısınız.\n",satirNo,guvensiz[2],guvenli[2]);
		}
		if(d&& !j)
		{
		  	if(strcmp(argv[1], "-s") == 0)
				printf("Satır %d: guvensiz komutu\n",satirNo);
			else if(strcmp(argv[1], "-r") == 0)
				printf("Satır %d: %s() kullanılmış, yerine %s() kullanmalısınız.\n",satirNo,guvensiz[3],guvenli[3]);
		}
		if(e)
		{
		  	if(strcmp(argv[1], "-s") == 0)
				printf("Satır %d: guvensiz komutu\n",satirNo);
			else if(strcmp(argv[1], "-r") == 0)
				printf("Satır %d: %s() kullanılmış, yerine %s() kullanmalısınız.\n",satirNo,guvensiz[4],guvenli[4]);
		}
    }

    fclose(file);

		return 0;
}
