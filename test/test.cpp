#include <gtest/gtest.h>

extern "C" {
    #include "wappenheim/vector.h"
}

TEST(VectorTest, CreateAndDestroy) {
    WappenheimVector *vec;

    vec = wappenheim_vector_create(sizeof(int));
    EXPECT_FALSE(vec == NULL) << "Unable to create the vector!";
    EXPECT_EQ(vec->item_size, sizeof(int)) << "Size of one item is not equal to the defined size!";
    EXPECT_EQ(vec->length, 0) << "Primary length of the vector must be 0!";
    wappenheim_vector_destroy(vec);
}

TEST(VectorTest, AppendAndPop) {
    int i, j;
    WappenheimVector *vec;

    vec = wappenheim_vector_create(sizeof(int));
    EXPECT_FALSE(vec == NULL) << "Unable to create the vector!";
    for (i = 0; i < 1000; ++i) {
        EXPECT_TRUE(wappenheim_vector_append(vec, &i) == 0) << "Unable to append!";
        EXPECT_TRUE(wappenheim_vector_get(vec, (size_t)i, &j) == 0) << "Unable to get!";
        EXPECT_EQ(i, j) << "The appended item is not equal!";
    }
    EXPECT_EQ(vec->length, 1000) << "The vector length must be 1000!";
    for (i = 999; i > -1; --i) {
        EXPECT_TRUE(wappenheim_vector_pop(vec, &j) == 0) << "Unable to pop!";
        EXPECT_EQ(i, j) << "Incorrent item!";
    }
    EXPECT_EQ(vec->length, 0) << "The vector length must be 0!";
    wappenheim_vector_destroy(vec);
}

TEST(VectorTest, InsertAndGet) {
    int i;
    WappenheimVector *vec;

    vec = wappenheim_vector_create(sizeof(int));
    EXPECT_FALSE(vec == NULL) << "Unable to create the vector!";

    i = 52;
    EXPECT_TRUE(wappenheim_vector_insert(vec, 696, &i) == 0) << "Unable to insert!";
    EXPECT_TRUE(wappenheim_vector_get(vec, 696, &i) == 0) << "Unable to get!";
    EXPECT_EQ(i, 52) << "The inserted item is not equal!";
    EXPECT_FALSE(wappenheim_vector_get(vec, 697, &i) == 0) << "Get item by index that is bigger than vector length!";
    wappenheim_vector_destroy(vec);
}