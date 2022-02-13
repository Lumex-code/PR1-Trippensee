//decalration of Struct, wich we use to give our Objects the Stats and description in order to work with them
//can be called upon for example by: obj->tag | we call the tag of the given obj.
typedef struct object {
    const char* description;
    const char* tag;
    struct object* location;
    int Status;
    int weight;
    struct object* destination;
    
} OBJECT;


//defining symbolic Names to make it easier to work with.
extern OBJECT objs[];

//6xLocations
#define mine        (objs + 0)
#define cave        (objs + 1)
#define forest      (objs + 2)
#define hut         (objs + 3)
#define bedroom     (objs + 4)
#define backyard    (objs + 5)
#define shed        (objs + 6)

//7xPatheways
#define ex_mine      (objs + 7) //exit mine
#define en_mine      (objs + 8)  //entrance mine
#define ex_cave      (objs + 9)
#define en_cave      (objs + 10)
#define ex_forest    (objs + 11)
#define en_forest    (objs + 12)
#define ex_bedr      (objs + 13)
#define en_bedr      (objs + 14)
#define ex_hut       (objs + 15)
#define en_hut       (objs + 16)
#define ex_backy     (objs + 17)
#define en_backy     (objs + 18)
#define ex_shed      (objs + 19)
#define en_shed      (objs + 20)
#define hole         (objs + 21)

//22xItems
#define pickaxe     (objs + 22)
#define vein        (objs + 23)
#define oven        (objs + 24)
#define gold        (objs + 25)
#define guard       (objs + 26)
#define chest       (objs + 27)
#define rustysword  (objs + 28)
#define axe         (objs + 29)
#define wood        (objs + 30)
#define bed         (objs + 31)
#define wardrobe    (objs + 32)
#define table       (objs + 33)
#define paper       (objs + 34)
#define box         (objs + 35)
#define key         (objs + 36)
#define note        (objs + 37)
#define keychain    (objs + 38)
#define door        (objs + 39)
#define rack        (objs + 40)
#define picture     (objs + 41)
#define helmet      (objs + 42)
#define hat         (objs + 43)
#define watermelon  (objs + 44)
#define peel        (objs + 45)
#define rune        (objs + 46)
#define fridge      (objs + 47)
#define heap        (objs + 48)
#define rock        (objs + 49)
#define rawGold     (objs + 50)


//Player
#define player (objs + 51)
//endofObjs so we know how long the list is
#define endOfObjs  (objs + 52)
