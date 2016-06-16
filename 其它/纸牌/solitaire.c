/*
 * 发牌和洗牌
 */
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

typedef enum { false = 0, true } bool; 
typedef enum { 
        Ace, Two, Three, Four, Five, Six, Seven, Eight, 
	    Nine, Ten, Jack, Queeen, King, 
	    CARDS_PER_SUIT//=14, 每桌上的最大牌数
} FaceValue; 
const char *FaceValueStr[] = 
    { "A", "2", "3", "4", "5", "6", 
	        "7", "8", "9", "10", "J", "Q", "K" }; 
typedef enum { 
        Hearts, Diamonds, Clubs, Spades,
	SUITS_PER_DECK//每桌最大花色数
} Suit; 
const char *SuitStr[] = { "H",//heart红心
			  "D",//diamond方块
			  "C",//club草花
			  "S" };//spade黑桃
typedef struct {
    Suit suit;
    FaceValue face;
    bool inDeck;
} Card;
typedef Card Deck[SUITS_PER_DECK*CARDS_PER_SUIT];//4*14张牌
const int CARDS_PER_DECK = SUITS_PER_DECK*CARDS_PER_SUIT;//每桌牌数

int Random(int range);
void newDeck(Deck);
void printDeck(const Deck);
void shuffle(Deck,Deck);

int main(int argc, char *argv[])
{
    Deck d1,d2;
    time_t t;

    srand((unsigned)time(&t)); //产生随机数种子
    newDeck(d1);//默认发牌
#if 0
    printf("\nNew deck:\n");
    printDeck(d1);
#endif
    shuffle(d1,d2);
    printf("\n洗牌后:\n");
    printDeck(d2);
    shuffle(d2,d1);
    printf("\n再次洗牌后:\n");
    printDeck(d1);
    return 0;
}

void newDeck(Deck d)
{ 
    int s, f, x; 
    Card c; 
    //默认顺序发牌
    for (s = x = 0; s < SUITS_PER_DECK; s++) { 
        for (f = 0; f < CARDS_PER_SUIT; f++){
	    c.suit = s; 
	    c.face = f;
	    c.inDeck = true;
	    d[x++] = c;
	}
    }
}

void printDeck(const Deck d)
{
    int i;
    
    for(i = 0; i < CARDS_PER_DECK; i++) {
	if(d[i].inDeck == true) {
	    printf("%2s %s\n", FaceValueStr[ d[i].face ], SuitStr[ d[i].suit ]);
	}
    }
}

//洗牌
void shuffle(Deck d, Deck shuffled)
{ 
    int i, j, n = CARDS_PER_DECK;
    
    for(i = 0; i < CARDS_PER_DECK; i++) {
	while(d[j=Random(n)].inDeck == false);
        shuffled[i] = d[j];
        d[j].inDeck = false;
    }
    while(i >= 0) d[--i].inDeck = true;
}

/*产生随机数*/
int Random(int range) { 
    float x = ((float)rand() / (float)RAND_MAX) * range; 
    return (int)x;
}
