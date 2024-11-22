module pcsrc #(
    parameter D_WIDTH =32;
) (
    input logic [D_WIDTH-1:0] inc_PC;
    input logic [D_WIDTH-1:0] PC_i;
    input logic [D_WIDTH-1:0] ImmOp;
    input logic PCsrc;
    output logic [D_WIDTH-1:0] next_PC;
);
    logic [D_WIDTH-1:0] branch_PC;
    assign branch_PC = PC_i + ImmOp;
    assign next_PC = PCsrc ? branch_PC : (inc_PC+4);

endmodule
