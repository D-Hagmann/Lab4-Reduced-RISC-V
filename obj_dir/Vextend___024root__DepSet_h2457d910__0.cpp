// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vextend.h for the primary calling header

#include "verilated.h"

#include "Vextend___024root.h"

VL_INLINE_OPT void Vextend___024root___combo__TOP__0(Vextend___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vextend___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->ImmOp = ((IData)(vlSelf->ImmSrc) ? (((- (IData)(
                                                            (1U 
                                                             & ((IData)(vlSelf->ImmI) 
                                                                >> 0xbU)))) 
                                                 << 0xcU) 
                                                | (IData)(vlSelf->ImmI))
                      : 0U);
}

void Vextend___024root___eval(Vextend___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vextend___024root___eval\n"); );
    // Body
    Vextend___024root___combo__TOP__0(vlSelf);
}

#ifdef VL_DEBUG
void Vextend___024root___eval_debug_assertions(Vextend___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vextend___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->ImmI & 0xf000U))) {
        Verilated::overWidthError("ImmI");}
    if (VL_UNLIKELY((vlSelf->ImmSrc & 0xfeU))) {
        Verilated::overWidthError("ImmSrc");}
}
#endif  // VL_DEBUG
