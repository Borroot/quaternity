# Quaternity
Quaternity is a state validator for an imaginative variation on the game quartet.

## Game rules
Let us first define some useful variables: the size of one set, or the number of cards in one set, is denoted by _S_, the number of sets is denoted by _N_ and the number of players is denoted by _P_. Note that we start counting from zero in order to be compatible with the actual code, so if _P_ is 3 then we have player 0, 1 and 2, the same holds for sets and cards.

### Start of the game
To allow an equal distribution of the cards the following relation should hold (_N_ * _S_) mod _P_ = 0. Once this relation is satisfied every player will receive (_N_ * _S_) / _P_ cards. Note that these cards are undefined, we only know that every player has (_N_ * _S_) / _P_ cards, but we do not know which cards! Once the cards are distributed player 0 (which can be anyone) will get the first turn.

### Course of the game
On a player's turn, say player _x_ is on turn, a question can be asked by player _x_ to any other player, say player _y_. Player _x_ will ask player _y_ for a card from a certain set. Player _x_ can only ask for a card it does not possess. Additionally, player _x_ needs to possess another card from the same set as the card which it is asking for. 

Player _y_ can answer either yes or no. If player _y_ says no then player _y_ does not have the card and the turn will be handed over to player _y_. If player _y_ says yes then the card will be handed over to player _x_ and player _x_ will receive the next turn. 

Note that it can be the case that player _y_ might need to have the card, because e.g. all the other players can not have the card anymore due to previous questions and answers thus forcing player _y_ to say yes. Likewise it can be that other restrictions can lead to an invalid question or answer.

If a player has all the cards from a certain set, then these cards will be removed from this player's hand and the player will receive one point. A player has all the cards from a certain set when due to the restrictions induced by asking and answering questions all of these cards can only be in this player's hands.

There is a special situation when player _x_ receives a card from player _y_, player _x_ finishes a set with this card and player _x_ has no additional cards from other sets then player _x_'s hands are empty at the end of its turn. Player _x_ will be on turn again, but since its hands are empty there are no valid questions. So in this case instead of handing over the turn to player _x_ again the turn will go to player _y_.

If player _y_ also does not have any cards left, we choose the first player with cards from a randomly predetermined order of players. This player will have a slight advantage over the other players, but since this situation is rare it should not make a big difference. To make it as fair as possible make sure to randomize or rotate the predetermined order of players after every game. (In the implementation we choose the first player from the player list, so make sure that the mapping of players to the player list is random.)

### End of the game
The game finishes when all the sets have been completed and thus when every player has no cards in their hands. The player with the most points (completed sets) wins. If there are multiple people with the same amount of sets then everyone loses.

## Validator
The validator checks whether a given quaternity state is valid, i.e. whether it is possible given the constraints to assign all the cards to the players. This is done by performing a bipartite matching algorithm on a carefully constructed graph, iff there exists a complete matching the state is valid.

Internally only three values are needed to encode the state of the game. For every player we keep track of the number of cards the player has. For every card we keep track of which players _can_ have that card. For every player we keep track of the _minimum_ number of cards that player has from each set.

The constructed bipartite graph consists of two sets (left (_L_) and right (_R_)), each containing _S_ * _N_ elements, i.e. one for every card in the game. In the left set we encode the hands of the players. For example, if the first player has 4 cards and the second player has 2 cards, then the first 4 elements of _L_ are assigned to player one and the last 2 elements of _L_ are assigned to player two. The right set encodes all the cards. For example, the first element is card zero from set zero, the seventh element is card two from set one (if _S_ = 4), etc.

With these encodings in mind we draw connections between elements from the left set and the right set. For every player we go through all the set constraints. For each set constraint we take one element from the players' hand and draw lines from here to the cells of that set, if the card constraint allows this player to have that specific card. This makes sure that the player will minimally have a card of that set, thereby encoding the set constraint. All of the leftover spots in the hand of the player will be connected to every card that the player can have.

Performing the bipartite matching algorithm on this graph now tells us whether the state is valid or not.

## Documentation
An extensive documentation of the code can be found [here](https://borroot.github.io/quaternity/files.html).
