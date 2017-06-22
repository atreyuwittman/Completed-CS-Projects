<SCRIPT LANGUAGE="JavaScript">

var gameOver;
var cardCount;

// Returns a random number
// between 1 and the max
function randomType(max) {
    //TODO - Implement function
  randNum = 0;
  randNum = Math.floor((Math.random() * max) + 1);
  return randNum;
}

// Returns a random suit
// for the card
// spades, clubs, diamonds, hearts
function getSuit() {
    // TODO - Implement function
	// Get random value (1-4)
	// Assign a suit to each value
	// and return it as a string
	// Ex. (return "Spades";)
  randNum = 0;
  randNum = randomType(4);
  if(randNum == 1){
    return "Spades";
  }
  else if (randNum == 2){
    return "Hearts"
  }
  else if (randNum == 3){
    return "Clubs";
  }
  else{
    return "Diamonds";
  }
}

// Returns card number if 2-10
// and card names for others
// (Jack, Queen, King, Ace)
function cardName(card) {
    // TODO - Implement function
  if(card == 1){
     return "Ace";
     }
  if(card == 2){
     return "Two";
     }
  if(card == 3){
     return "Three";
     }
  if(card == 4){
     return "Four";
     }
  if(card == 5){
     return "Five";
     }
  if(card == 6){
     return "Six";
     }
  if(card == 7){
     return "Seven";
     }
  if(card == 8){
     return "Eight";
     }
  if(card == 9){
     return "Nine";
     }
  if(card == 10){
     return "Ten";
     }
  if(card == 11){
     return "Jack";
     }
  if(card == 12){
     return "Queen";
     }
  if(card == 13){
     return "King";
     }
}

// Returns numerical value of drawn card
function cardValue(card, strWho) {
    // If card is Ace, value is 1 or 11
	if (card == 1) {
        if (strWho == "Player" && document.display.player.value > 10) {
            document.display.say2.value = document.display.say2.value + " Low";
            return 1;
        } 
		else {
			return 11;
		}
    }
	
	// If card is a 10 or higher, value is 10
    if (card > 10) {
		return 10;
	}
	
	// Any other card's value is its number
    return card;
}

// Returns a random card from the deck
function pickCard(strWho) {
    // Thirteen possible value cards (Ace, 2, 3, ..., King)
	card = randomType(13);
    
	// Applies a suit (spades, clubs, diamonds, hearts)
	// to the card
	suit = getSuit();
	
    if (strWho == "Player") {
		document.display.say2.value = (cardName(card) + " of " + suit);
	}
    else {
		document.display.say1.value = (cardName(card) + " of " + suit);
	}
	
    return cardValue(card, strWho);
}

// Starts new game
function newHand(form) {
    if (gameOver != 0) {
        form.say1.value = ("Hand still in Play!");
        form.say2.value = ("Click Hit or Stand");
        return;
    } 
	
	else {
        form.dealer.value = 0;
        form.player.value = 0;
        cardCount = 0;
        form.dealer.value = eval(form.dealer.value) + pickCard("Dealer");
        form.player.value = eval(form.player.value) + pickCard("Player");
        gameOver = -1;
        cardCount += 1;
    }
}

// Dealer's turn
function dealerGo(form) {
    if (gameOver == 0) {
        form.say1.value = ("Deal the Cards!");
        form.say2.value = ("");
        return;
    } 
	else if (form.player.value < 10) {
        form.say1.value = ("Not Below Ten!");
        form.say2.value = ("Take a Hit!");
        return;
    } 
	else if (cardCount < 2) {
        form.say1.value = ("Minimum 2 Cards!");
        form.say2.value = ("Hit Again!");
        return;
    } 
	else {
		while (form.dealer.value < 17) {
			form.dealer.value = eval(form.dealer.value) + pickCard("Dealer");
		}
    }
}

// Player's turn
// Determines if player can Hit again
// Or if player busts
function userGo(form) {
    if (gameOver == 0) {
        form.say1.value = ("Deal the Cards!");
        form.say2.value = ("");
        return;
    } 
	
	else {
        cardCount += 1;
        form.say1.value = ("Player Gets");
        form.player.value = eval(form.player.value) + pickCard("Player");
    }
	
    if (form.player.value > 21) {
        form.say1.value = ("Player Busted!");
        gameOver = 0;
        form.numgames.value = eval(form.numgames.value) - 1;
    }
}

// Evaluate players' hands
// Determines winner, loser
function checkHands(form) {
    if (gameOver == 0 || form.player.value < 10 || cardCount < 2) {
        return;
    } 
	
	else if (form.dealer.value > 21) {
        form.say1.value = ("House Busts!");
        form.say2.value = ("Player Wins! $$$$$$");
        gameOver = 0;
        form.numgames.value = eval(form.numgames.value) + 1;
    } 
	
	else if (form.player.value > form.dealer.value) {
        form.say1.value = ("21!! Player Wins!!");
        form.say2.value = ("$$$$$$$$$$$$");
        gameOver = 0;
        form.numgames.value = eval(form.numgames.value) + 1;
    } 
	
	else if (form.dealer.value == form.player.value) {
        form.say1.value = ("Game Tied!");
        form.say2.value = ("Try Again!");
        gameOver = 0;
        form.numgames.value = eval(form.numgames.value) - 1;
    } 
	
	else {
        form.say1.value = ("House Wins.");
        form.say2.value = ("Tough Luck :(");
        gameOver = 0;
        form.numgames.value = eval(form.numgames.value) - 1;
    }
}

// Initialize board
function setBj() {
    gameOver = 0;
    cardCount = 0;
    document.display.dealer.value = "";
    document.display.player.value = "";
    document.display.numgames.value = "0";
    document.display.say1.value = "    Hit 'Deal'";
    document.display.say2.value = "    To Start!";
}
</script>

<body OnLoad="setBj()">
    <center>
        <form name="display">
            <table bgcolor="#c0c0c0" border="1" cellspacing="0" cellpadding="3">
                <tr>
                    <td>
                        <center>Score:</center>
                    </td>
                    <td>
                        <center>Dealer</center>
                    </td>
                    <td>
                        <center>
                            <input type=text name="dealer" size="2">
                        </center>
                    </td>
                    <td>
                        <center>Card(s):
                            <input type=text name="say1" size="18" value="">
                        </center>
                    </td>
                </tr>
                <tr>
                    <td>
                        <center>
                            <input type=text name="numgames" size="3" value="0">
                        </center>
                    </td>
                    <td>
                        <center>Player</center>
                    </td>
                    <td>
                        <center>
                            <input type=text name="player" size="2">
                        </center>
                    </td>
                    <td>
                        <center>Card(s):
                            <input type=text name="say2" size="18" value="">
                        </center>
                    </td>
                </tr>
                <tr>
                    <td>
                        <center>
                            <input type=button value="Deal" onClick="newHand(this.form)">
                        </center>
                    </td>
                    <td colspan=3>
                        <center>
                            <input type=button value="Stand" onClick="dealerGo(this.form);checkHands(this.form);">
                            <input type=button value=" Hit " onClick="userGo(this.form)">
                        </center>
                    </td>
                </tr>
            </table>
        </form>
    </center>
</body>
