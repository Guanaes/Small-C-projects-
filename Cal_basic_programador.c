#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    int x = 0, y, var, line = 0, bi[35][4];
    char ch;
    

    setlocale(LC_ALL, "Portuguese");

    printf("Calculadora de programador.\n--------------------\n");
    printf("Entre com '.' para terminar\n--------------------\n");
    printf("%d\n", x);
    
    for ( ;; )
    {
        
       scanf(" %c", &ch);

        /*Caso leia '.' para o loop.*/
        if(ch == '.') break;
        
        scanf("%d", &y);   

        switch (ch)
        {
        case '+':
            x = x + y;
            break;
        case '-':
            x = x - y;
            break;
        case '/':
            x= x / y;
            break;
        case '*':
            x = x * y;
            break;
        default:
            printf("\nOperador não é valído.\nEntre com operadores matemáticos simples.\n");
            break;
        }    
        printf("%d\n", x);
    }
   
    /*Binário*/
    var = x;

    for (int i = 0; i <35; i++)
    {
        for (int j = 0; j < 4; j++)
        {
           /*Salva resto da aperação em uma matriz int*/
            if (var == 1 && j < 3)
            {
                bi[i][j] = 1;
                var = 0;
                j++;
            }
            else if (var == 1 && j ==3)
            {
                bi[i][j] = 1;
                var = 0;
                break;
            }
            
            bi[i][j]= var % 2;
            var = var / 2;
        }
        if (var == 0)
        {
            break;
        }
        line ++;
    }
     
    printf("\n--------------------\nValor em decial: %d.\n", x);

    printf("Valor em binario: ");
    for (int i = line; i >= 0; i--)
    {
        for (int j = 3; j >= 0; j--)
        {
            printf("%d", bi[i][j]);
        }
        if(i) printf(" ");
    }
    


    /*Hexadecimal*/
    printf(".\nValor em Hexadecimal: ");

    y = 0;
    for (int i = line; i >= 0; i--)
    {
        for (int j = 3; j >= 0; j--)
        {
            y = y + (pow(2, j) * bi[i][j]);
        }
        if(y <= 9)
        {
            printf("%d", y);
        }
        else
        {
            switch (y)
            {
                case 10:
                    printf("A");
                    break;
                case 11:
                    printf("B");
                    break;
                case 12:
                    printf("C");
                    break;
                case 13:
                    printf("D");
                    break;
                case 14:
                    printf("E");
                    break;
                case 15:
                    printf("F");
                    break;               
            }
        }
        y = 0;
    }
    printf(".");
}