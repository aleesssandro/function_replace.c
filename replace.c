#include <stdio.h>
#include <stdlib.h>



int main() {
    char del;
    printf("Enter a delimiter: \n");
    scanf("%c", &del);
   while (getchar() != '\n');


   char *s = (char *)malloc(1086 * sizeof(char));
    if (s == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }


    printf("Enter a string: \n");
    fgets(s, 1086, stdin);

    int s_len = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
       s_len++;
    }
    if (s[s_len - 1] == '\n') {
        s[s_len - 1] = '\0';
        s_len--;
    }

    int count_word = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == del || i == s_len - 1) 
        {
           count_word++;
        }
    }
    
    char **result = (char**)malloc(count_word * sizeof(char*));
    if (!result) {
        printf("memory allocation failed.\n");
        free(s);
        return 1;
    }

    int count_index = 0;
    int j = 0;
    int start_index = 0;

    for (int i = 0; i < s_len; i++)
    {
        if (s[i] != del || s[i] == '\0')  
        {
            count_index++;
        }
        

        if (s[i] == del || i == s_len - 1) 
        {
            result[j] = (char*)malloc((count_index + 1) * sizeof(char));
            if (!result[j])
            {
                for (int y = 0; y < j; y++)
                {
                    free(result[y]);
                }
                
              printf("Memory allocation failed.\n");
              free(s);
              free(result);
              return 1;
            }

              for (int z = 0; z < count_index; z++)
            {
                result[j][z] = s[z + start_index];
            }


        result[j][count_index] = '\0';
        start_index = i + 1;
        count_index = 0;
        j++;
        }
    }

    printf("Original string: \n");
    printf("%s\n", s);


    for (int i = 0; i < count_word; i++)
    {
        printf("string[%d]: %s\n", i, result[i]);
    }
    

    free(s);
    for (int i = 0; i < count_word; i++)
    {
        free(result[i]);
    }
    free(result);  
    return 0;
}