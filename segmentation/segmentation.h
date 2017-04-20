// segmentation.h

# ifndef SEGMENTATION_H_
# define SEGMENTATION_H_

# include <SDL/SDL.h>
# include <SDL/SDL_image.h>

# include "pixel_operations.h"
# include "list/list.h"

void buildLinesList(SDL_Surface *img, struct list *lines);
void buildColumnsList(SDL_Surface *img, struct list *columns);

# endif
