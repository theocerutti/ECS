/*
** EPITECH PROJECT, 2020
** Entity.h
** File description:
** 
*/

#ifndef INDIESTUDIO_ENTITY_H
#define INDIESTUDIO_ENTITY_H

#include <iostream>
#include "../components/BaseComponent.h"

namespace ECS {
    using EntityID = std::size_t;
    namespace Entity {
        /*
         * Generate nextID for entity
         */
        const EntityID nextID();
        static EntityID idCounter = 0;
    }
}

#endif //INDIESTUDIO_ENTITY_H