/*
** EPITECH PROJECT, 2020
** TestComponent.h
** File description:
** 
*/

#ifndef INDIESTUDIO_TESTCOMPONENT_H
#define INDIESTUDIO_TESTCOMPONENT_H

#include "../ecs/components/BaseComponent.h"

struct TestComponent : ECS::ECSComponent<TestComponent> {
    /*
     * Default constructor
     */
    TestComponent() = default;

    /*
     * 'Custom' constructor
     */
    TestComponent(int x, int y, int z) : x(x), y(y), z(z) {}
    int x{0};
    int y{0};
    int z{0};
};

#endif //INDIESTUDIO_TESTCOMPONENT_H
