#include "monty.h"

void begin_interpret(iptr_data *data)
{
	printf("Time to decode!!!!, fd: %d\n", data->fd);

	close(data->fd);
}
