#include "algs.h"

#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class HelpClass : public ::testing::Test
{
    protected:
    void SetUp() override
    {
        for (int i = 0; i < 5; ++i)
        {
            vec1.push_back(i);
            vec2.push_back(i);
            vec4.push_back(5 - i);
        }

        vec3.push_back(0);
    }

    // void TearDown() override {}

    vector<int> vec1;   // 0, 1, 2, 3, 4
    vector<int> vec2;   // 0, 1, 2, 3, 4
    vector<int> vec3;   // 0
    vector<int> vec4;   // 5, 4, 3, 2, 1
    vector<int> vec5;   // empty

    vector<int> remove1{0, 0, 0, 0, 0, 1, 1};
    vector<int> remove2{0};
    vector<int> remove3{1, 0, 2, 0, 3, 0, 4, 0, 5};
    vector<int> remove4{1, 0, 2, 0, 3, 0, 4, 0};
    vector<int> remove5{1, 2, 3, 4, 0, 5, 6, 7};
};

// ---------------------------------------------------------------------------

TEST_F(HelpClass, EQUALworksFine)
{
    EXPECT_TRUE(equal(vec1.begin(), vec1.end(), vec2.begin()));
    EXPECT_FALSE(equal(vec1.begin(), vec1.end(), vec4.begin()));
}
TEST_F(HelpClass, EQUALshortVector)
{
    EXPECT_FALSE(equal(vec1.begin(), vec1.end(), vec3.begin()));
}

// ---------------------------------------------------------------------------

TEST_F(HelpClass, FINDworksFine)
{
    EXPECT_EQ(my_find(vec1.begin(), vec1.end(), 3),
              std::find(vec1.begin(), vec1.end(), 3));
    EXPECT_EQ(my_find(vec1.begin(), vec1.end(), 0), vec1.begin());
    EXPECT_EQ(my_find(vec1.begin(), vec1.end(), 100), vec1.end());
}

// ---------------------------------------------------------------------------

TEST_F(HelpClass, COPYworksFine)
{
    my_copy(vec1.begin(), vec1.end(), std::back_inserter(vec5));
    EXPECT_TRUE(std::equal(vec1.begin(), vec1.end(), vec5.begin()));
}

// ---------------------------------------------------------------------------
//
// skip the easy tests
//
// ---------------------------------------------------------------------------

TEST_F(HelpClass, REMOVEworksFine1)
{
    vector<int>::iterator it = my_remove(remove1.begin(), remove1.end(), 0);
    EXPECT_EQ(it, remove1.begin() + 2);
    for (vector<int>::const_iterator i = remove1.begin(); i != remove1.end();
         ++i)
    {
        if (i == it)
        {
            cout << "X";
        }
        cout << *i << " ";
    }
    cout << endl;
}

TEST_F(HelpClass, REMOVEworksFine2)
{
    vector<int>::iterator it = my_remove(remove1.begin(), remove1.end(), 2);
    EXPECT_EQ(it, remove1.end());
    for (vector<int>::const_iterator i = remove1.begin(); i != remove1.end();
         ++i)
    {
        if (i == it)
        {
            cout << "X";
        }
        cout << *i << " ";
    }
    cout << endl;
}

TEST_F(HelpClass, REMOVEworksFine3)
{
    vector<int>::iterator it = my_remove(remove1.begin(), remove1.end(), 1);
    EXPECT_EQ(it, remove1.begin() + 5);
    for (vector<int>::const_iterator i = remove1.begin(); i != remove1.end();
         ++i)
    {
        if (i == it)
        {
            cout << "X";
        }
        cout << *i << " ";
    }
    cout << endl;
}

TEST_F(HelpClass, REMOVEworksFine4)
{
    vector<int>::iterator it = my_remove(remove2.begin(), remove2.end(), 0);
    EXPECT_EQ(it, remove2.begin());
    for (vector<int>::const_iterator i = remove2.begin(); i != remove2.end();
         ++i)
    {
        if (i == it)
        {
            cout << "X";
        }
        cout << *i << " ";
    }
    cout << endl;
}

TEST_F(HelpClass, REMOVEworksFine5)
{
    vector<int>::iterator it = my_remove(remove3.begin(), remove3.end(), 0);
    EXPECT_EQ(it, remove3.begin() + 5);
    for (vector<int>::const_iterator i = remove3.begin(); i != remove3.end();
         ++i)
    {
        if (i == it)
        {
            cout << "X";
        }
        cout << *i << " ";
    }
    cout << endl;
}

TEST_F(HelpClass, REMOVEworksFine6)
{
    vector<int>::iterator it = my_remove(remove4.begin(), remove4.end(), 0);
    EXPECT_EQ(it, remove4.begin() + 4);
    for (vector<int>::const_iterator i = remove4.begin(); i != remove4.end();
         ++i)
    {
        if (i == it)
        {
            cout << "X";
        }
        cout << *i << " ";
    }
    cout << endl;
}

TEST_F(HelpClass, REMOVEworksFine7)
{
    vector<int>::iterator it = my_remove(remove5.begin(), remove5.end(), 0);
    EXPECT_EQ(it, remove5.begin() + remove5.size() - 1);
    for (vector<int>::const_iterator i = remove5.begin(); i != remove5.end();
         ++i)
    {
        if (i == it)
        {
            cout << "X";
        }
        cout << *i << " ";
    }
    cout << endl;
}

// ---------------------------------------------------------------------------



int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}