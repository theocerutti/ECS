/*
** EPITECH PROJECT, 2020
** BaseComponent.h
** File description:
** 
*/

#ifndef INDIESTUDIO_BASECOMPONENT_H
#define INDIESTUDIO_BASECOMPONENT_H

namespace ECS {
    using ComponentID = std::size_t;
    static ComponentID componentID = 0;

    struct BaseComponent {
        static ComponentID nextID() { return (componentID++); }
        virtual const ComponentID &getID() const = 0;
    };

    template<typename T>
    struct ECSComponent : public BaseComponent {
        static const ComponentID ID;
        const ComponentID &getID() const override { return(T::ID); };
    };

    template<typename T>
    const ComponentID ECSComponent<T>::ID(BaseComponent::nextID());
}

#endif //INDIESTUDIO_BASECOMPONENT_H
