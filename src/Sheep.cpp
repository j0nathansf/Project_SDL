#include "Animal.h"
#include "Sheep.h"
#include <cstdio>
#include <SDL2/SDL.h>

Sheep::Sheep(int x, int y, int velocity, SDL_Surface *surface_ptr, bool is_male)
    : Animal(x, y, velocity, surface_ptr,
             is_male ? "./media/msheep.png" : "./media/wsheep.png",
             is_male ? MALE : FEMALE, DEFAULT_LIFE_TIME)
{
}

Sheep::~Sheep()
{
}

void Sheep::move(const std::vector<Entity *> entities, int direction)
{

    int targeted_entity = -1;

    for (size_t i = 0; i < entities.size(); i++)
    {
        if (Entity::is_near(entities[i]) && !entities[i]->name().compare("Wolf"))
            targeted_entity = i;
    }

    if (targeted_entity != -1)
    {
        int diff_x = (this->get_x() - entities[targeted_entity]->get_x());
        int diff_y = (this->get_y() - entities[targeted_entity]->get_y());

        int moveX = (diff_x <= 0) ? -50 : 50;
        int moveY = (diff_y <= 0) ? -50 : 50;
        Entity::step(moveX, moveY);
    }
    else
    {
        int moveX = -8 + (rand() % static_cast<int>(17));
        int moveY = -8 + (rand() % static_cast<int>(17));
        Entity::step(moveX, moveY);
    }
}

std::tuple<std::string, int> Sheep::action(std::vector<Entity *> entities)
{
    int targeted_entity = -1;
    int targeted_distance = 9999;

    if (this->gender == FEMALE)
    {
        return std::make_tuple("NULL", -1);
    }

    for (size_t i = 0; i < entities.size(); i++)
    {
        int distance = Entity::compute_distance(entities[i]);
        if (Entity::is_near(entities[i]) && !entities[i]->name().compare("Sheep") && distance < targeted_distance)
        {
            Animal *sheep = dynamic_cast<Animal *>(entities[i]);
            if (sheep->is_male())
            {
                targeted_entity = i;
                targeted_distance = distance;
            }
        }
    }

    if (targeted_entity != -1)
    {
        return std::make_tuple("ADD", targeted_entity);
    }
    return std::make_tuple("NULL", -1);
}

std::string Sheep::name()
{
    return "Sheep";
}
