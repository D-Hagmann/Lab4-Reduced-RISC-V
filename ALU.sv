module ALU #(
    parameter WIDTH = 32,
)(
    input logic [WIDTH - 1:0] ALUop1, ALUop2,
    input logic [2:0] ALUctrl,
    output logic [WIDTH-1:0] ALUResult,
    output logic EQ
);

    always_ff() begin

      
        EQ = 1'b0;
    
        case(ALUctrl)
        3'b000: ALUResult = ALUop1 + ALUop2;
        3'b001: begin
            if(ALUop1 == ALUop2) 
                EQ = 1'b1;
            else 
                EQ = 1'b0;
        end

        default: ALUResult = 32'b0;
    end
endmodule
