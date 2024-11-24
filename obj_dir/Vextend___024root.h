// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vextend.h for the primary calling header

#ifndef VERILATED_VEXTEND___024ROOT_H_
#define VERILATED_VEXTEND___024ROOT_H_  // guard

#include "verilated.h"

class Vextend__Syms;

class Vextend___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(ImmSrc,0,0);
    VL_IN16(ImmI,11,0);
    VL_OUT(ImmOp,31,0);

    // INTERNAL VARIABLES
    Vextend__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vextend___024root(Vextend__Syms* symsp, const char* name);
    ~Vextend___024root();
    VL_UNCOPYABLE(Vextend___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
