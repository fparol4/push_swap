#include "../main.h"

// Mesmo que eu não saiba eu preciso agir.
// Agir sem saber = coragem.
// Agir sem ter certeza = confianca.
// Agir sem ter certeza do resultado = Fé
// Agir é o remédio
// Acão é o verdadeiro remédio desta vida.
// Apenas através da acão.
// Não me importa o que o buddha pensava.
// Nem a indicacão de ninguém
// Eu sei que a única saída é a acão
// e a simplicidade do pensamento

t_option get_best_option(t_stack one, t_stack two)
{
	int i = 0;
	t_option best_option;
	while (i < one.size)
	{
		t_target_cost item_c = get_target_cost(one, i);
		t_target_cost target_c = get_minmax_cost(two, one.items[i]);
		t_option transfer_option = get_option(item_c, target_c);
		if (i == 0 || transfer_option.cost < best_option.cost)
			best_option = transfer_option;
		i++;
	}
	return best_option;
}

void push_swap(t_stack one, t_stack two)
{
	// 1. Ordenar do A para o B até que sobrem 3.
	// 2. Ordenar os 3 que sobrarem no A.
	// 3. Trazer de volta do B para o A.

	char *steps[196];
	while (one.size > 2)
	{
		t_option option = get_best_option(one, two);

	}
}

int main()
{
	t_stack s_one = {
		.id = STACK_ONE, .size = 3,
		.items = (int[7]){ 4, 3 }
	};
	t_stack s_two = {.id = STACK_TWO, .size = 4,
		.items = (int[7]){2, 1, 7, 6, 5}
	};
	push_swap(s_one, s_two);
}
