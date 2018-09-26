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
#  define A		0
#  define ZERO		82
#  define ONE		83
#  define TWO		84
#  define THREE		85
#  define FOUR		86
#  define FIVE		87
#  define SIX		88
#  define SEVEN		89
#  define EIGHT		91
#  define NINE		92
#  define NBR_COND(x)	(x >= 82 && x <= 92 && x != 90)
# else
#  define ESCAPE	65307
#  define PLUS		65451
#  define MINUS		65453
#  define TOP		65361
#  define RIGHT		65362
#  define BOTTOM	65363
#  define LEFT      65364
#  define ARROW_COND(x)	(x >= 65361 && x <= 65364)
#  define A		97
#  define ZERO		65438
#  define ONE		65436
#  define TWO		65433
#  define THREE		65435
#  define FOUR		65430
#  define FIVE		65437
#  define SIX		65432
#  define SEVEN		65429
#  define EIGHT		65431
#  define NINE		65434
#  define NBR_COND(x)	(x >= 65429 && x<= 65438)
#  define E         101
#  define R         114
#  define T         116
#  define Y         121
#  define U         117
#  define I         105
# endif

#endif
