/* -*- c++ -*- */
/*
 * Copyright 2020-2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_DECISION_C4FM_REENCODE_SOFT_DECISION_CF_IMPL_H
#define INCLUDED_DECISION_C4FM_REENCODE_SOFT_DECISION_CF_IMPL_H

#include <gnuradio/decision/c4fm_reencode_soft_decision_cf.h>

namespace gr {
namespace decision {

class c4fm_reencode_soft_decision_cf_impl
    : public c4fm_reencode_soft_decision_cf {
private:
  float d_gain;

public:
  c4fm_reencode_soft_decision_cf_impl(float gain);
  ~c4fm_reencode_soft_decision_cf_impl();

  // Where all the action really happens
  int work(int noutput_items, gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
};

} // namespace decision
} // namespace gr

#endif /* INCLUDED_DECISION_C4FM_REENCODE_SOFT_DECISION_CF_IMPL_H */
