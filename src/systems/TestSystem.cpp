/*
** EPITECH PROJECT, 2020
** TestSystem.cpp
** File description:
** 
*/

#include "systems/TestSystem.h"
// don't miss this include !!
#include "ecs/engine/Engine.h"

TestSystem::TestSystem(ECS::Engine *engine) : ECS::System(engine)
{
    /*
     * Set the signature of this system.
     * All registered components
     */
    registerComponent<TestComponent>();
}

void TestSystem::update(double deltaTime)
{
    // Loop through all registered entities
    for (auto &entity : _registeredEntities) {
        // get component ptr of this entity
        // do not use _engine->getComponent<..> to get your component!
        TestComponent *testComponent = getComponent<TestComponent>(entity->first);

        // update your component as you want
        testComponent->x += 1;
        testComponent->y += 1;
        std::cout << "Entity " << entity->first << ": x=" << testComponent->x << ", y:" << testComponent->y << std::endl;
    }
}