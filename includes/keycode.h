#ifndef KEYCODE_H
# define KEYCODE_H

# ifdef __APPLE__
#  define ESCAPE	53
#  define PLUS		69
#  define MINUS		78
#  define TOP		123
#  define BOTTOM	124
#  define LEFT		125
#  define RIGHT		126
#  define ARROW_COND(x)	(x >= 123 && x <= 126)
# else
#  define ESCAPE	65307
#  define PLUS		65451
#  define MINUS		65453
#  define LEFT		65361
#  define TOP		65362
#  define RIGHT		65363
#  define BOTTOM	65364
#  define ARROW_COND(x)	(x >= 65361 && x <= 65364)
# endif

#endif
