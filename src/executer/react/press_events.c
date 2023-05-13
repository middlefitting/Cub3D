#include "execute.h"

// void	default_event(int key_num, t_data *data)
// {
// 	(void) key_num;
// 	(void) data;
// }

// void	press_event(int key_num, t_data *data)
// {
// 	data->press[key_num] = TRUE;
// }

// void	esc_event(int key_num, t_data *data)
// {
// 	press_event(key_num, data);
// 	finish_game(0);
// }

// void	init_press_events(void (*events[])(int, t_data*))
// {
// 	int	ind;

// 	ind = 0;
// 	while (ind < 256)
// 		events[ind++] = press_event;
	// events[ESC] = esc_event;
// }

int	press_events(int key_num, t_data *data)
{
	// void	(*events[256])(int, t_data*);

	if (key_num < 256)
		data->press[key_num] = TRUE;
	// init_press_events(events);
	// if (key_num < 256)
	// 	events[key_num](key_num, data);
	return (0);
}
