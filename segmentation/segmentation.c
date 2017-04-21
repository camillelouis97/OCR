// segmentation.c

# include "segmentation.h"

void buildLinesList(SDL_Surface *img, struct list *lines) {
	int i = j = 0;
	int isText = 0;

	while(j < img->h) {
		i = 0;
		if(isText) {
			while(i < img->w && getpixel(img, i, j) == SDL_MapRGB(img->format,
                                                            255, 255, 255))
				i++;
			if(i == img->w) {
				struct list *tmp = malloc(sizeof(struct list));
				list_init(tmp);
				tmp->data = i;
				list_insert(lines, tmp);
			}
		} else {
			while (i < img->w && getpixel(img, i, j) == SDL_MapRGB(img->format,
                                                             255, 255, 255))
				i++;
			if(i != img->w) {
				struct list *tmp = malloc(sizeof(struct list));
				list_init(tmp);
				tmp->data = i;
				list_insert(lines, tmp);
			}
		}
		j++;
	}
}

void buildColumnsList(SDL_Surface *img, struct list *columns) {
  int i = j = 0;
  int isText = 0;

  while(i < img->w) {
    j = 0;
    if(isText) {
      while(j < img->h && getpixel(img, i, j) == SDL_MapRGB(img->format,
                                                            255, 255, 255))
        j++;
      if(i == img->h) {
        struct list *tmp = malloc(sizeof(struct list));
				list_init(tmp);
				tmp->data = i;
				list_insert(columns, tmp);
      }
    } else {
      while (j < img->h && getpixel(img, i, j) == SDL_MapRGB(img->format,
                                                             255, 255, 255))
				j++;
			if(j != img->h) {
				struct list *tmp = malloc(sizeof(struct list));
				list_init(tmp);
				tmp->data = i;
				list_insert(columns, tmp);
			}
    }
    i++;
  }
}

void buildCharsList(SDL_Surface *img, struct list *lines, struct list *columns,
                   struct *chars) {
  struct list _lines = lines->next;
  struct list _columns = columns->next;
  while(_lines->next) {
    while(_columns->next) {
      int width = _columns->next->data - _columns->data;
      int height = _lines->next->data - _lines->data;
      SDL_Surface *character = SDL_CreateRGBSurface(0, width, height, 32,
                                                    0, 0, 0, 0);// empty surface
      for(int i = _lines->data; i < _lines->next->data; i++) {
        for(int j = _columns->data; j < _columns->next->data; j++) {
          int x = i - _lines->data;
          int y = j - _columns->data;
          putpixel(character, x, y, getpixel(img, i, j)); // filled surface
        }
      }
      list_insert(chars, character); // insert the surface in the list chars
      _lines = _lines->next->next;
      _columns = _columns->next->next;
    }
  }
}
