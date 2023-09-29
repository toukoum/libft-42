#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Tes fonctions
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
size_t	ft_strlen(const char *s);
int	ft_toupper(int c);
int	ft_tolower(int c);

int main()
{
    // Test pour ft_isalpha
    printf("ft_isalpha('a') = %d, isalpha('a') = %d\n", ft_isalpha('a'), isalpha('a'));

    // Test pour ft_isdigit
    printf("ft_isdigit('1') = %d, isdigit('1') = %d\n", ft_isdigit('1'), isdigit('1'));

    // Test pour ft_isalnum
    printf("ft_isalnum('a') = %d, isalnum('a') = %d\n", ft_isalnum('a'), isalnum('a'));

    // Test pour ft_isascii
    printf("ft_isascii(127) = %d, isascii(127) = %d\n", ft_isascii(127), isascii(127));

    // Test pour ft_isprint
    printf("ft_isprint(' ') = %d, isprint(' ') = %d\n", ft_isprint(' '), isprint(' '));

    // Test pour ft_strlen
    printf("ft_strlen(\"Hello\") = %zu, strlen(\"Hello\") = %zu\n", ft_strlen("Hello"), strlen("Hello"));

    // Test pour ft_toupper
    printf("ft_toupper('a') = %c, toupper('a') = %c\n", ft_toupper('a'), toupper('a'));

    // Test pour ft_tolower
    printf("ft_tolower('A') = %c, tolower('A') = %c\n", ft_tolower('A'), tolower('A'));

    return 0;
}
