#include "gtest/gtest.h"
#include "Vtoptask3.h"  // Include the correct Verilated header for the module
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <memory>

class SignExtensionTest : public ::testing::Test
{
public:

protected:
    Vtoptask3* dut; 

    virtual void SetUp() override {
        dut = new Vtoptask3;
    }

    virtual void TearDown() override {
        delete dut;
    }

    void evaluate() {
        dut->eval(); 
    }
};

TEST_F(SignExtensionTest, PositiveImmediateNoSignExtension) {
    dut->Immop = 0x00000A;   
    dut->ImmSrc = 1;
    evaluate();
    // std::cout << "Running Positive Immediate with No Sign Extension\n";
    // std::cout << "instr: " << dut->instr << " | immSrc: " << dut->immSrc << " | immOp: " << dut->immOp;
    // std::cout << "\n------------------------------------------------\n";
    EXPECT_EQ(dut->immOp, 0x0000000A); 
}

TEST_F(SignExtensionTest, NegativeImmediateWithSignExtension) {
    dut->instr = 0xFFFFFA;   
    dut->ImmSrc = 1;
    evaluate();
    EXPECT_EQ(dut->ImmSrcmmOp, 0xFFFFFFFA); 
}

TEST_F(SignExtensionTest, ImmSrcZeroNoSignExtension) {
    dut->instr = 0x00000A;  
    dut->ImmSrc = 0;        
    evaluate();
    EXPECT_EQ(dut->ImmOp, 0x0000000A); 
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}