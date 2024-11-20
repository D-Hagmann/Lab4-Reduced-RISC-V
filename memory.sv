module memory #(
    parameter ADDRESS_WIDTH = 32,
              DATA_WIDTH = 32
)(
    input logic clk,      //input clock
    input logic [ADDRESS_WIDTH-1:0] addr,      //address
    output logic [DATA_WIDTH-1:0] dout      //output data (instruction)
);

logic [DATA_WIDTH-1:0] rom_array [2**ADDRESS_WIDTH-1:0];      //memory array

always_ff @(posedge clk) begin
    dout <= rom_array[addr];
end;

endmodule