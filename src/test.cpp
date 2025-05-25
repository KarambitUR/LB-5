#include "../source.cpp"
#include <gtest/gtest.h>

unsigned int M1[2] = {128, 65};
unsigned int C1[2] = {423, 197};

unsigned int M2[4] = {243, 357, 145, 73};
unsigned int C2[4] = {491, 190, 549, 269};

unsigned int M3[8] = {163, 422, 357, 184, 128, 431, 287, 7};
unsigned int C3[8] = {19, 315, 22, 147, 365, 836, 1029, 197};

unsigned int M4[16] = {203, 313, 129, 230, 47, 273, 373, 251, 372, 78, 24, 54, 276, 134, 267, 491};
unsigned int C4[16] = {513, 701, 402, 230, 47, 14, 67, 732, 200, 817, 277, 294, 368, 467, 563, 639};
 
TEST(Task1Test, Encryption) { 
    EXPECT_EQ(Task1(M1,  2, 17, 29, true), "423 197");
    EXPECT_EQ(Task1(M2,  4, 23, 31, true), "491 190 549 269");
    EXPECT_EQ(Task1(M3,  8, 29, 37, true), "19 315 22 147 365 836 1029 197");
    EXPECT_EQ(Task1(M4, 16, 23, 37, true), "513 701 402 230 47 14 67 732 200 817 277 294 368 467 563 639");
}

TEST(Task1Test, Decryption) { 
    EXPECT_EQ(Task1(C1,  2, 17, 29, false), "128 65");
    EXPECT_EQ(Task1(C2,  4, 23, 31, false), "243 357 145 73");
    EXPECT_EQ(Task1(C3,  8, 29, 37, false), "163 422 357 184 128 431 287 7");
    EXPECT_EQ(Task1(C4, 16, 23, 37, false), "203 313 129 230 47 273 373 251 372 78 24 54 276 134 267 491");
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

