#include "Animal.h"
#include "Wolf.h"
#include <cstdio>

Wolf::Wolf(int x, int y, int velocity, SDL_Surface *surface_ptr, Uint32 life_time)
    : Animal(x, y, velocity, surface_ptr, "./media/wolf.png", MALE, life_time)
{
}

Wolf::~Wolf()
{
}

void Wolf::move(const std::vector<Entity *> entities, int direction)
{
    Entity *targeted_entity = NULL;
    int targeted_distance = 99999;
    bool can_hunt = true;

    for (size_t i = 0; i < entities.size(); i++)
    {
        int distance = Entity::compute_distance(entities[i]);
        if (Entity::is_near(entities[i]) && !entities[i]->name().compare("Dog"))
        {
            targeted_entity = entities[i];
            can_hunt = false;
            break;
        }
        else if (!entities[i]->name().compare("Sheep") && distance < targeted_distance)
        {
            targeted_entity = entities[i];
            targeted_distance = distance;
        }
    }

    if (targeted_entity == NULL)
    {
        int moveX = -8 + (rand() % static_cast<int>(17));
        int moveY = -8 + (rand() % static_cast<int>(17));
        Entity::step(moveX, moveY);
    }
    else if (can_hunt)
    {
        int diff_x = (this->get_x() - targeted_entity->get_x());
        int diff_y = (this->get_y() - targeted_entity->get_y());

        int moveX = (diff_x >= 0) ? -8 : 8;
        int moveY = (diff_y >= 0) ? -8 : 8;
        Entity::step((diff_x < -8 || diff_x > 8) ? moveX : 0, (diff_y < -8 || diff_y > 8) ? moveY : 0);
    }
    else
    {
        int diff_x = (this->get_x() - targeted_entity->get_x());
        int diff_y = (this->get_y() - targeted_entity->get_y());

        int moveX = (diff_x <= 0) ? -10 : 10;
        int moveY = (diff_y <= 0) ? -10 : 10;
        Entity::step(moveX, moveY);
    }
}

void Wolf::action()
{
}

std::string Wolf::name()
{
    return "Wolf";
}