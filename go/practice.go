package main

import (
	"fmt"
)

type Player struct {
	havingCardNum []int
	score int
}

func main() {
	player := Player{}
	fmt.Println(player)
	player.score += 5
	player.havingCardNum = append(player.havingCardNum, 2)
	fmt.Println(player)
}