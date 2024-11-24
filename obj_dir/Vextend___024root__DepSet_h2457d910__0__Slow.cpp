// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vextend.h for the primary calling header

#include "verilated.h"

#include "Vextend___024root.h"

VL_ATTR_COLD void Vextend___024root___eval_initial(Vextend___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vextend___024root___eval_initial\n"); );
}

void Vextend___024root___combo__TOP__0(Vextend___024root* vlSelf);

VL_ATTR_COLD void Vextend___024root___eval_settle(Vextend___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vextend___024root___eval_settle\n"); );
    // Body
    Vextend___024root___combo__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vextend___024root___final(Vextend___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vextend___024root___final\n"); );
}

VL_ATTR_COLD void Vextend___024root___ctor_var_reset(Vextend___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vextend___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->ImmI = VL_RAND_RESET_I(12);
    vlSelf->ImmSrc = VL_RAND_RESET_I(1);
    vlSelf->ImmOp = VL_RAND_RESET_I(32);
}
