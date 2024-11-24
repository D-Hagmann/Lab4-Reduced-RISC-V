module toptask3 #(
    parameter DATA_WIDTH = 32,
              ADDR_WIDTH = 32,
              REG_WIDTH = 5
) (
    input   logic clk,
    input   logic [DATA_WIDTH-1:0] PC,
    input logic EQ,
    output logic [DATA_WIDTH-1:0] ImmOp, // Immediate operand
    output logic RegWrite, // Control unit Register write enable
    output logic ALUctrl,
    output logic ALUsrc,
    output logic PCsrc, // Control unit PC source
    output logic [REG_WIDTH-1:0] rd,
    output logic [REG_WIDTH-1:0] rs1,
    output logic [REG_WIDTH-1:0] rs2,
);

    logic [DATA_WIDTH-1:0] instr;
    logic ImmSrc;
    logic [6:0] opcode;
    logic [2:0] funct3;
    logic [6:0] funct7;


    assign opcode = instr[6:0];
    assign funct3 = instr[14:12];
    assign funct7 = instr[31:25];
    assign rd = instr[11:7];
    assign rs1 = instr[19:15];
    assign rs2 = instr[24:20];

memory memory_unit(
    .clk(clk),
    .addr(PC),
    .dout(instr)
)

control control_unit(
    .opcode(opcode),
    .EQ(EQ),
    .funct3(funct3),
    .funct7(funct7),
    .RegWrite(RegWrite),
    .ALUctrl(ALUctrl),
    .ALUsrc(ALUsrc),
    .ImmSrc(ImmSrc),
    .PCsrc(PCsrc)
);

extend extend_unit(
    .ImmI(instr[31:20]),
    .ImmSrc(ImmSrc),
    .ImmOp(ImmOp)
);
endmodule
