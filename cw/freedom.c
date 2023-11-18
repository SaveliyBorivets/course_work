#include "freedom.h"
#include "struct.h"

void freedom(struct Text text) {
    for (int i = 0; i < text.cnt_sen; i++) {
        free(text.txt[i]);
    }
  free(text.txt);
}