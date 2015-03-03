/*****************************************************************************
MiniSat -- Copyright (c) 2003-2006, Niklas Een, Niklas Sorensson
CryptoMiniSat -- Copyright (c) 2009 Mate Soos

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
********************************************************************/

#ifndef ONLYNONLEARNTBINS_H
#define ONLYNONLEARNTBINS_H

#include "Solver.h"
#include <set>
using std::set;

namespace CMSat2
{
using namespace CMSat2;

class OnlyNonLearntBins
{
public:
  OnlyNonLearntBins(Solver& solver);

  // propagation
  bool propagate();
  bool propagateBinExcept(const Lit& exceptLit);
  bool propagateBinOneLevel();

  // Management of clauses
  bool fill();
  void removeBin(Lit lit1, Lit lit2);
  void removeClause(Clause& c);
  uint32_t removeBins();

private:
  vec<vec<WatchedBin>> binwatches;
  set<uint64_t> toRemove;

  Solver& solver;
};

} // NAMESPACE CMSat2

#endif // ONLYNONLEARNTBINS_H
