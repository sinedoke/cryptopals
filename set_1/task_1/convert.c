#include <stdio.h>
#include <stdlib.h>


char* hex_to_base64(char *hex, int size)
{
    int size64 = (size * 2) / 3.0;
    size64 += 1;
    char *base64 = calloc(size64, 1);
    size64 -= 1;
    for (int i = size-1; i>= 0; i-=3, size64-=2) {
        base64[size64] |= hex[i];
        if (i > 0) {
            base64[size64] |= ((hex[i - 1] << 4) & 0x3F); //0x3F is 00111111
            base64[size64 - 1] |= (hex[i - 1] >> 2);
        }
        if (i > 1) {
            base64[size64 - 1] |= ((hex[i - 2] << 2));
        }
    }
    return base64;
}



int main(int argc, char **argv)
{
    int i = 0;
    //49276D206B696C6C696E6720796F757220627261696E206C696B65206120706F69736F6E6F7573206D757368726F6F6D
    char input[] = { 4, 9, 2, 7, 6, 13, 2, 0, 6, 11, 6, 9, 6, 12, 6, 12, 6, 9, 6, 14, 6, 7, 2, 0, 7, 9, 6, 15, 7, 5, 7, 2, 2, 0, 6, 2, 7, 
        2, 6, 1, 6, 9, 6, 14, 2, 0, 6, 12, 6, 9, 6, 11, 6, 5, 2, 0, 6, 1, 2, 0, 7, 0, 6, 15, 6, 9, 7, 3, 6, 15, 6, 14, 6, 15, 7, 5, 7, 3, 
        2, 0, 6, 13, 7, 5, 7, 3, 6, 8, 7, 2, 6, 15, 6, 15, 6, 13 };
    char *output;
    int outputsize = ((sizeof(input)* 2) / 3.0) + 1;
    char *text = calloc(outputsize + 1, 1);
    char *formatted;
    output = hex_to_base64(input, sizeof(input));
    for (i = outputsize-1; i >=0; i--) {
        if (output[i] < 26) {
            text[i] = output[i] + 65;
        }
        else if (output[i] < 52) {
            text[i] = output[i] + 97 - 26;
        }
        else if (output[i] < 62) {
            text[i] = output[i] + 48 - 52;
        }
        else if (output[i] == 62) {
            text[i] = '+';
        }
        else if (output[i] == 63) {
            text[i] = '/';
        }
    }
    i = 0;
    formatted = text;
    while (text[i++] == 'A') {
        formatted++;
    }
    printf("%s\n", formatted);
    free(text);
    return 0;
}
