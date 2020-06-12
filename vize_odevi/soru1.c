  /*    
------ Soru 2  
------ Rayan Alheraki
------ G171210556
------ 2B
*/
  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <alloca.h>
#include <string.h>         
 typedef unsigned long int UI;

extern etext;
extern edata;
extern end;


int main(int argc, char **argv)
{
                           
	  
	int satir=0;
	int heapSatri;
	int stackSatri;
	char *a,*b,*c,*d;
	FILE* file = fopen("/proc/self/smaps", "r"); 
	char line[350];
	printf("data bölümü  : başlangıç= 0x%lx , boyut= %ld byte\n",(UI) &etext+1, (&end)-(&etext));

    while (fgets(line, sizeof(line), file)) 
	{
		satir++;
		a=strstr(line,"heap" );
		b=strstr(line,"Size:" );
		c=strstr(line,"stack" );
		if(a)
		{
			heapSatri=satir;
			char * token  = strtok(line, "-"); 
	
			printf("heap bölümü : başlangıç= 0x%s", token);
		}
		if(b && (satir ==heapSatri+1))
		{
			int x;
			int sayac=0;
			int boyut=0 ;
			for(int i =23 ; i >=20;i--){
				if(line[i] != ' ')
				{
				x=line[i]-'0';
					if(sayac==0)
					{
						boyut=boyut+x*1;
					}
					else if(sayac==1)
					{
						boyut=boyut+x*10;
					}
					else if(sayac==2)
					{
						boyut=boyut+x*100;
					}
					else if(sayac==3)
					{
						boyut=boyut+x*1000;
					
					}
					sayac++;
				}
			}
			printf(", boyut = %d byte\n", boyut*1024); 
		}
		                                        
		if(c)
		{
			stackSatri=satir;
			char * token1  = strtok(line, "-"); 
	 
			printf("stack bölümü : başlangıç= 0x%s ", token1);
		}
		if(b && (satir ==stackSatri+1))
		{
			int x;
			int sayac=0;
			int boyut=0 ;
			for(int i =23 ; i >=20;i--)
			{
				if(line[i] != ' ')
				{
				x=line[i]-'0';
					if(sayac==0)
					{
						boyut=boyut+x*1;
					}
					else if(sayac==1)
					{
						boyut=boyut+x*10;
					}
					else if(sayac==2)
					{
						boyut=boyut+x*100;
					}
					else if(sayac==3)
					{
						boyut=boyut+x*1000;
					
					}
					sayac++;
				}
			}
			printf(", boyut =%d byte\n", boyut*1024); 
		}
		
	}
	
	    fclose(file);

	return 0 ; 
}