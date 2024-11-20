module RegisterFile #(
    parameter WIDTH = 32,
    parameter ADD_WIDTH = 5
)(
    input  logic clk, // program counter
    input logic WE3, // from control unit
    input logic [WIDTH - 1:0] WD3, // from sum in alu
    input logic [ADD_WIDTH - 1:0] AD1, // from instruction memory - source register
    input logic [ADD_WIDTH - 1:0] AD2, // from instruction memory - source register
    input logic [ADD_WIDTH - 1:0] AD3, // from instruction memory
    output logic [WIDTH - 1:0] RD1, // goes straight to alu
    output logic [WIDTH - 1:0] RD2, // goes to mux 
    output logic [8:0] a0 //destination
);

    logic [WIDTH - 1:0] register_file [2**ADD_WIDTH - 1:0];

    
    always_ff @(posedge clk) begin
        if(WE3 == 1'b1) 
            register_file[AD3] <= WD3;
        
        RD1 = register_file[AD1];
        RD2 = register_file[AD2];

        a0 <= RD1[7:0];

    end        

endmodule
