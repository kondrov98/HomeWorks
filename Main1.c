#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void CesarCod(char* message, char* alphabet, int key)
{
	int i = 0;
	while (message[i] != '\0')
	{
		if (message[i] == ' ')
		{
			int j = i;
			while (message[j] != '\0')
			{
				message[j] = message[j + 1];
				j++;
			}
		}
		else
		{
			for (int k = 0; k < 26; k++)
			{
				if (message[i] == alphabet[k])
				{
					
					if (k >= 26 - key)
					{
						message[i] = alphabet[k - 26 + key];
					}
					else
					{
						message[i] = alphabet[k + key];
					}
					k = 26;
				}
			}
			i++;
		}
	}
}

void CesarDeCod(char* message, char* alphabet, int key)
{
	int i = 0;
	while (message[i] != '\0')
	{
			for (int k = 0; k < 26; k++)
			{
				if (message[i] == alphabet[k])
				{

					if (k < key)
					{
						message[i] = alphabet[26 + k - key];
					}
					else
					{
						message[i] = alphabet[k - key];
					}
					k = 26;
				}
			}
			i++;
	}
	printf("%i\n",i);
}


int main()
{
 int key = 5;
 char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
 const int SIZ = 400;
 char* arr = (char*)malloc(sizeof(char) * SIZ);
 printf("Enter a message!\n");
 fgets(arr, SIZ, stdin);
 CesarCod(arr, alphabet, key);
 printf("Cesar Encoding: %s\n", arr);
 CesarDeCod(arr, alphabet, key);
 printf("Cesar Decoding: %s\n", arr);
}