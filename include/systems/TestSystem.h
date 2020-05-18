/*
** EPITECH PROJECT, 2020
** TestSystem.h
** File description:
** 
*/

#ifndef INDIESTUDIO_TESTSYSTEM_H
#define INDIESTUDIO_TESTSYSTEM_H

#include "../ecs/systems/System.h"
#include "../components/TestComponent.h"

class TestSystem : public ECS::System {
public:
    /*
     * Must always have a Constructor with Engine parameter
     */
    explicit TestSystem(ECS::Engine *engine);

    /*
     * Overrided method
     */
    void update(double deltaTime) override;
};


#endif //INDIESTUDIO_TESTSYSTEM_H
