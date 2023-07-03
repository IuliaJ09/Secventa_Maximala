#include <stdlib.h>
#include <stdio.h>
int main()
{
	FILE* f, * g;
	int n, v[100000], i,j,l,s[100000],nr=1,maxx=0;
	f = fopen("pb28in.txt", "rt");
	g = fopen("pb28out.txt", "wt");
	fscanf(f, "%d", &n);
	for (i = 0; i < n; i++)
		fscanf(f, "%d", &v[i]);
	fscanf(f, "%d", &l);
	for(i=0;i<l;i++)
		fscanf(f, "%d", &s[i]);
	for (i = 0; i < l; i++)
	{
		for (j=s[i];j<n-1;j++)
		{
			if (v[j] < v[j + 1])
				nr++;
			else
			{
				if (maxx < nr)
					maxx = nr;
				nr = 0;
			}
		}
		if (maxx < nr)
			maxx = nr;
		fprintf(g, "%d\n", maxx);
		maxx = 0;
		nr = 0;
	}
	fclose(f);
	fclose(g);
	
	return 0;
}