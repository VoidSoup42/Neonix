#pragma once
#include "Graphics/Layer.hpp"
#include <stdio.h>


class TestLayer : public Neonix::Layer
{
public:
    inline TestLayer()
    {
        printf("Test Layer Created");
    }

    virtual ~TestLayer() override
    {
        printf("Test Layer Destroyed");
    }

    virtual void OnUpdate() override
    {
        printf("Test Layer Updating");
    }
};
