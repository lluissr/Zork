# Zork

This is my version of the game Zork. I have called it **'I have a bath urge' Zork**. In this game you have to write commands to perform actions and reach the end and be able to win the game.

In this game you are a man named Pepe and you have come home after a hard day's work and you have to go to the bathroom urgently. You have to find toilet paper and get to the toilet before you can not take it anymore!

To add a sense of urgency I added a counter. You only have 30 actions before you can not take it anymore and lose. 

**Have fun!!**

## How to play guide

In this section you will see the different commands and how to finish the game.

### Instructions

In this game of Zork you have different commands that you can use for finish the game. 

#### Look

The "look" command allows you to see what is in the room, how is an item or look at yourself. 
```
look              -- To see What is in the room
look {item name}  -- To see a description of the item. Ex: look box
look myself       -- To look at youself
```

#### Go

The "go" command allows you to move between rooms. You can use also a cardinal point to go to that direction.
```
go {cardinal point}   -- north, south, east, west
west
east
north
south
```

#### Take

The "take" command allows you to get items that are in the room or inside other items. You can use "get" or "pick" words insted o "take" if you want.
```
take {item name}  -- Ex: take box
get {item name}   -- Ex: get key
pick {item name}  -- Ex: pick paper
```

#### Drop

The "drop" command allows you to put items that are in your inventory inside other items or in the room. You can use "release" or "put" words insted o "drop" if you want.
```
drop {item name}                                  -- Ex: drop box
release {item name}                               -- Ex: release key
put {item name} inisde {container item name}      -- Ex: put paper into box
```

#### Inventory

The "inventory" command allows you to see which items have you picked before.
```
inventory
```

#### Open

The "open" command allows you to open doors that are closed and items that can be opened.
```
open {door name}      -- Ex: open door
open {item name}      -- Ex: open box
```

#### Close

The "close" command allows you to close doors that are opened and items that can be closed.
```
close {door name}      -- Ex: open door
close {item name}      -- Ex: close closet
```

#### Unlock

The "unlock" command allows you to unlock doors that are locked with a special items like keys or passwords. You need to specify which object do you want to use to unlock the door.
```
unlock {door name} with {item name}     -- Ex: unlock door with key
```

#### Lock

The "lock" command allows you to lock doors that are unlocked with a special items like keys or passwords. You need to specify which object do you want to use to lock the door.
```
lock {door name} with {item name}     -- Ex: lock door with password
```

#### Sit

The "sit" command allows you to sit. This action will only let you perform if you have reached the end of the game.
```
sit
```

### How to finish the game

A step by step guide of how finish this game:

```
open box
get key
unlock door with key
open door
go north
go east
open oven
get password
go west
go north
get paper
go south
go west
unlock door with password
open door
go north
open toilet
sit
```

To finish the game as fast as possible before the time runs out, you have to enter 18 commands. Remember that you only have 30 command in total before losing.

## Notes

This game of Zork has two special features
### Lock and unlock doors

In this game you can **lock and unlock doors**. You will need to unlock two doors with different items to reach the objective (bathroom). 

It is not necessary to lock any doors to win the game but if you close the bathroom door before sitting on the toilet Pepe will be grateful :)

To develop this feature I have related an item with an exit. In this way you make sure that only this item can open this exit.

### Counter

In 'I have a bath urge'Zork you have to win the game before Pepe can not take it anymore and fail. To add a sense of urgency (because everyone knows how desperate you are when you have to go to the bathroom and you can not take it anymore) I added a **counter**.

This counter will increment everytime you do an action. And you can only do 30 actions before lose.

## Authors

* **Lluís Sánchez Roig** - [Lluissr](https://github.com/lluissr)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details
