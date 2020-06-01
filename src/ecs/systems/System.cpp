/*
** EPITECH PROJECT, 2020
** System.cpp
** File description:
** 
*/

#include "ecs/systems/System.h"
#include "ecs/engine/Engine.h"

ECS::System::System(const Engine *engine) : _engine(engine)
{
}

const std::vector<ECS::ComponentID> &ECS::System::getRegisteredComponentIDs() const
{
    return (_registeredComponentIDs);
}

void ECS::System::registerEntity(EntityHandle *entity)
{
    if (entity) {
        const EntityID &idToAdd = entity->first;

        if (!isRegistered(entity->first)) {
            _registeredEntities.push_back(entity);
        }
    }
}

void ECS::System::unregisterEntity(const ECS::EntityID &entityToDelete)
{
    _registeredEntities.erase(std::remove_if(_registeredEntities.begin(), _registeredEntities.end(), [&entityToDelete](const EntityHandle *entity) {
        return (entityToDelete == entity->first);
    }), _registeredEntities.end());
}

const std::vector<ECS::EntityHandle *> &ECS::System::getRegisteredEntities() const
{
    return (_registeredEntities);
}

bool ECS::System::isRegisterable(const EntityHandle *entity) const
{
    if (_registeredComponentIDs.empty())
        return (false);
    if (entity) {
        const ComponentArray &components = entity->second;
        std::vector<ComponentID> entitySignature;

        if (components.empty())
            return (false);
        for (const std::shared_ptr<BaseComponent> &compo : components)
            entitySignature.push_back(compo->getID());
        if (entitySignature.size() < _registeredComponentIDs.size())
            return (false);
        for (const ComponentID &id : _registeredComponentIDs) {
            if (std::find(entitySignature.begin(), entitySignature.end(), id) == entitySignature.end())
                return (false);
        }
    } else
        return (false);
    return (true);
}

bool ECS::System::isRegistered(const ECS::EntityID &entityId)
{
    return (std::find_if(_registeredEntities.begin(), _registeredEntities.end(), [&entityId](const EntityHandle *handle) {
        return (handle->first == entityId);
    }) != _registeredEntities.end());
}
