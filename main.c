#include "func_out.h"
#include "func_vvod_text.h"
#include "func_obr_text.h"//0
#include "func_translit.h"//1
#include "func_sort_sym.h"//2
#include "func_repl_digit.h"//3
#include "func_odd_del.h"//4
#include "freedom.h"
#include "struct.h"

int main() {
  setlocale(LC_ALL,"ru_RU.UTF-8");
  wprintf(L"Course work for option 5.12, created by Savelii Borivets\n");
  int command;
  wscanf(L"%d", &command);
  struct Text orig_text, obr_text;
  wchar_t ch;
  orig_text = func_vvod_text();
  obr_text = func_obr_text(orig_text);
  switch(command){
    case 0: 
      func_out(obr_text);
      break;
    case 1:
      struct Text translit_text = func_translit(obr_text);
      func_out(translit_text);
      freedom(translit_text);
      break;
    case 2:
      struct Text sort_sym_text = func_sort_sym(obr_text);
      func_out(sort_sym_text);
      freedom(sort_sym_text);
      break;
    case 3:
      struct Text repl_text = func_repl_digit(obr_text);
      func_out(repl_text);
      freedom(repl_text);
      break;
    case 4:
      struct Text odd_del_text = func_odd_del(obr_text);
      func_out(odd_del_text);
      freedom(odd_del_text);
      break;
    case 5:
      break;
    default:
  }
  freedom(orig_text);
  free(obr_text.txt);
}
