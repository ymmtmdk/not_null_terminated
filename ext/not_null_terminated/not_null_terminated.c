#include "not_null_terminated.h"

VALUE rb_mNotNullTerminated;

void
Init_not_null_terminated(void)
{
  rb_mNotNullTerminated = rb_define_module("NotNullTerminated");
}
