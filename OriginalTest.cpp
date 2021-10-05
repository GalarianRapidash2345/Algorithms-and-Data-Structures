// Uncomment the next line to use precompiled headers

#include "pch.h"

// uncomment the next line if you do not use precompiled headers

//#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here

//These are the defined assertions and expectations that are specific to each test

#define ASSERT_CAP_GREATER_EQUAL
#define EXPECT_THROW

using namespace std;

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

// create our test class to house shared data between tests
// you should not need to change anything here

class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;    //properly initialize index

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }

    //define symbolics
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called

TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    // is the collection created
    ASSERT_TRUE(collection);

    // if empty, the size must be 0
    ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer */

//TEST_F(CollectionTest, AlwaysFail)
//{
    //FAIL();
//}




// TODO: Create a test to verify adding a single value to an empty collection

//This test verifies adding a single value to an empty collection. Using EXPECT will verify that when the collection points
//to empty, the processing will continue as the size is to be detected as either 0 or 1 for entry size. 

TEST_F(CollectionTest, CanAddToEmptyVector)  //Refine this test
{
    // is the collection empty?
    // if empty, the size must be 0

    add_entries(1);
   // EXPECT_EQ(collection->empty(), 1); //eliminate redundancy

    //ASSERT_TRUE(collection->empty(), 0);

    ASSERT_EQ(collection->size(), 1);

    // is the collection still empty?
    // if not empty, what must the size be?
}



// TODO: Create a test to verify adding five values to collection

//This test verifies adding five values to a collection that is not empty. Using EXPECT will verify that the processing will continue
//when the new size of the collection is detected. 

TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    add_entries(5);
    EXPECT_EQ(collection->size(), 5);
}



// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries

//This test verifies that the maximum size is greater than or equal to size for 0, 1, 5, and 10 entries.
//Creating a new assertion called ASSERT_GREATER validates that when the collection points to the maximum size, that size 
//must be greater than or equal to the defined sizes of the entries. 

TEST_F(CollectionTest, MaxSizeGreaterThanOrEqualEntries)
{
    add_entries(0); 
    add_entries(1);
    add_entries(5);
    add_entries(10);

    ASSERT_GE(collection->size(), 0);
    ASSERT_GE(collection->size(), 1);
    ASSERT_GE(collection->size(), 5);
    ASSERT_GE(collection->size(), 10);



}



// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries

//This test verifies that the capacity of the collection is greater than or equal to size for 0, 1, 5, and 10 entries.
//Creating a new assertion for the capacity validates that when the collection is retrieved, the capacity is determined to be
//greater than or equal to entry size. 

TEST_F(CollectionTest, CapacityGreaterThanOrEqualEntries)
{
    add_entries(0);
    add_entries(1);
    add_entries(5);
    add_entries(10);

    ASSERT_CAP_GREATER_EQUAL(collection.get(), 0);
    ASSERT_CAP_GREATER_EQUAL(collection.get(), 1);
    ASSERT_CAP_GREATER_EQUAL(collection.get(), 5);
    ASSERT_CAP_GREATER_EQUAL(collection.get(), 10);
}



// TODO: Create a test to verify resizing increases the collection

//This test verfifies if resizing increases the collection. The collection and size are reset, defined again, then incremented
//to determine if resizing will increment the collection. 

TEST_F(CollectionTest, ResizeIncreaseCollection)
{
    collection.reset(nullptr);
    ASSERT_TRUE(collection->size(), ++i);
}



// TODO: Create a test to verify resizing decreases the collection

//This test verifies if resizing decreases the collection. The collection and size are reset, defined again, then decremented
//to determine if resizing will decrement the collection.

TEST_F(CollectionTest, ResizeDecreaseCollection)
{
    collection.reset(nullptr);
    ASSERT_TRUE(collection->size(), --i);

}



// TODO: Create a test to verify resizing decreases the collection to zero

//This test verifies if resizing decreases the collection to zero. The collection and size are reset, defined again, then set to zero
//to determine if resizing will define the collection size to be zero. 

