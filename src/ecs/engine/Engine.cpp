/*
** EPITECH PROJECT, 2020
** Engine.cpp
** File description:
** 
*/

#include "ecs/engine/Engine.h"

const ECS::EntityID ECS::Engine::createEntity()
{
    EntityID id = ECS::Entity::nextID();

    _entities.emplace(id, ComponentArray());
    return (id);
}

void ECS::Engine::removeEntity(const ECS::EntityID &entityID)
{
    for (const std::unique_ptr<System> &system : _systems) {
        if (system->isRegistered(entityID)) {
            system->unregisterEntity(entityID);
        }
    }
    _entities.erase(entityID);
}

void ECS::Engine::update(double deltaTime)
{
    for (const std::unique_ptr<System> &system : _systems)
        system->update(deltaTime);
}

void ECS::Engine::removeSystem(const System *system)
{
    if (system) {
        _systems.erase(
                std::remove_if(_systems.begin(), _systems.end(), [system](const std::unique_ptr<System> &systemGiven) {
                    return (system == systemGiven.get());
                }), _systems.end());
    }
}