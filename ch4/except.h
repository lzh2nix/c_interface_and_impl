#ifndef EXCEPT_INCLUDED
#define EXCEPT_INCLUDED
#include <setjmp.h>

#define T Except_T
typedef struct T {
  char *reason;
} T;

#define RAISE(e) Except_raise(&(e), __FILE___, __LINE__)
#define RERAISE Except_raise(Except_frame.exception, Excpt_frame.file, Except_frame.line)

void Except_raise(cosnt T *e, const char *file, int line);
#undef T
#endif
