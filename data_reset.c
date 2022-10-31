#include<stdio.h>

typedef struct{
	int level_i;
	int pearls;
}TOOLS_SaveData;

void TOOLS_Save_Data(char* filename, TOOLS_SaveData* d)
{
	FILE* file;
	file = fopen(filename, "w");
	fwrite(d, sizeof(TOOLS_SaveData), 1, file);
	fclose(file);
}

int main()
{
	TOOLS_SaveData d = {0,0};
	TOOLS_Save_Data("resources/save.dat", &d);
	return 0;
}
