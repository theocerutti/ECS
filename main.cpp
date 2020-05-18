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

    // create the system TestSystem and add it to the engine
    // systems needs to be created before creatingEntity
    engine.createSystem<TestSystem>();

    // create 2 entities
    ECS::EntityID entity0 = engine.createEntity();
    ECS::EntityID entity1 = engine.createEntity();

    // add TestComponent(10, 10) to entity1 by constructing it component
    engine.addComponent<TestComponent>(entity1, 10, 10);
    // add TestComponent to entity0 without constructing it component (use default ctor)
    engine.addComponent<TestComponent>(entity0);
    // remove TestComponent from entity0
    engine.removeComponent<TestComponent>(entity0);
    // remove entity 0 from engine
    engine.removeEntity(entity0);

    // update all entities
    for (int i = 0; i < 20; i++) {
        engine.update(0);
    }
}