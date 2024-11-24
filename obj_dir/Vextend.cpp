// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vextend.h"
#include "Vextend__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vextend::Vextend(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vextend__Syms(contextp(), _vcname__, this)}
    , ImmSrc{vlSymsp->TOP.ImmSrc}
    , ImmI{vlSymsp->TOP.ImmI}
    , ImmOp{vlSymsp->TOP.ImmOp}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vextend::Vextend(const char* _vcname__)
    : Vextend(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vextend::~Vextend() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vextend___024root___eval_initial(Vextend___024root* vlSelf);
void Vextend___024root___eval_settle(Vextend___024root* vlSelf);
void Vextend___024root___eval(Vextend___024root* vlSelf);
#ifdef VL_DEBUG
void Vextend___024root___eval_debug_assertions(Vextend___024root* vlSelf);
#endif  // VL_DEBUG
void Vextend___024root___final(Vextend___024root* vlSelf);

static void _eval_initial_loop(Vextend__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vextend___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vextend___024root___eval_settle(&(vlSymsp->TOP));
        Vextend___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vextend::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vextend::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vextend___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vextend___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vextend::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vextend::final() {
    Vextend___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vextend::hierName() const { return vlSymsp->name(); }
const char* Vextend::modelName() const { return "Vextend"; }
unsigned Vextend::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vextend::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vextend___024root__trace_init_top(Vextend___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vextend___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vextend___024root*>(voidSelf);
    Vextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vextend___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vextend___024root__trace_register(Vextend___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vextend::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vextend___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
