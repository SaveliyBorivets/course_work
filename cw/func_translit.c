#include "func_translit.h"
#include "struct.h"

struct Text func_translit(struct Text text) {
    wchar_t alf_rus[] = {L'а', L'б', L'в', L'г', L'д', L'е', L'ё', L'ж', L'з', L'и', L'й', L'к', L'л', L'м', L'н', L'о', L'п', L'р', L'с', L'т', L'у', L'ф', L'х', L'ц', L'ч', L'ш', L'щ', L'ъ', L'ы', L'ь', L'э', L'ю', L'я', L'А', L'Б', L'В', L'Г', L'Д', L'Е', L'Ё', L'Ж', L'З', L'И', L'Й', L'К', L'Л', L'М', L'Н', L'О', L'П', L'Р', L'С', L'Т', L'У', L'Ф', L'Х', L'Ц', L'Ч', L'Ш', L'Щ', L'Ъ', L'Ы', L'Ь', L'Э', L'Ю', L'Я'};
    wchar_t *alf_eng[] = {L"a", L"b", L"v", L"g", L"d", L"e", L"yo", L"zh", L"z", L"i", L"j", L"k", L"l", L"m", L"n", L"o", L"p", L"r", L"s", L"t", L"u", L"f", L"x", L"cz", L"ch", L"sh", L"shh", L"``", L"y`", L"`", L"e`", L"yu", L"ya", L"A", L"B", L"V", L"G", L"D", L"E", L"Yo", L"Zh", L"Z", L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"R", L"S", L"T", L"U", L"F", L"X", L"Cz", L"Ch", L"Sh", L"Shh", L"``", L"Y`", L"`", L"E`", L"Yu", L"Ya"};
    wchar_t **trans_text = (wchar_t **) malloc(sizeof(wchar_t*) * text.cnt_sen);
    wchar_t *trans_sen = (wchar_t *) malloc(sizeof(wchar_t) * wcslen(text.txt[0]));
    int flag, count_ch, N;
    for (int i = 0; i < text.cnt_sen; i++) {
        N = wcslen(text.txt[i]);
        trans_sen = (wchar_t *) malloc(sizeof(wchar_t) * wcslen(text.txt[i]));
        count_ch = 0;
        for (int j = 0; j < wcslen(text.txt[i]); j++) {
            if (count_ch >= N - 10) {
                N += 20;
                trans_sen = (wchar_t *) realloc(trans_sen, sizeof(wchar_t) * N);
            }
            flag = 1;//Если буква кириллица - 0
            for (int k = 0; k < 66; k++) {
                if (alf_rus[k] == text.txt[i][j]) {
                    wcscat(trans_sen, alf_eng[k]);
                    flag = 0;
                    count_ch += wcslen(alf_eng[k]);
                    break;
                }
            }
            if (flag) {
                trans_sen[count_ch] = text.txt[i][j];
                count_ch++;
            }
        }
        trans_sen[count_ch] = '\0';
        trans_text[i] = trans_sen;
    }
    struct Text translit_text = {trans_text, text.cnt_sen};
    return translit_text;
}