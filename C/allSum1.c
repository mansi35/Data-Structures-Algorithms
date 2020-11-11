#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int totalSum = 0;
    char strSum[100];
    double floatSum = 0;
    int flag = 0;
	
	if(argc < 1)
	{
		printf("0\n");
		return 0;
	}

	for(int i = 1; i < argc; i++) {
        for (int j = 0; j < strlen(argv[i]); j++) {
            if ((argv[i][j] >= 97 && argv[i][j] <= 122) || (argv[i][j] >= 65 && argv[i][j] <= 90)) {
                flag = 1;
                break;
            }

            else if (argv[i][j] == 46) {
                flag = 2;
                break;
            }
        }
    }

	for(int i = 1; i < argc; i++)
	{
        if (flag == 1) {
            strcat(strSum, argv[i]);
        }

        else if (flag == 2) {
            floatSum += atof(argv[i]);
        }

        else {
		    totalSum += atoi(argv[i]);
        }
	}
	if (flag == 1) {
        printf("%s\n", strSum);
        return 0;
    }

    else if (flag == 2) {
        printf("%f\n", floatSum);
        return 0;
    }

	printf("%d\n", totalSum);
	
	return 0;
}