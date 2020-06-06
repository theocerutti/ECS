/*
** EPITECH PROJECT, 2020
** Engine.h
** File description:
** 
*/

#ifndef INDIESTUDIO_ENGINE_H
#define INDIESTUDIO_ENGINE_H

#include <iostream>
#include <functional>
#include <unordered_map>
#include "../entities/Entity.h"
#include "../systems/System.h"

namespace ECS {
    class Engine {
    public:
        /*
         * Engine constructor
         */
        Engine() = default;

        /*
         * Create entity and returns its id
         */
        const ECS::EntityID createEntity();

        /*
         * Remove entity by id, remove entity in associated systems
         */
        void removeEntity(const EntityID &entity);

        /*
         * Remove system
         */
        void removeSystem(const System *system);

        /*
         * Update
         */
        void update(double deltaTime);

        /*
         * Add component to entity
         */
        template<typename ComponentType, typename ...ctorComponentTArgs>
        void addComponent(const EntityID &entityID, ctorComponentTArgs... ctorComponentArgs)
        {
            ComponentArray &components = _entities.at(entityID);

            if (std::find_if(components.begin(), components.end(), [](const std::shared_ptr<BaseComponent> &compo){
                return (compo->getID() == ComponentType::ID);
            }) == components.end()) {
                components.push_back(std::make_shared<ComponentType>(std::forward<ctorComponentTArgs>(ctorComponentArgs)...));
                // add entity to system
                for (const std::unique_ptr<System> &system : _systems) {
                    const std::vector<ComponentID> &signature = system->getRegisteredComponentIDs();
                    auto it = std::find_if(_entities.begin(), _entities.end(), [&entityID](const EntityHandle &entity) {
                        return (entity.first == entityID);
                    });
                    if (system->isRegisterable(&*it)) {
                        system->registerEntity(&*it);
                    }
                }
            }
        }

        /*
         * Remove component entity
         */
        template<typename ComponentType>
        void removeComponent(const EntityID &entity)
        {
            // check if entity exists and have the component
            if (_entities.find(entity) != _entities.end() && getComponent<ComponentType>(entity) != nullptr) {
                ComponentArray &components = _entities.at(entity);
                for (System *system : getSystems<ComponentType>())
                    system->unregisterEntity(entity);
                components.erase(std::remove_if(components.begin(), components.end(),
                [](const std::shared_ptr<BaseComponent> &compo) {
                    return (compo->getID() == ComponentType::ID);
                }));
            }
        }

        /*
         * Get component from entity
         */
        template<typename ComponentType>
        ComponentType *getComponent(const EntityID &entity) const
        {
            const ComponentArray &vec = _entities.at(entity);

            for (const std::shared_ptr<BaseComponent> &compo : vec) {
                if (compo->getID() == ComponentType::ID)
                    return (dynamic_cast<ComponentType *>(compo.get())); // TODO: bad!
            }
            return (nullptr);
        }

        /*
         * Create system
         */
        template<typename SystemType, typename ...ctorSystemTArgs>
        SystemType *createSystem(ctorSystemTArgs... ctorSystemArgs)
        {
            _systems.push_back(std::make_unique<SystemType>(this, std::forward<ctorSystemTArgs>(ctorSystemArgs)...));
            for (EntityHandle &entity : _entities) {
                if (_systems.back()->isRegisterable(&entity))
                    _systems.back()->registerEntity(&entity);
            }
            return (dynamic_cast<SystemType *>(_systems.back().get())); // TODO: bad!
        }

    private:
        /*
         * Returns a vector of system where ComponentType is registered
         */
        template<typename ComponentType>
        std::vector<System *> getSystems()
        {
            std::vector<System *> vec;

            for (const std::unique_ptr<System> &system : _systems) {
                if (system->hasRegisteredComponent<ComponentType>())
                    vec.push_back(system.get());
            }
            return (vec);
        }

        std::vector<std::unique_ptr<System>> _systems{};
        std::unordered_map<EntityID, ComponentArray> _entities; // TODO: to std::unordered_map<EntityID, EntityHandle> ? easier
    };
}

#endif //INDIESTUDIO_ENGINE_H
