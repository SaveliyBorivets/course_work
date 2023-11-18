#pragma once
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

struct Sentence {
    wchar_t *sen;
    int ln_sen;
};
struct Text {
    wchar_t **txt;
    int cnt_sen;
};