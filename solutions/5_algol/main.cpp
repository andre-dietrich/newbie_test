#include "header.h"

INT compare(STRING s1, STRING s2)
BEGIN
    WHILE *s1++ == *s2
    DO IF *s2++ == 0
        THEN return (0);
        FI
    OD
    return (*--s1 - *s2);
END

int main() {
	printf("compare(\"string1\", \"string2\") = %d\n", compare("string1","string2"));
	printf("compare(\"string1\", \"string1\") = %d\n", compare("string1","string1"));
	printf("compare(\"string2\", \"string1\") = %d\n", compare("string2","string1"));
}
