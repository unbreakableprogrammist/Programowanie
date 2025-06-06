#include<iostream>
using namespace std;
class Character
{
    private:
        string name;
        int health;
        int maxHealth;
    public : 
        Character(string name, int health = 100);
        string getName() const { return name; }
        int getHealth() const { return health; }
        bool isAlive() const { return health > 0; }
        void takeDamage(int damage);
        void heal(int amount);
        virtual void attack(Character* target);
        virtual ~Character() {}

    };
    class Warrior : public Warrior
    {
        private:
            int meleeDamage;
        public:
            Warrior(string name, int health = 120, int damage = 15);
            void attack(Character* target);
            ~Warrior() {}
    };