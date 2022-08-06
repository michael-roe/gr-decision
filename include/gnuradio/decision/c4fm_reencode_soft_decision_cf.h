/* -*- c++ -*- */
/*
 * Copyright 2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_DECISION_C4FM_REENCODE_SOFT_DECISION_CF_H
#define INCLUDED_DECISION_C4FM_REENCODE_SOFT_DECISION_CF_H

#include <gnuradio/decision/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace decision {

/*!
 * \brief <+description of block+>
 * \ingroup decision
 *
 */
class DECISION_API c4fm_reencode_soft_decision_cf
    : virtual public gr::sync_block {
public:
  typedef std::shared_ptr<c4fm_reencode_soft_decision_cf> sptr;

  /*!
   * \brief Return a shared_ptr to a new instance of
   * decision::c4fm_reencode_soft_decision_cf.
   *
   * To avoid accidental use of raw pointers,
   * decision::c4fm_reencode_soft_decision_cf's constructor is in a private
   * implementation class. decision::c4fm_reencode_soft_decision_cf::make is the
   * public interface for creating new instances.
   */
  static sptr make(float gain);
};

} // namespace decision
} // namespace gr

#endif /* INCLUDED_DECISION_C4FM_REENCODE_SOFT_DECISION_CF_H */
