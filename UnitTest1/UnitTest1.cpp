#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

struct Elem
{
    Elem* link1,
        * link2;
    int info;
};

Elem* p;

TEST_CLASS(UnitTest1)
{
public:

    TEST_METHOD(TestLinkedListDeletion)
    {
        p = new Elem;   //1

        p->info = 1;    //2

        p->link1 = new Elem;    //3
        p->link1->info = 2;     //4
        p->link1->link2 = p;    //5

        p->link1->link1 = new Elem;    //6
        p->link1->link1->info = 3;     //7
        p->link1->link1->link2 = nullptr;    //8
        p->link1->link1 = p;    //9

        p->link1->link2->link2 = new Elem;    //10
        p->link1->link2->link2->info = 4;     //11
        p->link1->link2->link2 = p->link1;       //12
        p->link1->link2->link2 = p->link1->link1->link2; //13

        delete p->link1->link2->link2; //14
        delete p->link1->link1;    //15
        delete p->link1;    //16
        delete p;   //17

        // Validate that all memory is deallocated
        Assert::IsNull(p);
    }
};
