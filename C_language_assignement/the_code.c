#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Enumeration for card suits
typedef enum
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
} Suit;

// Structure representing a card
typedef struct Card
{
    Suit suit;
    int pips;
}Card;

// Function to shuffle the deck of cards
void shuffleDeck(Card deck[])
{
    int n = sizeof(deck) / sizeof(deck[0]);
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        // Swap cards at positions i and j
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to deal a hand from the deck
void dealHand(Card hand[], Card deck[])
{
    for (int i = 0; i < 7; i++)
    {
        hand[i] = deck[i];
    }
}

// Function to check if a hand has a pair
int hasPair(Card hand[])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 7; j++)
        {
            if (hand[i].pips == hand[j].pips)
            {
                return 1; // True, a pair is found
            }
        }
    }
    return 0; // False, no pair found
}

// Function to check if a hand has two pairs
int hasTwoPair(Card hand[])
{
    int count = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 7; j++)
        {
            if (hand[i].pips == hand[j].pips)
            {
                count++;
                if (count >= 2)
                {
                    return 1; // True, two pairs are found
                }
            }
        }
    }
    return 0; // False, less than two pairs found
}

// Function to check if a hand has three of a kind
int hasThreeKind(Card hand[])
{
    for (int i = 0; i < 5; i++)
    {
        if (hand[i].pips == hand[i + 1].pips && hand[i].pips == hand[i + 2].pips)
        {
            return 1; // True, three of a kind is found
        }
    }
    return 0; // False, no three of a kind found
}

// Function to check if a hand has a full house
int hasFullHouse(Card hand[])
{
    if (hasThreeKind(hand))
    {
        for (int i = 0; i < 4; i++)
        {
            if (hand[i].pips != hand[i + 1].pips && hand[i].pips == hand[i + 2].pips)
            {
                return 1; // True, full house is found
            }
            else if (hand[i].pips == hand[i + 1].pips && hand[i].pips != hand[i + 3].pips)
            {
                return 1; // True, full house is found
            }
        }
    }
    return 0; // False, no full house found
}

// Function to check if a hand has four of a kind
int hasFourKind(Card hand[])
{
    for (int i = 0; i < 4; i++)
    {
        if (hand[i].pips == hand[i + 1].pips && hand[i].pips == hand[i + 2].pips && hand[i].pips == hand[i + 3].pips)
        {
            return 1; // True, four of a kind is found
        }
    }
    return 0; // False, no four of a kind found
}

int main()
{
    const int numTrials = 1000000;
    int noPairCount = 0;
    int onePairCount = 0;
    int twoPairCount = 0;
    int threeKindCount = 0;
    int fullHouseCount = 0;
    int fourKindCount = 0;

    // Initialize a deck of 52 cards
    Card deck[52];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            deck[i * 13 + j].suit = i;
            deck[i * 13 + j].pips = j + 1;
        }
    }

    // Seed the random number generator with current time
    srand(time(NULL));

    // Simulate the specified number of trials
    for (int i = 0; i < numTrials; i++)
    {
        shuffleDeck(deck);
        Card hand[7];
        dealHand(hand, deck);

        // Determine the poker hand and update the respective counters
        if (!hasPair(hand))
        {
            noPairCount++;
        }
        else if (hasPair(hand) && !hasTwoPair(hand))
        {
            onePairCount++;
        }
        else if (hasTwoPair(hand) && !hasThreeKind(hand))
        {
            twoPairCount++;
        }
        else if (hasThreeKind(hand) && !hasFullHouse(hand))
        {
            threeKindCount++;
        }
        else if (hasFullHouse(hand) && !hasFourKind(hand))
        {
            fullHouseCount++;
        }
        else
        {
            fourKindCount++;
        }
    }

    // Calculate and print the probabilities
    double noPairProb = (double)noPairCount / numTrials;
    double onePairProb = (double)onePairCount / numTrials;
    double twoPairProb = (double)twoPairCount / numTrials;
    double threeKindProb = (double)threeKindCount / numTrials;
    double fullHouseProb = (double)fullHouseCount / numTrials;
    double fourKindProb = (double)fourKindCount / numTrials;

    printf("Probability of no pair: %.4lf\n", noPairProb);
    printf("Probability of one pair: %.4lf\n", onePairProb);
    printf("Probability of two pair: %.4lf\n", twoPairProb);
    printf("Probability of three of a kind: %.4lf\n", threeKindProb);
    printf("Probability of full house: %.4lf\n", fullHouseProb);
    printf("Probability of four of a kind: %.4lf\n", fourKindProb);

    return 0;
}
