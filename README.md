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

There is a special situation when player _x_ receives a card from player _y_, player _x_ finishes a set with this card and player _x_ has no additional cards from other sets then player _x_'s hands are empty at the end of its turn. Player _x_ will be on turn again, but since its hands are empty there are no valid questions. So in this case instead of handing over the turn to player _x_ again the turn will go to player _y_. If player _y_ also does not have any cards left, we choose the player with the least amount of quartets to be onturn. If there are multiple players with the least amount of quartets, we choose from these players the one with the least amount of cards left in their hands. If this also ties, we choose a random player from these players.

### End of the game
The game finishes when all the sets have been completed and thus when every player has no cards in their hands. The player with the most points (completed sets) wins. If there are multiple people with the same amount of sets then everyone loses.

## Validator

## Documentation
An extensive documentation of the code can be found [here](https://borroot.github.io/quaternity/files.html).
