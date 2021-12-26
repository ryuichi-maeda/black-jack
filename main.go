package main

import (
	"fmt"
	"math/rand"
)

type Card struct {
	suit string
	mark string
	value int
	isUsed bool
}

type Player struct {
	havingCardNum []int
	score int
}

type Dealer struct {
	havingCardNum []int
	score int
}

type Info struct {
	mark string
	value int
}

type cards map[int]Card
var cardInfo = map[int]Info{
	1: Info{"A", 1},
	2: Info{"2", 2},
	3: Info{"3", 3},
	4: Info{"4", 4},
	5: Info{"5", 5},
	6: Info{"6", 6},
	7: Info{"7", 7},
	8: Info{"8", 8},
	9: Info{"9", 9},
	10: Info{"10", 10},
	11: Info{"J", 10},
	12: Info{"Q", 10},
	13: Info{"K", 10},
}

func calculateCardNum(num int) int {
	var cardNum int
	if num % 13 == 0 {
		cardNum = 13
	} else {
		cardNum = num
	}
	return cardNum
}

func createCard(suit string, i int) Card {
	cardNum := calculateCardNum(i % 13)
	mark := cardInfo[cardNum].mark
	value := cardInfo[cardNum].value
	return Card{suit, mark, value, false}
} 

func initialize() cards {
	c := cards{}
	var suit string
	for i := 1; i < 53; i++ {
		switch {
			case i < 14:
				suit = "クラブ"
				c[i] = createCard(suit, i)
			case i < 27:
				suit = "ダイヤ"
				c[i] = createCard(suit, i)
			case i < 40:
				suit = "ハート"
				c[i] = createCard(suit, i)
			default:
				suit = "スペード"
				c[i] = createCard(suit, i)
		}
	}
	return c
}

func createDrawMessage(drawer, suit, mark string) string {
	var message string
	if drawer == "player" {
		message = fmt.Sprintf("あなたの引いたカードは%vの%vです。", suit, mark)
	} else {
		message = fmt.Sprintf("ディーラーの引いたカードは%vの%vです。", suit, mark)
	}
	return message
}

func draw(drawer string) int{
	var cardNum int
	for {
		cardNum = 1 + rand.Intn(52)
		if c[cardNum].isUsed == false {
			card := c[cardNum]
			card.isUsed = true
			c[cardNum] = card
			break
		}
	}
	if drawer == "player" {
		player.score += c[cardNum].value
		player.havingCardNum = append(player.havingCardNum, cardNum)
	} else {
		dealer.score += c[cardNum].value
		dealer.havingCardNum = append(dealer.havingCardNum, cardNum)
	}
	return cardNum
}

func judgeWinner() string {
	var winner string
	if player.score > 21 {
		winner = "ディーラー"
	} else if dealer.score > 21 {
		winner = "あなた"
	} else if player.score > dealer.score {
		winner = "あなた"
	} else if dealer.score > player.score {
		winner = "ディーラー"
	}
	return winner
}

var c = initialize()
var player = Player{}
var dealer = Dealer{}
 
func main() {
	var drawNum int
	var dealerSecondDrawNum int
	var winner string

	fmt.Println("ゲームを開始します。")
	drawNum = draw("player")
	fmt.Println(createDrawMessage("player", c[drawNum].suit, c[drawNum].mark))
	drawNum = draw("player")
	fmt.Println(createDrawMessage("player", c[drawNum].suit, c[drawNum].mark))
	drawNum = draw("dealer")
	fmt.Println(createDrawMessage("dealer", c[drawNum].suit, c[drawNum].mark))
	dealerSecondDrawNum = draw("dealer")
	fmt.Println("ディーラーの2枚目のカードは分かりません。")
	fmt.Println(dealerSecondDrawNum)

	fmt.Printf("あなたの現在の得点は%vです。\n", player.score)

	for {
		var answer string

		fmt.Println("カードを引きますか？引く場合はYを、引かない場合はNを入力してください。")
		fmt.Scan(&answer)
		if answer == "Y" {
			drawNum = draw("player")
			fmt.Println(createDrawMessage("player", c[drawNum].suit, c[drawNum].mark))
			fmt.Printf("あなたの現在の得点は%vです。\n", player.score)
			if player.score > 21 {
				break
			}
		} else if answer == "N" {
			fmt.Printf("ディーラーの2枚目のカードは%vの%vでした。\n", c[dealerSecondDrawNum].suit, c[dealerSecondDrawNum].mark)
			fmt.Printf("ディーラーの現在の得点は%vです。\n", dealer.score)
			for dealer.score < 17 {
				drawNum = draw("dealer")
				fmt.Println(createDrawMessage("dealer", c[drawNum].suit, c[drawNum].mark))
				if dealer.score > 21 {
					break
				} else {
					fmt.Printf("ディーラーの現在の得点は%vです。\n", dealer.score)
				}
			}
		} else {
			continue
		}
		break
	}

	fmt.Printf("あなたの得点は%vです。\n", player.score)
	fmt.Printf("ディーラーの得点は%vです。\n", dealer.score)

	winner = judgeWinner()
	if winner != "" {
		fmt.Printf("%vの勝ちです\n", winner)
	} else {
		fmt.Println("引き分けです。")
	}
	fmt.Println("ブラックジャック終了!")
}