/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
**
*/

#include "ecs/engine/Engine.h"
#include "components/TestComponent.h"
#include "systems/TestSystem.h"

int main()
{
    // create engine
    ECS::Engine engine;

    for (int i = 0; i < 100000; i++) {
        ECS::EntityID id = engine.createEntity();
        engine.addComponent<TestComponent>(id, 10, 10, 10);
    }
}