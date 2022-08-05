/* -*- c++ -*- */
/*
 * Copyright 2019-2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "c4fm_soft_decision_fc_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace decision {

c4fm_soft_decision_fc::sptr c4fm_soft_decision_fc::make(float gain) {
  return gnuradio::make_block_sptr<c4fm_soft_decision_fc_impl>(gain);
}

/*
 * The private constructor
 */
c4fm_soft_decision_fc_impl::c4fm_soft_decision_fc_impl(float gain)
    : gr::sync_block(
          "c4fm_soft_decision_fc",
          gr::io_signature::make(1, 1, sizeof(float)),
          gr::io_signature::make(1, 1, sizeof(gr_complex)))
{
  d_gain = gain;
}

/*
 * Our virtual destructor.
 */
c4fm_soft_decision_fc_impl::~c4fm_soft_decision_fc_impl() {}

int c4fm_soft_decision_fc_impl::work(int noutput_items,
                                     gr_vector_const_void_star &input_items,
                                     gr_vector_void_star &output_items) {
  const float *in = (const float *) input_items[0];
  gr_complex *out = (gr_complex *) output_items[0];
  float f;
  int i;

  for (i = 0; i < noutput_items; i++)
  {
    f = in[i];
    if (f < -4.0)
    {
      out[i] = gr_complex(0.0, d_gain);
    }
    else if (f < -3.0)
    {
      out[i] = gr_complex(d_gain*(f+4), d_gain);
    }
    else if (f < -1.0)
    {
      out[i] = gr_complex(d_gain, d_gain*(-2-f));
    }
    else if (f < 1.0)
    {
      out[i] = gr_complex(-d_gain*f, -d_gain);
    }
    else if (f < 3.0)
    {
      out[i] = gr_complex(-d_gain, d_gain*(f-2));
    }
    else if (f < 4.0)
    {
      out[i] = gr_complex(d_gain*(f-4), d_gain);
    }
    else
    {
      out[i] = gr_complex(-d_gain, d_gain);
    }
  }

  // Tell runtime system how many output items we produced.
  return noutput_items;
}

} /* namespace decision */
} /* namespace gr */
