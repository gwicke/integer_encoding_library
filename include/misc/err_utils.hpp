/*-----------------------------------------------------------------------------
 *  err_utils.hpp - A header for err_utiils.cpp
 *
 *  Coding-Style:
 *      emacs) Mode: C, tab-width: 8, c-basic-offset: 8, indent-tabs-mode: nil
 *      vi) tabstop: 8, expandtab
 *
 *  Authors:
 *      Takeshi Yamamuro <linguin.m.s_at_gmail.com>
 *      Fabrizio Silvestri <fabrizio.silvestri_at_isti.cnr.it>
 *      Rossano Venturini <rossano.venturini_at_isti.cnr.it>
 *-----------------------------------------------------------------------------
 */

#ifndef __ERR_UTILS_HPP__
#define __ERR_UTILS_HPP__

#include <assert.h>

namespace integer_coding {
namespace utility {

#define eoutput(fmt, ...)       \
do {                            \
        fprintf(stderr, fmt, ##__VA_ARGS__);    \
        fprintf(stderr, "\n");  \
        exit(1);                \
} while (0)

#ifndef NDEBUG
 #define __assert(cond)         assert(cond)
#else
 #define __assert(cond)
#endif /* NDEBUG */
}; /* namespace: utility */
}; /* namespace: integer_coding */

#endif  /* __ERR_UTILS_HPP__ */
