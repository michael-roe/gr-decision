/* -*- c++ -*- */
/*
 * Copyright 2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_DECISION_C4FM_SOFT_DECISION_FC_H
#define INCLUDED_DECISION_C4FM_SOFT_DECISION_FC_H

#include <gnuradio/decision/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace decision {

/*!
 * \brief Decode a 4 level FSK symbol into a pair of single bit soft decisions
 * \ingroup decision
 * \details
 * The input is a floating point number where the values -3, -1, +1 and +3
 * represent the Gray-coded dibits 11, 10, 00 and 01. The output is a complex
 * number whose real part is a soft decision for the first bit and whose
 * imaginary part is a soft decision for the second bit. In the output, -1*gain
 * represents a bit value of 0 and +1*gain represents a bit value of 1; values
 * between -gain and +gain are output when the input value lies between a point
 * of the constellation.
 *
 */
class DECISION_API c4fm_soft_decision_fc : virtual public gr::sync_block {
public:
  typedef std::shared_ptr<c4fm_soft_decision_fc> sptr;

  /*!
   * \brief Return a shared_ptr to a new instance of
   * decision::c4fm_soft_decision_fc.
   *
   * To avoid accidental use of raw pointers, decision::c4fm_soft_decision_fc's
   * constructor is in a private implementation
   * class. decision::c4fm_soft_decision_fc::make is the public interface for
   * creating new instances.
   */
  static sptr make(float gain);
};

} // namespace decision
} // namespace gr

#endif /* INCLUDED_DECISION_C4FM_SOFT_DECISION_FC_H */
