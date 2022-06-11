#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int checkword(const char* word)
{
    char *str_num[] = 
    { "zero","one","two","three" ,"four" ,
        "five" ,"six" ,"seven" ,"eight" ,"nine" };
    for (int i = 0; i < 10; ++i)
    {
        if (strncmp(word, str_num[i],strlen(str_num[i])) == 0)
            return i;
    }

    return -1;
}

int solution(const char* s) {
    int answer = 0;

    char ch = 0;
    int j = 0;
    int count = 0;
    char word[10] = "\0";

    int ret_value = -1;
    int result = 0;
    while (ch = *s)
    {
        if ('0' <= ch && ch <= '9')
        {
            result *= 10; //shift ¿¬»ê
            result += (ch - '0');
        }
        else if( 'a' <= ch && 'z' >= ch)
        {
             word[j++] = ch;
        }
        ret_value = checkword(word);
        if (-1 != ret_value)
        {
            result *= 10;
            result += ret_value;
            j = 0;
            memset(word, 0, 10 * sizeof(char));
        }

        s++;
    }

    answer = result;
    return answer;
}

int main()
{
    char str[] = "one4seveneight";
    char str2[] = "four00zero";
    char str3[] = "1zerotwozero3";
    char str4[] = "2three45sixsevennine";
    char str5[] = "sevensevenseven3sevensevensevenseven";

    printf("%d\n", solution(str2));
    printf("%d\n", solution(str4));
    printf("%d\n", solution(str5));
    return 0;
}