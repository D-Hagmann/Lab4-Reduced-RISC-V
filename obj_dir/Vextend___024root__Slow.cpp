// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vextend.h for the primary calling header

#include "verilated.h"

#include "Vextend__Syms.h"
#include "Vextend___024root.h"

void Vextend___024root___ctor_var_reset(Vextend___024root* vlSelf);

Vextend___024root::Vextend___024root(Vextend__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vextend___024root___ctor_var_reset(this);
}

void Vextend___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vextend___024root::~Vextend___024root() {
}
