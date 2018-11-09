/*
  A -> I = E | E
  E -> T + E | T - E | T
  T -> F * T | F / T | F
  F -> P ^ F | P
  P -> I | L | UI | UL | (A)
  U -> + | - | !
  I -> C | CI
  C -> a | b | ... | y | z
  L -> D | DL
  D -> 0 | 1 | ... | 8 | 9
*/

#include <cstdio>
#include <cstdlib>

#define U *s == '+' || *s == '-' || *s == '!'
#define C *s >= 'a' && *s <= 'z'
#define D *s >= '0' && *s <= '9'

bool A(void);
bool E(void);
bool T(void);
bool F(void);
bool P(void);
bool I(void);
bool L(void);

char *s;

int main(int argc, char *argv[])
{
    FILE* fd = fopen("input.txt", "r");
    if(fd == NULL)
    {
        fputs("Unable to open input.txt\n", stderr);
        exit(EXIT_FAILURE);
    }

    size_t length = 0;
    ssize_t read;
    const char* backup;

    while ((read = getline(&s, &length, fd) ) > 0)
    {
        backup = s;
        if (A() && *s == '\n')
        {
            printf("%s is in the language\n", backup);
        }
        else
        {
            fprintf(stderr, "%sis not in the language\n", backup);
        }
    }
    fclose(fd);

    return 0;
}

// A -> I = E | E
bool A(void)
{

    if (I())
    {
        if (*s == '=') ++s;
    }
    return E();
}

// E -> T + E | T - E | T
bool E(void)
{

    if (T())
    {
        if (*s == '+' || *s == '-')
        {
            ++s;
            return E();
        }
        return true;
    }

    return false;
}

// T -> F * T | F / T | F
bool T(void)
{

    if (F())
    {
        if(*s == '*' || *s == '/')
        {
            ++s;
            return F();
        }
        return true;
    }
    return false;
}

// F -> P ^ F | P
bool F(void)
{
    if(P())
    {
        if(*s == '^')
        {
            ++s;
            return F();
        }
        return true;
    }
    return false;
}


// P -> I | L | UI | UL | (A)
bool P(void)
{
    if(I() || L()) return true;
    else if (U)    return I() || L();
    else if (*s == '(')
    {
        ++s;
        if(A())
        {
    if(*s == ')') {
            ++s;
            return true;
	  }
        }
    }

    return false;
}

// I -> C | CI
bool I(void)
{

    if (C)
    {
        ++s;
        I();
        return true;
    }

    return false;
}

// L -> D | DL
bool L(void)
{

    if (D)
    {
        ++s;
        L();
        return true;
    }

    return false;
}

