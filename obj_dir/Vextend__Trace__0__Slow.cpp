// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vextend__Syms.h"


VL_ATTR_COLD void Vextend___024root__trace_init_sub__TOP__0(Vextend___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vextend___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,"ImmI", false,-1, 11,0);
    tracep->declBit(c+2,"ImmSrc", false,-1);
    tracep->declBus(c+3,"ImmOp", false,-1, 31,0);
    tracep->pushNamePrefix("extend ");
    tracep->declBus(c+4,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1,"ImmI", false,-1, 11,0);
    tracep->declBit(c+2,"ImmSrc", false,-1);
    tracep->declBus(c+3,"ImmOp", false,-1, 31,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vextend___024root__trace_init_top(Vextend___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vextend___024root__trace_init_top\n"); );
    // Body
    Vextend___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vextend___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vextend___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vextend___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vextend___024root__trace_register(Vextend___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vextend___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vextend___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vextend___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vextend___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vextend___024root__trace_full_sub_0(Vextend___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vextend___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vextend___024root__trace_full_top_0\n"); );
    // Init
    Vextend___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vextend___024root*>(voidSelf);
    Vextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vextend___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vextend___024root__trace_full_sub_0(Vextend___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vextend___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullSData(oldp+1,(vlSelf->ImmI),12);
    bufp->fullBit(oldp+2,(vlSelf->ImmSrc));
    bufp->fullIData(oldp+3,(vlSelf->ImmOp),32);
    bufp->fullIData(oldp+4,(0x20U),32);
}
