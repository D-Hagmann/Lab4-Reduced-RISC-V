module ALU #(
    parameter WIDTH = 32,
)(
    input logic [WIDTH - 1:0] ALUop1, 
    input logic [WIDTH - 1:0] ALUop2,
    input logic [6:0] opcode,
    input logic [2:0] ALUctrl,
    output logic [WIDTH-1:0] ALUResult,
    output logic EQ
);

    always_comb begin

            case(opcode)
            7'b0010011: begin
                case(ALUctrl)
                3'b000: ALUResult = ALUop1 + ALUop2;
                default: ALUResult = 0;
                endcase
            end
            
            7'b1100011: begin
                case(ALUctrl)
                3'b000: begin
                    if(ALUop1 == ALUop2) 
                        EQ = 1'b1;
                    else 
                        EQ = 1'b0;
                end
                3'b001: begin
                    if(ALUop1 == ALUop2) 
                        EQ = 1'b0;
                    else 
                        EQ = 1'b1;
                end
                default: begin
                    ALUResult = 0;
                    EQ = 0;
                endcase
            end
                
        
            default: begin
                ALUResult = 0;
                EQ = 0;
            end

        endcase
    end
endmodule
