//
// Created by wojczakowskik on 3/14/25.
//

#ifndef FRUIT_H
#define FRUIT_H

enum class Color { red , orange , green , violet } ;
enum class Fruits { apple , orange , plum } ;

struct Fruit {
    Fruits type ;
    Color color ;
};

static constexpr Fruit RipeApple{Fruits::apple, Color::violet}; ;
static constexpr Fruit GoodApple{Fruits::apple, Color::green};
static constexpr Fruit RipeOrange{Fruits::orange, Color::green};
static constexpr Fruit GoodOrange{Fruits::orange, Color::orange};
static constexpr Fruit RipePlum{Fruits::plum, Color::green};
static constexpr Fruit GoodPlum{Fruits::plum, Color::violet};


#endif //FRUIT_H
