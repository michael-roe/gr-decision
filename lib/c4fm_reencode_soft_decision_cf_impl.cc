/* -*- c++ -*- */
/*
 * Copyright 2020-2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "c4fm_reencode_soft_decision_cf_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace decision {

static float graycode[4] = {1.0, -1.0, 3.0, -3.0};

c4fm_reencode_soft_decision_cf::sptr
c4fm_reencode_soft_decision_cf::make(float gain) {
  return gnuradio::make_block_sptr<c4fm_reencode_soft_decision_cf_impl>(gain);
}

/*
 * The private constructor
 */
c4fm_reencode_soft_decision_cf_impl::c4fm_reencode_soft_decision_cf_impl(
    float gain)
    : gr::sync_block(
          "c4fm_reencode_soft_decision_cf",
          gr::io_signature::make(1, 1, sizeof(gr_complex)),
          gr::io_signature::make(1, 1, sizeof(float)))
{
  d_gain = gain;
}

/*
 * Our virtual destructor.
 */
c4fm_reencode_soft_decision_cf_impl::~c4fm_reencode_soft_decision_cf_impl() {}

int c4fm_reencode_soft_decision_cf_impl::work(
    int noutput_items, gr_vector_const_void_star &input_items,
    gr_vector_void_star &output_items) {
  const gr_complex *in = (const gr_complex *) input_items[0];
  float *out = (float *) output_items[0];
  int i;
  int bit0;
  int bit1;
  float err0;
  float err1;

  for (i=0; i<noutput_items; i++)
  {
    bit0 = (in[i].real() >= 0) ? 1 : 0;
    bit1 = (in[i].imag() >= 0) ? 1 : 0;
    err0 = in[i].real()*d_gain - (bit0 ? 1.0 : -1.0);
    err1 = in[i].imag()*d_gain - (bit1 ? 1.0 : -1.0);
    out[i] = graycode[bit1*2 + bit0];
    if (fabs(err0) < fabs(err1))
    {
      if (bit0)
      {
        out[i] -= err1;
      }
      else
      {
        out[i] += err1;
      }
    }
    else
    {
      if (bit1)
      {
        out[i] += err0;
      }
      else
      {
        out[i] -= err0;
      }
    }
  }

  // Tell runtime system how many output items we produced.
  return noutput_items;
}

} /* namespace decision */
} /* namespace gr */
