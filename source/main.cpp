#include <iostream>
#include "NumbersHandler.h"
#include <gtest/gtest.h>
TEST(FindPortData, FindingOwnerByNumber_1){
    NumbersHandler handler;
    const std::string file_path = "../data/Numbering_plan.csv";
    const std::string portFile_path = "../data/Port_All.csv";

    handler.ParsePortDataFromCSV(portFile_path);
    EXPECT_EQ( "mMTS",handler.FindPortData(9059449362));
    EXPECT_EQ("mJUTA",handler.FindPortData(9059449404));
    EXPECT_EQ("mMEGAFON",handler.FindPortData(9060291607));
    EXPECT_EQ("mMEGAFON",handler.FindPortData(9060291618));
    EXPECT_EQ("mROSTELEKOM",handler.FindPortData(9082712066));
    EXPECT_EQ("mRTK",handler.FindPortData(9082712098));
    EXPECT_EQ("mJUTA",handler.FindPortData(9082712147));
    EXPECT_EQ("mMTS",handler.FindPortData(9088099002));

}
TEST(FindOwner,FindingOwnerByNumber_2) {
    NumbersHandler handler;
    const std::string file_path = "../data/Numbering_plan.csv";
    handler.ParseDataFromCSV(file_path);
    EXPECT_EQ( "mTELE2",handler.FindOwnerByNumber(9000299998));
    EXPECT_EQ("mEKATERINBURG",handler.FindOwnerByNumber(9043800000));
    EXPECT_EQ("mBEELINE",handler.FindOwnerByNumber(9061930000));

    EXPECT_EQ("mMTS",handler.FindOwnerByNumber(9170640005));
    EXPECT_EQ("mMTS",handler.FindOwnerByNumber(9192899990));

    EXPECT_EQ("mSPRINT",handler.FindOwnerByNumber(9318889995));
    EXPECT_EQ("mSPRINT",handler.FindOwnerByNumber(9318880000));
    EXPECT_EQ("mSPRINT",handler.FindOwnerByNumber(9318889999));

    EXPECT_EQ("mSBERTEL",handler.FindOwnerByNumber(9320010000));
    EXPECT_EQ("mSBERTEL",handler.FindOwnerByNumber(9320010100));
    EXPECT_EQ("mSBERTEL",handler.FindOwnerByNumber(9320089999));
}




int main() {

    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();

}
