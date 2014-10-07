#include "not_null_terminated.h"

#define STR_NOEMBED      FL_USER1
#define STR_EMBED_P(str) (!FL_TEST((str), STR_NOEMBED))

#define STR_SET_EMBED_LEN(str, n) do { \
    long tmp_n = (n);\
    RBASIC(str)->flags &= ~RSTRING_EMBED_LEN_MASK;\
    RBASIC(str)->flags |= (tmp_n) << RSTRING_EMBED_LEN_SHIFT;\
} while (0)

#define STR_SET_LEN(str, n) do { \
    if (STR_EMBED_P(str)) {\
 STR_SET_EMBED_LEN((str), (n));\
    }\
    else {\
 RSTRING(str)->as.heap.len = (n);\
    }\
} while (0)

/* return coderange without scan */
static VALUE
str_chop_without_terminate(VALUE str)
{
    STR_SET_LEN(str, RSTRING_LEN(str)-1);
    return Qnil;
}

/* scan coderange and return the result */
static VALUE
str_null_terminated_p(VALUE str)
{
    if ((size_t)RSTRING_LEN(str) == rb_str_capacity(str)) return Qfalse;
    if (*RSTRING_END(str) != 0) return Qfalse;

    return Qtrue;
}

void
Init_not_null_terminated(void)
{
  VALUE rb_mNotNullTerminated;
  rb_mNotNullTerminated = rb_define_module("NotNullTerminated");
  rb_define_method(rb_mNotNullTerminated, "chop_without_terminate", str_chop_without_terminate, 0);
  rb_define_method(rb_mNotNullTerminated, "null_terminated?", str_null_terminated_p, 0);
}
