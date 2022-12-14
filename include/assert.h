#include <assert/assert.h>

#ifndef _ISOMAC
/* This prints an "Assertion failed" message and aborts.
   In installed assert.h this is only conditionally declared,
   so it has to be repeated here.  */
extern void __assert_fail (const char *__assertion, const char *__file,
			   unsigned int __line, const char *__function)
     __THROW __attribute__ ((__noreturn__));

/* Likewise, but prints the error text for ERRNUM.  */
extern void __assert_perror_fail (int __errnum, const char *__file,
				  unsigned int __line,
				  const char *__function)
     __THROW __attribute__ ((__noreturn__));

/* The real implementation of the two functions above.  */
extern void __assert_fail_base (const char *fmt, const char *assertion,
				const char *file, unsigned int line,
				const char *function)
     __THROW  __attribute__ ((__noreturn__)) attribute_hidden;

rtld_hidden_proto (__assert_fail)
rtld_hidden_proto (__assert_perror_fail)
libc_hidden_proto (__assert_perror_fail)


# if IS_IN (libc)
/* Redirect to the internal version which does not use stderr.  */
extern _Noreturn __typeof (__assert_fail) __libc_assert_fail attribute_hidden;
#  define __assert_fail __libc_assert_fail
# endif
#endif
