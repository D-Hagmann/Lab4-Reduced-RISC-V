module control #(
    input logic [6:0] opcode,
    input logic EQ,
    input logic [2:0] funct3,
    input logic [6:0] funct7,
    output logic RegWrite,
    output logic ALUctrl,
    output logic ALUsrc,
    output logic ImmSrc,
    output logic PCsrc
    
);
   always_comb begin
    case (opcode)
        Default: begin
        RegWrite = 0;
        ALUctrl = 0;  // Define operations separately
        ALUsrc = 0;
        ImmSrc = 0;
        PCsrc = 0;  // Default to incrementing PC
    end
        7'b1100011: begin // opcode for B-type instructions
            // RegWrite = 0;
            case(funct3)            
                3'b000: begin // BEQ
                    RegWrite = 0;
                    ALUctrl = 1; // ALU should subtract rs1 and rs2 to set EQ correctly
                    ALUsrc = 0; // Use register value for rs2
                    PCsrc = EQ[1] ? 1 : 0; // Take the branch if rs1 and rs2 are equal (EQ[1] would be the 'equal' flag)
                end
                3'b001: begin // BNE
                    RegWrite = 0;
                    ALUctrl = 1; // ALU should subtract rs1 and rs2 to set EQ correctly
                    ALUsrc = 0; // Use register value for rs2
                    PCsrc = EQ[1] ? 0 : 1; // Take the branch if rs1 and rs2 are not equal (EQ[1] would be the 'not equal' flag)
                end
                
                default: begin
                    // Handle other cases or set safe defaults
                end
            endcase
        end

        7'b0010011: begin // opcode for I-type instructions
            case(funct3)            
                3'b000: begin // ADD or SUB, SUB not initiliazed here, register + immediate 
                        RegWrite = 1;
                        ALUctrl = 1; // ALU should add rs1 and the sign-extended immediate
                        ALUsrc = 1; // Use immediate value
                        ImmSrc = 1; // Sign extend the immediate
                        PCsrc = 0; // Next instruction
                end
            endcase
        end
       
    endcase
end

endmodule