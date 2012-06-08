/*-----------------------------------------------------------------------------
 *  F_Delta.hpp - A encoder/decoder for improved Delta
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

#ifndef __F_DELTA_HPP__
#define __F_DELTA_HPP__

#include "xxx_common.hpp"

#include "io/BitsWriter.hpp"
#include "io/BitsReader.hpp"

namespace integer_coding {
namespace compressor {

class F_Delta : public CompressorBase {
public:
        F_Delta() : CompressorBase(C_INVALID) {}
        F_Delta(int policy) : CompressorBase(policy) {}
        ~F_Delta() throw() {}

        void encodeArray(uint32_t *in, uint32_t len,
                        uint32_t *out, uint32_t &nvalue) const {
                utility::BitsWriter wt(out);
                nvalue = wt.N_DeltaArray(in, len);
        }

        void decodeArray(uint32_t *in, uint32_t len,
                        uint32_t *out, uint32_t nvalue) const {
                utility::BitsReader rd(in);
                rd.F_DeltaArray(out, nvalue);
        }
}; /* F_Delta */

} /* namespace: compressor */
} /* namespace: integer_coding */

#endif /* __F_DELTA_HPP__ */