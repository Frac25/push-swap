	int		i;
	int		somme_p;
	int		valeur_p;
	t_nod	*location_t;
	int		min;


	i = 0;
	location_t = table->location;
	min = location_t->discret;
	while (i < table->size)
	{
		if(min > location_t->discret)
			min = location_t->discret;
		location_t = location_t->next;
		i++;
	}
