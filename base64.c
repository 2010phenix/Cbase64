/* base64 - a lib of the base64 encoding and decoding.  */
/* Written by Hapo, wuyichao71@126.com.  */
#include <stdio.h>
#include <string.h>

/* If you just to test it.  */
#ifndef HAVE_BASE64_H
# include "base64.h"
#endif  

/* The author of the program.  */
#define AUTHOR "Hapo"
/* The name of the program .  */
#define PROGRAM_NAME "base64"

/*const char *_strtable = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\
abcdefghijklmnopqrstuvwxyz0123456789+/";
*/

void
base64_encode(char *out, char *in, int maxlen)
{
    int len = strlen(in);
    int i, j;
    char c;
    for (i=0, j=0; i<len && j+4<maxlen; i+=3, j+=4)
        switch (c = (len - i) >= 3 ? 3:(len - i))
        {
            case 3:
                out[j+3] = _strtable[in[i+2] & 0x3f];
            case 2:
                out[j+2] = _strtable[(in[i+1] & 0xf) << 2 | in[i+2] >> 6];
            case 1:
                out[j+1] = _strtable[(in[i] & 0x3) << 4 | in[i+1] >> 4];
                out[j] = _strtable[in[i] >> 2];
        }
    switch (c)
    {
        case 1:
            out[j-2] = '=';
        case 2:
            out[j-1] = '=';
    }
    out[j] = '\0';
}

void
base64_decode(char *out, char *in, int maxlen)
{
    int len = strlen(in);
    char c;
    int i, j;
    for (i = 0, j = 0; i < len && j + 3 < maxlen; i += 4, j += 3)
    {
        c = (in[i+3] == '=') + (in[i+2] == '=');
        switch (c)
        {
            case 0:
                out[j+2] = (tablechr(in[i+2]) & 0x3) << 6 |\
                tablechr(in[i+3]);
            case 1:
                out[j+1] = (tablechr(in[i+1]) & 0xf) << 4 |\
                    tablechr(in[i+2]) >> 2;
            case 2:
                out[j] = tablechr(in[i]) << 2 | tablechr(in[i+1]) >> 4;
        }
    }
    out[j-c] = '\0';
}
