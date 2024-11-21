module top #(
    DATA_WIDTH = 32
) (
    input   logic clk,
    input   logic rst,
    output  logic [DATA_WIDTH-1:0] a0    
);
    assign a0 = 32'd5;
    
    logic              ALUsrc, //sel in mux
    logic [WIDTH-1:0]  MUXout

    //ALU
    // input logic [WIDTH - 1:0] ALUop1, same as RD1
    logic [WIDTH - 1:0] ALUop2,
    logic [6:0] opcode,
    logic [2:0] ALUctrl,
    logic [WIDTH-1:0] ALUResult,
    logic EQ,

    //regfile
    input  logic clk, 
    //input logic WE3, same as Regwrite
    //input logic [WIDTH - 1:0] WD3, same as ALUResult
    logic [ADD_WIDTH - 1:0] AD1, //same as rs1
    logic [ADD_WIDTH - 1:0] AD2, //same as rs2
    logic [ADD_WIDTH - 1:0] AD3 //same as rs3

toptask2 ALU(
    .clk(clk),
    .AD1(AD1),
    .AD2(AD2),
    .AD3(AD3),
    .MUXout(MUXout),
    .ALUResult(ALUResult),
    .ALUsrc(ALUsrc),
    .ALUctrl(ALUctrl),
    .ImmOP(ImmOP),
    .EQ(EQ),
    .opcode(opcode)

);

toptask3 Control()

endmodule
