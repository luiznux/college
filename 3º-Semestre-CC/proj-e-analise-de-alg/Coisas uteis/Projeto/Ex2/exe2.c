/* strtok example */
#include <stdio.h>
#include <string.h>

int main (){
	separadorComTraco ();
}

int separadorComTraco ()
{
	char str[] ="a7-b4-c3";
	int i = 0;
    char *p = strtok (str, "-");
    char *array[3];

    while (p != NULL)
    {
        array[i++] = p;
        p = strtok (NULL, "-");
    }

    for (i = 0; i < 3; ++i)
        printf("%s\n", array[i]);

    return mostraString(array[0]);
}


int mostraString(str){
	char *string2 = str;
	int i = 0;
	for(i; i < 2; i++){
		if (isdigit(string2[i])){
			printf("%d",string2[i]);
		}
	}

}

