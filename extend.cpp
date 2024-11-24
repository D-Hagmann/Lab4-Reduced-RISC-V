#include "gtest/gtest.h"
#include "Vextend.h"  // Include the correct Verilated header for the module
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <memory>

class SignExtensionTest : public ::testing::Test
{
public:

protected:
    Vextend* dut; 

    virtual void SetUp() override {
        dut = new Vextend;
    }

    virtual void TearDown() override {
        delete dut;
    }

    void evaluate() {
        dut->eval(); 
    }
};

TEST_F(SignExtensionTest, PositiveImmediateNoSignExtension) {
    dut->ImmI = 0x00000A;   
    dut->ImmSrc = 1;
    evaluate();
    std::cout << "Running Positive Immediate with No Sign Extension\n";
    std::cout << "instr: " << dut->ImmI << " | immSrc: " << dut->ImmSrc << " | immOp: " << dut->ImmOp;
    std::cout << "\n------------------------------------------------\n";
    EXPECT_EQ(dut->ImmOp, 0x0000000A); 
}

TEST_F(SignExtensionTest, NegativeImmediateWithSignExtension) {
    dut->ImmI = 0xFFFFFA;   
    dut->ImmSrc = 1;
    evaluate();
    EXPECT_EQ(dut->ImmOp, 0xFFFFFFFA); 
}

TEST_F(SignExtensionTest, ImmSrcZeroNoSignExtension) {
    dut->ImmI = 0x00000A;  
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