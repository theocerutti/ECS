# Example of system

```c++
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
```

# Example of Component

```c++
#include "../ecs/components/BaseComponent.h"

struct TestComponent : ECS::ECSComponent<TestComponent> {
    /*
     * Really important. Your components must always have a defaulted Component!
     */
    TestComponent() = default;

    /*
     * 'Custom' constructor
     */
    TestComponent(int x, int y) : x(x), y(y) {}
    int x{0};
    int y{0};
};
```

# Example of main

```c++
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
    // game loop
    for (int i = 0; i < 20; i++) {
        engine.update(0);
    }
}
```

## Output:

```
Entity 1: x=11, y:11
Entity 1: x=12, y:12
Entity 1: x=13, y:13
Entity 1: x=14, y:14
Entity 1: x=15, y:15
Entity 1: x=16, y:16
Entity 1: x=17, y:17
Entity 1: x=18, y:18
Entity 1: x=19, y:19
Entity 1: x=20, y:20
Entity 1: x=21, y:21
Entity 1: x=22, y:22
Entity 1: x=23, y:23
Entity 1: x=24, y:24
Entity 1: x=25, y:25
Entity 1: x=26, y:26
Entity 1: x=27, y:27
Entity 1: x=28, y:28
Entity 1: x=29, y:29
Entity 1: x=30, y:30
```