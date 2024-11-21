module pc #(
    D_WIDTH = 32

)(
    input logic clk,
    input logic rst,
    input logic [D_WIDTH-1:0] pc_in,
    output logic [D_WIDTH-1:0] pc_out,

);

    always_ff @(posedge clk)
        if (rst) pc_out <= 32'b0 ;
        else pc_out<=pc_in;

endmodule
