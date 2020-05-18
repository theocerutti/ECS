/*
** EPITECH PROJECT, 2020
** Entity.cpp
** File description:
** 
*/

#include "ecs/entities/Entity.h"

const ECS::EntityID ECS::Entity::nextID()
{
    return (idCounter++);
}