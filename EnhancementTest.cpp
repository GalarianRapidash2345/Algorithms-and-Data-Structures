//This is the new file

#include "pch.h"

//This ensures symbolics are used instead of string constants, and has space for data. This originates from the SEI CERT
//C++ coding standards, which can be found here: https://wiki.sei.cmu.edu/confluence/display/cplusplus/STR50-CPP.+Guarantee+that+storage+for+strings+has+sufficient+space+for+character+data+and+the+null+terminator

#include <string>

#include <exception>

//This is the creation of a new unique collection data structure, which is similar to the creation of the old collection.
//Major changes are present within the tests instead.

using namespace std;


//This is the new testing environment 

class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    
    void SetUp() override
    {
        //  initialize random seed
        
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    
    void TearDown() override {}
};

// Create our test class to house shared data between tests
// This is the new unique collection data structure tested for efficiency

class UniqueCollectionTest : public ::testing::Test
{
protected:

    // create a smart point to hold our new collection
    std::unique_ptr<std::vector<int>> unique_collection;
    
    void SetUp() override
    { // create a new collection to be used in the test
        unique_collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        unique_collection->clear();
        // free the pointer
        unique_collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 1500 count times to the collection
    void add_uentries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            unique_collection->push_back(rand() % 1501);
    }

    //This is for symbolic and data truncation issues that are resolved in the SEI CERT C++ coding standard STR50-CPP. 
    //String input Ds is for the data structure, and Al for the algorithm.
    
    void symbolic_entries()
    {
        string input;
        string stringDsOutBounds, stringAlOutBounds;
        cin >> stringDsOutBounds >> stringAlOutBounds;

    }
};


//These tests are for verifying the new unique test to be created and empty.

//This test ensures the unique collection is created. 

TEST_F(UniqueCollTest, UniqueCollSmartPntrNotNull)
{
    // is the collection created
    ASSERT_TRUE(unique_collection);

    // if empty, the size must be 0
    ASSERT_NE(unique_collection.get(), nullptr);
}

//This test ensures the unique collection is empty for deallocation purposes.
TEST_F(UniqueCollTest, UniqueEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(unique_collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(unique_collection->size(), 0);
}


//This is the Data Structure test. This test ensures that a certain size can be added to the unique collection.

TEST_F(UniqueCollTest, CanAddEmptyStructUniqueColl)
{
    add_uentries(20);
    ASSERT_TRUE(unique_collection->empty());
    ASSERT_TRUE(unique_collection->size(), 20);
    
}

//This is the Algorithm test. This test ensures that entries from the collection can be retrieved while the capacity is 
//greater than or equal to the size of the unique collection. 

TEST_F(UniqueCollTest, CapacityGreaterEqualUniqueColl)
{
    add_uentries(0);
    add_uentries(2);
    add_uentries(100);
    add_uentries(1000);

    ASSERT_GE(unique_collection->size(), 0);
    ASSERT_GE(unique_collection->size(), 2);
    ASSERT_GE(unique_collection->size(), 100);
    ASSERT_GE(unique_collection->size(), 1000);
}

//This is the refined CanAddToEmptyVector test. This test ensures that any value can be added to the unique collection.

TEST_F(UniqueCollTest, CanAddToEmptyUniqueVector)
{
    add_uentries(1);

    EXPECT_EQ(unique_collection->empty(), 0);

    ASSERT_EQ(unique_collection->size(), 1);
}


//This is the negative test that covers all cases and the indexes, subscripts, or pointers are tested 
//against array, record, or file bounds for the data structure.

TEST_F(UniqueCollTest, ExceptionUniqueDSOutBounds)
{
    int unique_collect1 = 1250;

    unique_collect1;
    string stringDsOutBounds;

    try
    {
        FAIL() << stringDsOutBounds;
    }
    catch (const std::exception& e)
    {
        EXPECT_EQ(unique_collection->size(), 250);
        throw;
    }


}

//This is the negative test that covers all cases and the indexes, subscripts, or pointers are tested 
//against array, record, or file bounds for the algorithm.

TEST_F(UniqueCollTest, ExceptionUniqueAlOutBounds)
{
    int unique_collect2 = 1350;

    unique_collect2;
    string stringAlOutBounds;

    try
    {
        FAIL() << stringAlOutBounds;
    }
    catch (const std::exception& e)
    {
        EXPECT_EQ(unique_collection->size(), 1000);

    }
}
