#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <errno.h>

#include <X11/X.h>
#include <X11/keysym.h>
#include "mlx.h"

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_WID 106
# define TILE_HEI 106
# define ANIMATION_SPEED 100
# define PLAYER_FRAME 6
# define WINDOW_WID 1481
# define WINDOW_HEI 635
# define BUFFER_SIZE 10 
# define W 119
# define D 100
# define A 97
# define S 115
# define ESC 65307
# define IMG mlx_put_image_to_window
# define WIN mlx_new_window


typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_mlx
{
	char **map;
	void *mlx;
	void *win;
	void *player_img[PLAYER_FRAME];
	void *background_img;
	void *collectible_img[6];
	void *exit_img;
	void *wall_img;
	void *empty_img;
	int current_frame;
	int player_x;
	int player_y;
	int map_wid;
	int map_hei;
	int collectible;
	int moves;
}   t_data;

int		found_newline(t_list *list);
t_list	*find_lst_node(t_list *list);
char	*get_line(t_list *list);
void	copy_str(t_list *list, char *str);
int		len_to_newline(t_list *list);
void	polish_list(t_list **list);
char	*get_next_line(int fd);
void	dealloc(t_list **list, t_list *clean_node, char *buf);
void	create_list(t_list **list, int fd);
void	append(t_list **list, char *buf);
char 	**add_to_map(char **map, char *new_line);
int 	validate_map(t_data *data);
int 	validate_map_walls(char **map, t_data *data);
int		window_init(t_data *data);
int 	key_press(int key, t_data *data);
void 	move_player(int dierection, t_data *data);
int 	exit_game(t_data *data, char *s);
int		error_mssg(char *s, int ERR_TYPE);
int		draw_game(t_data *data);   // Remember To Delete This  // Or Maybe Not
int		init_game(t_data *data);
int 	standar_animation(t_data *data);
void 	some_function(char **filenames);
int 	check_map_row_len(t_data *data);
int 	draw_background(t_data *data);
void 	collectible_function(char **filenames);
int init_player(t_data *data);
#endif /* SO_LONG_H  */