TEST_F(CollectionTest, ResizeDecreaseCollectionZero)
{
    collection.reset(nullptr);
    ASSERT_TRUE(collection->size(), 0);

}



// TODO: Create a test to verify clear erases the collection

//This test verifies that clear erases the collection. Clear and reset are initialized here to erase the collection, and
//an assertion is used to ensure that when the collection is erased, the collection is empty. 

TEST_F(CollectionTest, ClearEraseCollection)
{
    collection->clear();
    collection.reset(nullptr);
    ASSERT_TRUE(collection->empty());

}



// TODO: Create a test to verify erase(begin,end) erases the collection

//This test verifies that erase(begin,end) will erase the collection. Initializing erase, begin, and end to zero ensures that
//the size of the collection is empty when collection is erased. Using assertions will determine if the collection is empty during
//the erase with erase(begin, end). 

TEST_F(CollectionTest, BeginEndEraseCollection)
{
    int erase = 0;
    int begin = 0;
    int end = 0;

    ASSERT_TRUE(collection->empty(), erase);
    ASSERT_TRUE(collection->empty(), begin);
    ASSERT_TRUE(collection->empty(), end);

}



// TODO: Create a test to verify reserve increases the capacity but not the size of the collection

//This test verifies that the reserve will increase the capacity but not the size of the collection. Reserve is initialized as a maximum in order
//for the capacity to be affected by an increase. The size constant is not used, as the capacity is retrieved by .get(). Using
//assertions assist in checking the capacity with reserve and incrementing the capacity as well. 

TEST_F(CollectionTest, ReserveIncreaseCapacityCollection)
{
    int reserve = 99;

    ASSERT_TRUE(collection.get(), reserve);
    ASSERT_TRUE(collection.get(), ++i);

}



// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test

//This test verifies the std::out_of_range exception that is thrown when calling at() with an index out of bounds. 
//This test uses try and catch blocks for the exception, as well as a range definition, expectations and fails for the negative
//test. The try and catch blocks ensure that the std::out_of_range exception is thrown, and that at() is called with the index
//being out of bounds.

TEST_F(CollectionTest, ExceptionIndexOutOfBounds)
{

    int range = 0;

    range;
    try {
        FAIL() << "Index Out Of Range";
    }

    catch (const std::out_of_range& o)
    {
        EXPECT_EQ(collection->size(), 1);
        throw;
    }
    catch (const std::out_of_range& at())
    {
        EXPECT_EQ(collection->size(), 5); //This calls at() with index out of bounds.
        FAIL() << "Index Out Of Range";
    }

}



// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative

//Positive Test to verify the maximum value being added to an empty collection

//This test verifies that the maximum of 99 values can be added to an empty collection. Using expectations allows for the 
//maximum values to be tested without termination. 

TEST_F(CollectionTest, CanAddMaxToEmptyVector)
{
    add_entries(99);
    EXPECT_EQ(collection->empty(), 99);
}



//Negative Test to verify the general std::exception is thrown when calling get() with the collection size out of bounds

//This test verifies that std::exception is thrown when calling get() with the collection size out of bounds.
//The collection is defined, and try and catch blocks are used with expectations as well as fails for validating collection size.
//The try and catch blocks ensure collection size is detected for the exception. 

TEST_F(CollectionTest, ExceptionCollSizeOutOfBounds)
{
    int collect = 0;

    collect;      //indexes, subscripts, or pointers are tested against array, record, or file bounds for the data structure.
    try {
        FAIL() << "Size Out Of Bounds"; //use symbolics
    }
    catch (const std::exception& e)
    {
        EXPECT_EQ(collection->size(), 5);
        throw;
    }
    catch (const std::exception& get())  //indexes, subscripts, or pointers are tested against array, record, or file bounds for the algorithm.
    {
        EXPECT_EQ(collection->size(), 10); //This calls get() with size out of bounds.
        FAIL() << "Size Out Of Bounds"; //use symbolics
    }
}



//Need two new tests for data structure and algorithms
