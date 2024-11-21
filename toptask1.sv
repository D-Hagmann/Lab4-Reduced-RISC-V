module toptask2# (
    parameter WIDTH = 32,
)(
    //pcsrc
    input logic [DATA_WIDTH-1:0] inc_PC;
    input logic [DATA_WIDTH-1:0] PC_i;
    input logic [DATA_WIDTH-1:0] ImmOp;
    input logic PCsrc;

    //pc
    input logic clk,
    input logic rst,
    input logic [DATA_WIDTH-1:0] pc_in,
    output logic [DATA_WIDTH-1:0] pc_out,

);

    logic [DATA_WIDTH-1:0] next_PC;

PCMUX pcsrc (
    .inc_PC (inc_PC),
    .PC_i (PC_i),
    .ImmOp (ImmOp),
    .PCsrc (PCsrc)
);

PC pc (
    .clk (clk),
    .rst (rst),
    .pc_in (pc_in),
    .pc_out (pc_out)
);

endmodule


