#include "libft.h"

void	ft_str_to_upper(void *name)
{
	char	*name_char;

	name_char = name;
	while (*name_char)
	{
		*name_char = ft_toupper(*name_char);
		name_char++;
	}
}

void	ft_display(t_list *poke_1)
{
	printf("========== Liste of POKE ==========\n");
	while (poke_1)
	{
		printf("Nom du poke: %s\n", (char *)(poke_1->content));
		poke_1 = poke_1->next;
	}
	printf("===============================\n\n");
}

void	del_func(void *elem)
{
	free(elem);
}


int	main(void)
{
	t_list	*poke_1;
	t_list	*poke_2;
	t_list	*poke_3;
	char	*carapuce;
	char	*drakofeu;
	char	*bulbizar;

	carapuce = strdup("carapuce");
	drakofeu = strdup("drakofeu");
	bulbizar = strdup("bulbizar");
	poke_1 = ft_lstnew(carapuce);
	poke_2 = ft_lstnew(drakofeu);
	poke_3 = ft_lstnew(bulbizar);


	ft_lstadd_front(&poke_2, poke_1);
	ft_lstadd_back(&poke_1, poke_3);
	ft_display(poke_1);
	printf("Nombre de poke: %d\n", ft_lstsize(poke_1));
	printf("Valeur de dernier poke: %s\n",
		(char *)(ft_lstlast(poke_1)->content));
	ft_lstiter(poke_1, &ft_str_to_upper);
	ft_display(poke_1);
	ft_display(poke_1);



	
	return (0);
}
