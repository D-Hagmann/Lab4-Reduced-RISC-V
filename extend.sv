module extend #(
    parameter DATA_WIDTH = 32
) (
    input logic [11:0] ImmI,
    input logic  ImmSrc,
    output logic [DATA_WIDTH-1:0] ImmOp
);

always_comb begin
    case (ImmSrc)
        1'b1: ImmOp = {20{ImmI[11]}, ImmI};
        default: ImmOp = 32'b0;
    endcase
end

endmodule