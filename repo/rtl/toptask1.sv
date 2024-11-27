module toptask1# (
    parameter WIDTH = 32,
)(
    //pcsrc
    input logic [DATA_WIDTH-1:0] PC_i,
    input logic [DATA_WIDTH-1:0] ImmOp,
    input logic PCsrc,

    //pc
    input logic clk,
    input logic rst,
    output logic [DATA_WIDTH-1:0] pc_out

);

    logic [DATA_WIDTH-1:0] next_PC;

pcsrc PCMUX (
    .PC_i (PC_i),
    .ImmOp (ImmOp),
    .PCsrc (PCsrc),
    .next_PC(next_PC)
);

pc PC (
    .clk (clk),
    .rst (rst),
    .pc_in (next_PC),
    .pc_out (pc_out)
);

endmodule


