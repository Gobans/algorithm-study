#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *str, const void *str1)
{
	char *aa = *((char **)str);
	char *bb = *((char **)str1);
	if(strlen(aa) == strlen(bb))
		return strcmp(aa,bb);
	else
		return (strlen(aa) > strlen(bb));
}

int main(void)
{
	int n;
	int *len;

	scanf("%d", &n);
	char **words;
	words = (char**)malloc(sizeof(char*) * (n + 1));
	len = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		words[i] = (char *)malloc(sizeof(char) * 51);
		len[i] = strlen(words[i]);
		scanf("%s", words[i]);
	}

	qsort(words,n,sizeof(words[0]),compare);

	printf("%s\n", words[0]);
	for(int j = 1; j<n; j++)
	{
		if(!strcmp(words[j], words[j-1]))
		{
			continue;
		}
		else
		{
			printf("%s\n", words[j]);
		}
	}
	return (0);
}
