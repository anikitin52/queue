#include <gtest.h>
#include "Queue.h"

TEST(Queue, CanCreateQueue) {
    ASSERT_NO_THROW(Queue<int>(3));
}

TEST(Queue, IsEmptyOnCreation) {
    Queue<int> q;
    ASSERT_EQ(q.isEmpty(), true);
}

TEST(Queue,CanPushElement) {
    Queue<int> q(3);
    ASSERT_NO_THROW(q.push(10));
}

TEST(Queue, CanPushIfFull) {
    Queue<int> q(3);

    q.push(1);
    q.push(2);
    q.push(3);
    ASSERT_NO_THROW(q.push(4));
}

TEST(Queue, NotEmptyAfterPush) {
    Queue<int> q(3);

    q.push(1);
    ASSERT_EQ(q.isEmpty(), false);
}

TEST(Queue, CantPopFromEmptyQueue) {
    Queue<int> q(3);

    ASSERT_ANY_THROW(q.pop());
}

TEST(Queue, PopTest) {
    Queue<int> q(3);

    q.push(1);
    q.push(2);
    ASSERT_EQ(q.pop(), 1);
}

TEST(Queue, FullQueue) {
    Queue<int> q(3);

    q.push(1);
    q.push(2);
    q.push(3);

    ASSERT_EQ(q.isFull(), true);
}

TEST(Queue, EmptyQueue) {
    Queue<int> q(3);

    q.push(1);
    q.push(2);
    q.push(3);

    q.pop();
    q.pop();
    q.pop();

    ASSERT_EQ(q.isEmpty(), true);
}

TEST(Queue, CanGetSize) {
    Queue<int> q(3);

    q.push(1);
    q.push(2);
    q.push(3);
    ASSERT_EQ(q.size(), 3);
}

TEST(Queue, ClearQueueSizeZero) {
    Queue<int> q(3);

    q.push(1);
    q.push(2);
    q.push(3);

    q.clear();
    ASSERT_EQ(q.size(), 0);
}

TEST(Queue, ClearQueueIsEmpty) {
    Queue<int> q(3);

    q.push(1);
    q.push(2);
    q.push(3);

    q.clear();
    ASSERT_EQ(q.isEmpty(), true);
}

