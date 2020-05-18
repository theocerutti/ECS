/*
** EPITECH PROJECT, 2020
** System.h
** File description:
** 
*/

#ifndef INDIESTUDIO_SYSTEM_H
#define INDIESTUDIO_SYSTEM_H

#include <vector>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include "../entities/Entity.h"

// TODO: order of system's update matters. How we can resolve this issue ?
// Option1: add orderLevel variable that allows engine to update systems with order

namespace ECS {
    class Engine;

    using ComponentArray = std::vector<std::shared_ptr<BaseComponent>>;
    using EntityHandle = std::pair<const EntityID, ComponentArray>;

    class System {
    public:
        /*
         * Constructor
         */
        explicit System(const Engine *engine);

        /*
         * Update all components entities
         */
        virtual void update(double deltaTime) = 0;

        /*
         * Returns _registeredComponentIDs
         */
        const std::vector<ComponentID> &getRegisteredComponentIDs() const;

        /*
         * Returns _registeredEntities
         */
        const std::vector<EntityHandle *> &getRegisteredEntities() const;

        /*
         * Register entity. System will apply update on it.
         */
        void registerEntity(EntityHandle *entity);

        /*
         * Unregister entity
         */
        void unregisterEntity(const ECS::EntityID &entityToDelete);

        /*
         * Check if an entity is registerable in this system. The entity needs to have all the components
         * registered in this system
         */
        bool isRegisterable(const EntityHandle *entity) const;

        /*
         * Check if entity is registered to this system
         */
        bool isRegistered(const EntityID &entityId);

        /*
         * Check if Component is registered in this system
         */
        template<typename ComponentType>
        bool hasRegisteredComponent() const
        {
            return (std::find(_registeredComponentIDs.begin(), _registeredComponentIDs.end(), ComponentType::ID) != _registeredComponentIDs.end());
        }

    protected:
        /*
         * Register component. Multi Param
         */
        template<typename ComponentType, typename ...ComponentArgs,
                std::enable_if_t<sizeof...(ComponentArgs) != 0>* = nullptr>
        void registerComponent()
        {
            registerComponent<ComponentType>();
            registerComponent<ComponentArgs...>();
        }

        /*
         * Register component. Single Param
         */
        template<typename ComponentType>
        void registerComponent()
        {
            if (!hasRegisteredComponent<ComponentType>()) {
                _registeredComponentIDs.push_back(ComponentType::ID);
            }
        }

        /*
         * Returns entity component if component is not registered in this system returns nullptr
         */
        template<typename ComponentType>
        ComponentType *getComponent(const EntityID &entityId)
        {
            if (!hasRegisteredComponent<ComponentType>()) {
                return (nullptr);
            } else {
                auto handleIt = std::find_if(_registeredEntities.begin(), _registeredEntities.end(), [&entityId](const EntityHandle *entityHandle) {
                    return (entityHandle->first == entityId);
                });
                const ComponentArray &components = (*handleIt)->second;
                auto it = std::find_if(components.begin(), components.end(), [](const std::shared_ptr<BaseComponent> &compo) {
                    return (compo->getID() == ComponentType::ID);
                });
                return (dynamic_cast<ComponentType *>((*it).get())); // TODO: bad
            }
        }

    protected:
        std::vector<ComponentID> _registeredComponentIDs{};
        std::vector<EntityHandle *> _registeredEntities{};
        const Engine *_engine{nullptr};
    };
}

#endif //INDIESTUDIO_SYSTEM_H
