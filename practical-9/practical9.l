:%{
#include "y.tab.h"
%}

%%

i       { return I; }
t       { return T; }
e       { return E_SYM; }
b       { return B; }
a       { return A; }

\n      { return 0; }      /* End input on Enter */
<<EOF>> { return 0; }      /* Handle EOF */

[ \t]   ;                  /* Ignore spaces */

.       { return yytext[0]; }

%%

int yywrap() {
    return 1;
}