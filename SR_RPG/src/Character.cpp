#include "Character.h"

Character::Character()
{
    //ctor
}

Character::~Character()
{
    //dtor
}

void Character::setCharacter(int MaxHP, int HP, int Attack, int Defense, int Heal)
{
    this->MaxHP = MaxHP;
    this->HP = HP;
    this->Attack=Attack;
    this->Defense=Defense;
    this->Heal=Heal;
    this->PotionCooldown=0;

}

void Character::setPotions(int Potions)
{
    this->Potions=Potions;
}

void Character::addPot()
{
    setPotions(this->Potions+1);
}

void Character::subPot()
{
    if(Potions > 0)
    {
        setPotions(this->Potions-1);
    }
}

void Character::consumePot()
{
    //Blaze it 4:20.
    subPot();
    this->PotionCooldown=3;
}

void Character::refreshCooldown()
{
    if(PotionCooldown > 0)
    {
        PotionCooldown--;
    }
}
