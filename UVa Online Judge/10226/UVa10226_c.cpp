#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char line[32];
char name[1000000][32];
int sorted[1000000];
int cmp(const void *p1, const void *p2);

int main()
{
	int n;
	scanf("%d", &n);
	fgets(line, 32, stdin);
	fgets(line, 32, stdin);
	for(int c = 0;c < n;c++)
	{
		int count = 0;
		while(fgets(name[count], 32, stdin))
		{
			if(name[count][0]=='\n')
				break;
			int len = strlen(name[count]);
			name[count][len-1]='\0';
			count++;
		}
		for(int i = 0;i < count;i++)
		{
			sorted[i]=i;
		}
		qsort(sorted,count,sizeof(int),cmp);
		if(c > 0)
			printf("\n");

		int subcount = 1;
		printf("%s ",name[sorted[0]]);
		for(int i = 1;i < count;i++)
		{
			char *str0 = name[sorted[i-1]];
			char *str1 = name[sorted[i]];
			if(strcmp(str0,str1)==0)
			{
				subcount++;
			}
			else
			{
				printf("%.4f\n",100.0*subcount/count);
				subcount = 1;
				printf("%s ",name[sorted[i]]);
			}
		}
		printf("%.4f\n",100.0*subcount/count);
	}
	return 0;
}



int cmp(const void *p1, const void *p2)
{
	int i1 = *(int*)p1;
	int i2 = *(int*)p2;
	return strcmp(name[i1],name[i2]);
}
