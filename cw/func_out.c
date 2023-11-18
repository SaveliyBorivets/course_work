#include "func_out.h"
#include "struct.h"

void func_out(struct Text text) {
    for (int i = 0; i < text.cnt_sen; i++) {
        wprintf(L"%ls\n", text.txt[i]);
    }
}