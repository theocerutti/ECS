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
     * Really important. Your components must always have a defaulted Component!
     */
    TestComponent() = default;

    /*
     * 'Custom' constructor
     */
    TestComponent(int x, int y) : x(x), y(y) {}
    int x{0};
    int y{0};
};

#endif //INDIESTUDIO_TESTCOMPONENT_H
