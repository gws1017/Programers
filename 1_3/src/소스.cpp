//#include <string>
//#include <vector>
//
//using namespace std;
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int checkword(const char* word)
{
    char str_num[10][10] = 
    { "zero","one","two","three" ,"four" ,
        "five" ,"six" ,"seven" ,"eight" ,"nine" };
    for (int i = 0; i < 9; ++i)
    {
        if (strcmp(word, str_num[i]) == 0)
            return i;
    }

    return -1;
}

int solution(const char* s) {
    int answer = 0;
    
    int i = 0;
    int j = 0;
    int count = 0;
    int words[50] = { 0 };
    char word[10] = "\0";

    int ret_value = -1;

    while (s[i] != '\0')
    {
        if (s[i] != ' ' || s[i] != '\0')
        {
            if ('1' <= s[i] && s[i] <= '9')
            {
                words[count++] = s[i] - '0';
            }
            else
            {
                word[j++] = s[i];
            }
            ret_value = checkword(word);
            if (-1 != ret_value)
            {
                words[count++] = ret_value;
                j = 0;
                memset(word, 0, 10 * sizeof(char));
            }
        }
        
        i++;
    }
    for (int k = 0, m = count; m > 0; k++, m--)
    {
        int pow_value = 1;
        for (int l = 0; l < m -1; l++)
        {
            pow_value *= 10;
        }
        answer += words[k] * pow_value;

    }
    return answer;
}

int main()
{
    char str[] = "one4seveneight";
    char str2[] = "foursix";
    char str3[] = "1zerotwozero3";
    char str4[] = "2three45sixseven";
    char str5[] = "123";

    printf("%d\n", solution(str2));
    printf("%d\n", solution(str4));
    printf("%d\n", solution(str5));
    return 0;
}