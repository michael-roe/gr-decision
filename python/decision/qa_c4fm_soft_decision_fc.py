#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2022 Michael Roe.
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

from gnuradio import gr, gr_unittest
from gnuradio import blocks
try:
  from gnuradio.decision import c4fm_soft_decision_fc
except ImportError:
    import os
    import sys
    dirname, filename = os.path.split(os.path.abspath(__file__))
    sys.path.append(os.path.join(dirname, "bindings"))
    from gnuradio.decision import c4fm_soft_decision_fc

class qa_c4fm_soft_decision_fc(gr_unittest.TestCase):

    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None

    def test_instance(self):
        instance = c4fm_soft_decision_fc(1.0)

    def test_001(self):
        src_data = (-3, -2, -1, 0, 1, 2, 3)
        expected_result = (1+1j, 1+0j, 1-1j, 0-1j, -1-1j, -1+0j, -1+1j)
        src = blocks.vector_source_f(src_data)
        slicer = c4fm_soft_decision_fc(1.0)
        dst = blocks.vector_sink_c()
        self.tb.connect(src, slicer)
        self.tb.connect(slicer, dst)
        self.tb.run()
        result_data = dst.data()
        self.assertComplexTuplesAlmostEqual(expected_result, result_data, 7)

if __name__ == '__main__':
    gr_unittest.run(qa_c4fm_soft_decision_fc)
