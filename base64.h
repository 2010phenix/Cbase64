#include <string.h>

#define HAVE_BASE64_H 1
#define istrchr(A, B) (strchr((A), (B)) - A)
#define tablechr(A) istrchr(_strtable, (A))

static const char *_strtable = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\
abcdefghijklmnopqrstuvwxyz0123456789+/";

/*encode string to base64.  */
void
base64_encode(char *out, char *in, int maxlen);

/*decode base64 to string.  */
void
base64_decode(char *out, char *in, int maxlen);
