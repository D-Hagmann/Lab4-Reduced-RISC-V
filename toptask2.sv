module toptask2 #(
    parameter WIDTH = 32,
    parameter ADD_WIDTH = 5
)(

    //sign extend
    input logic [WIDTH - 1:0] ImmOp,
    
    //mux
    //input   logic [DATA_WIDTH-1:0]  in0, same as RD2
    //input   logic [DATA_WIDTH-1:0]  in1, same as ImmOP
    input   logic              ALUsrc, //sel in mux
    output  logic [WIDTH-1:0]  MUXout

    //ALU
    // input logic [WIDTH - 1:0] ALUop1, same as RD1
    input logic [6:0] opcode,
    input logic [2:0] ALUctrl,
    output logic [WIDTH-1:0] ALUResult,
    output logic EQ
    

    //regfile
    input  logic clk, 
    //input logic WE3, same as Regwrite
    //input logic [WIDTH - 1:0] WD3, same as ALUResult
    input logic [ADD_WIDTH - 1:0] AD1, //same as rs1
    input logic [ADD_WIDTH - 1:0] AD2, //same as rs2
    input logic [ADD_WIDTH - 1:0] AD3, //same as rs3
    output logic [8:0] a0 
    
);

    logic [WIDTH - 1:0] RD1;
    logic [WIDTH - 1:0] RD2;
    logic [WIDTH - 1:0] ALUop2,
    logic [WIDTH - 1:0] MUXout;


ALU ALU(
    .ALUop1 (RD1),
    .ALUop2 (MUXout),
    .opcode (opcode),
    .ALUctrl (ALUctrl),
    .ALUResult (ALUResult),
    .EQ (EQ)
);

MUX MUX(
    .in0 (RD2),
    .in1 (ImmOp),
    .sel (ALUsrc),
    .MUXout (MUXout)
    
);

Regfile regfile (
    .clk (clk),
    .WE3 (RegWrite),
    .WD3 (ALUResult),
    .AD1 (AD1), 
    .AD2 (AD2),
    .AD3 (AD3),
    .RD1 (RD1),
    .RD2 (RD2),
    .a0 (a0)

);

endmodule
