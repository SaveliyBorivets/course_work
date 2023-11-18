#include "func_vvod_text.h"
#include "struct.h"

struct Text func_vvod_text() {
    setlocale(LC_ALL,"ru_RU.UTF-8");
    int count_sen = 0, M = 20;
    wchar_t **text = (wchar_t **) malloc(sizeof(wchar_t*) * M);
    wchar_t ch;
    for (int j = 0;; j++) {
        int N = 20, count_ch = 0, flag = 0;//флаг для \n
        wchar_t *sen = (wchar_t *) malloc(sizeof(wchar_t) * N);
        for (int i = 0; (ch = getwchar()) != '.'; i++) {
            if (ch == '\n') {
                if (flag) {
                    break;
                }
                flag = 1;
                i--;
                continue;
            }
            flag = 0;
            sen[i] = ch;
            count_ch++;
            if (count_ch == N) {
                N += 20;
                sen = (wchar_t *) realloc(sen, sizeof(wchar_t) * N);
            }
        }
        if (flag) {
            break;
        }
        sen[count_ch] = '.';
        count_ch++;
        if (count_ch == N) {
            N += 20;
            sen = realloc(sen, sizeof(wchar_t) * N);
        }
        sen[count_ch] = '\0';
        text[j] = sen;
        count_sen++;
        if (count_sen == M) {
            M += 20;
            text = realloc(text, sizeof(wchar_t*) * M);
        }
    }
    struct Text vvod_text = {text, count_sen};
    return vvod_text;
}