#ifndef CHARACTER_H
#define CHARACTER_H


class Character
{
    public:

        int MaxHP;
        int HP;

        int Attack;
        int Defense;
        int Heal;
        int Potions;
        int PotionCooldown;

        Character();
        virtual ~Character();


        void setCharacter(int MaxHP, int HP, int Attack, int Defense, int Heal);
        void setPotions(int Potions);
        void addPot();
        void subPot();
        void consumePot();
        void refreshCooldown();
    protected:
    private:
};

#endif // CHARACTER_H
